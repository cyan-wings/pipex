/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:30:58 by myeow             #+#    #+#             */
/*   Updated: 2024/03/28 19:36:06 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (n--)
		{
			if (*s1 != *s2++)
				return (*(unsigned char *)s1 - *(unsigned char *)--s2);
			if (!(*s1++))
				break ;
		}
	}
	return (0);
}
