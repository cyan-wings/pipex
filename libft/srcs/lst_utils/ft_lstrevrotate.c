/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:03:09 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:49:29 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstrevrotate(t_list **lst)
{
	t_list	*temp;
	int		i;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	i = 0;
	temp = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		++i;
	}
	(*lst)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		--i;
	}
	temp->next = 0;
}
