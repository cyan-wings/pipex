/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:35:58 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:48:33 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int	ft_lstmin(t_list *lst)
{
	int	*i;

	i = (int *) lst->content;
	while (lst)
	{
		if (*((int *)lst->content) < *i)
			i = lst->content;
		lst = lst->next;
	}
	return (*i);
}
