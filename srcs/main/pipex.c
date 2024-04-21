/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:01:44 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 00:44:19 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

static void	init_pipex_check_error(t_pipex *vars, int argc, char **argv)
{
	if (vars->in_fd == -1)
	{
		ft_putstr_fd("No such file or directory: ", 2);
		ft_putendl_fd(argv[1], 2);
	}
	if (vars->out_fd == -1)
		return (pipex_error("Outfile Error: ", argv[argc - 1], vars, 1));
	if (!vars->path_dirs)
		return (pipex_error("Path Error.", 0, vars, 1));
}

static void	init_pipex(t_pipex *vars, int argc, char **argv, char **envp)
{
	char	*in_file;
	char	*out_file;

	in_file = argv[1];
	out_file = argv[argc - 1];
	if (argc < 5)
		pipex_error("Parse Error: < 5 arguments", 0, 0, 0);
	ft_bzero(vars, sizeof(t_pipex));
	if (!ft_strcmp("here_doc", in_file))
	{
		if (argc < 6)
			pipex_error("Parse Error: here_doc < 6 arguments", 0, 0, 0);
		vars->heredoc_flag = 1;
		vars->in_fd = pipex_heredoc(argc, argv);
		vars->out_fd = open(out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		vars->in_fd = open(in_file, O_RDONLY);
		vars->out_fd = open(out_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	vars->path_dirs = pipex_path(envp);
	init_pipex_check_error(vars, argc, argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	vars;

	init_pipex(&vars, argc, argv, envp);
	pipex_pipe(&vars, argc, argv, envp);
	while (1)
	{
		waitpid(-1, NULL, 0);
		if (waitpid(-1, NULL, WNOHANG) == -1)
			break ;
	}
	pipex_clean(&vars);
	return (0);
}
