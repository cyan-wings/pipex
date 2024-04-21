/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:46:23 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 01:07:36 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex_pipe_create(t_pipex *vars)
{
	int	i;

	i = -1;
	while (++i < vars->cmd_count - 1)
	{
		if (pipe(vars->p_array + (i * 2)) == -1)
			pipex_error("Pipe Creation Failed.", 0, vars, 1);
	}
}

static void	pipex_dup_fd(int i, t_pipex *vars)
{
	if (!i)
	{
		dup2(vars->in_fd, STDIN_FILENO);
		dup2(vars->p_array[1], STDOUT_FILENO);
		return ;
	}
	dup2(vars->p_array[(i - 1) * 2], STDIN_FILENO);
	if (i == vars->cmd_count - 1)
		dup2(vars->out_fd, STDOUT_FILENO);
	else
		dup2(vars->p_array[i * 2 + 1], STDOUT_FILENO);
	return ;
}

/*
 * prog_exec: Program executable.
 */
static char	*pipex_get_prog(char **path_dirs, char *prog_name, int *flag)
{
	char	*prog_exec;
	char	*path;

	if (!access(prog_name, F_OK))
		return (prog_name);
	while (*path_dirs)
	{
		path = ft_strjoin(*path_dirs, "/");
		prog_exec = ft_strjoin(path, prog_name);
		free(path);
		path = 0;
		if (!access(prog_exec, F_OK | X_OK))
		{
			*flag = 1;
			return (prog_exec);
		}
		free(prog_exec);
		prog_exec = 0;
		++path_dirs;
	}
	return (0);
}

/*
 * @param prog_args: Arguments that consist the command itself.
 * 		Ex: "ls" "-l"
 *
 * @param prog_path: The path to the program.
 * 		Ex: "bin/ls"
 *
 * @param flag: TRUE if prog_path is required for free when exec error.
 *
 */
static void	pipex_execute(char *cmd_str, char **envp, int i, t_pipex *vars)
{
	int		flag;
	pid_t	pid;
	char	**prog_args;
	char	*prog_path;

	flag = 0;
	pid = fork();
	if (!pid)
	{
		pipex_dup_fd(i, vars);
		pipex_close_pipes(vars->p_count, vars->p_array);
		prog_args = ft_split(cmd_str, ' ');
		prog_path = pipex_get_prog(vars->path_dirs, prog_args[0], &flag);
		pipex_close_pipes(vars->p_count, vars->p_array);
		if (execve(prog_path, prog_args, envp) == -1)
		{
			if (flag)
			{
				free(prog_path);
				prog_path = 0;
			}
			pipex_execute_error(prog_args, cmd_str, vars);
		}
	}
}

void	pipex_pipe(t_pipex *vars, int argc, char **argv, char **envp)
{
	int	i;

	vars->cmd_count = argc - (3 + vars->heredoc_flag);
	vars->p_count = (vars->cmd_count - 1) * 2;
	vars->p_array = (int *) ft_calloc(vars->p_count, sizeof(int));
	if (!vars->p_array)
		return (pipex_error("Malloc Pipe Array Failed.", 0, vars, 1));
	pipex_pipe_create(vars);
	i = -1;
	if (vars->in_fd == -1 && vars->heredoc_flag == 0)
		++i;
	while (++i < vars->cmd_count)
		pipex_execute(argv[i + 2 + vars->heredoc_flag], envp, i, vars);
	pipex_close_pipes(vars->p_count, vars->p_array);
}
