/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:31:32 by myeow             #+#    #+#             */
/*   Updated: 2024/04/10 19:57:30 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;
	size_t	s1len;

	s1len = ft_strlen(s1);
	ptr = malloc(s1len + 1);
	if (!ptr)
		return (0);
	return ((char *) ft_memmove(ptr, s1, s1len + 1));
}
