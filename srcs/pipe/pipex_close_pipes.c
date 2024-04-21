/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:56:35 by myeow             #+#    #+#             */
/*   Updated: 2024/04/21 02:38:43 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_close_pipes(int p_count, int *p_array)
{
	int	i;

	i = -1;
	while (++i < p_count)
		close(p_array[i]);
}
