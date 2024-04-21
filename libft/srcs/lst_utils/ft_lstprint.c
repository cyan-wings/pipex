/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:03:02 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:49:11 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "libft.h"
#include "ft_error.h"

void	ft_lstprint(t_list *lst, char sep)
{
	if (!lst)
		ft_error(NULL_ERROR);
	while (lst)
	{
		ft_putnbr_fd(*((int *) lst->content), 1);
		ft_putchar_fd(sep, 1);
		lst = lst->next;
	}
}
