/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:26:11 by myeow             #+#    #+#             */
/*   Updated: 2024/04/21 16:51:57 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

/*
 * @param file_name: optional argument
 */
void	pipex_error(char *err_msg, char *file_name, t_pipex *vars,
		int exit_status)
{
	if (vars)
		pipex_clean(vars);
	ft_putstr_fd(err_msg, 2);
	if (file_name)
		ft_putstr_fd(file_name, 2);
	ft_putchar_fd('\n', 2);
	exit(exit_status);
}
