/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:06:58 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:49:55 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstswap(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}
