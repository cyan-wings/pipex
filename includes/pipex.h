/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:34:24 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 00:33:18 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		heredoc_flag;
	char	**path_dirs;
	int		cmd_count;
	int		p_count;
	int		*p_array;
}	t_pipex;

void	pipex_clean(t_pipex *vars);
void	pipex_error(char *err_msg, char *file_name, t_pipex *vars,
			int exit_status);
int		pipex_heredoc(int argc, char **argv);
char	**pipex_path(char **envp);

void	pipex_pipe(t_pipex *vars, int argc, char **argv, char **envp);
void	pipex_execute_error(char **prog_args, char *cmd_str, t_pipex *vars);
void	pipex_close_pipes(int p_count, int *p_array);

#endif
