/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:51:00 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:46:19 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"

int	ft_error(t_error e)
{
	if (e == OK)
		return (OK);
	ft_putstr_fd("Error: ", 2);
	ft_putnbr_fd(e, 2);
	ft_putchar_fd('\n', 2);
	return (e);
}
