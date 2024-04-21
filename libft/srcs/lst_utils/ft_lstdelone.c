/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:26:12 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:47:33 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lst.h"

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
