/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:07:50 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 00:45:50 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_execute_error(char **prog_args, char *arg, t_pipex *vars)
{
	int	flag;
	int	i;

	flag = 0;
	i = -1;
	while (prog_args[++i])
	{
		if (ft_strchr(*prog_args, '/') && access(*prog_args, F_OK))
		{
			flag = 1;
			break ;
		}
	}
	ft_free_ft_split(prog_args);
	if (!flag)
		pipex_error("Program command not found: ", arg, vars, 128);
	else
		pipex_error("No such file or directory: ", arg, vars, 128);
}
