/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:43:41 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 19:41:12 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

static void	pipex_free(t_pipex *vars)
{
	ft_free_ft_split(vars->path_dirs);
	if (vars->fd_array)
	{
		free(vars->fd_array);
		vars->fd_array = 0;
	}
}

void	pipex_clean(t_pipex *vars)
{
	if (vars->heredoc_flag)
		unlink(".heredoc_temp");
	if (vars->in_fd != -1)
		close(vars->in_fd);
	if (vars->out_fd != -1)
		close(vars->out_fd);
	pipex_free(vars);
}
