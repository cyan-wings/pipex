/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:55:00 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:49:39 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstrotate(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = temp;
	*lst = temp->next;
	temp->next = 0;
}
