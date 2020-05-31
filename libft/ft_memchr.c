/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:27:44 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/09 14:36:42 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	unsigned char		ch;
	unsigned const char	*str;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned const char *)s;
	while (n > 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		else
		{
			i++;
			n--;
		}
	}
	return (NULL);
}
