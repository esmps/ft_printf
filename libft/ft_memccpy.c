/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:16:24 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/20 19:19:28 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int					i;
	unsigned char		ch;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	ch = (unsigned char)c;
	while (s[i] != ch && n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	if (s[i] == ch)
	{
		d[i] = s[i];
		return (d + i + 1);
	}
	else
		return (NULL);
}
