/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:25:52 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/09 18:37:42 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}
