/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:29:28 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/10 22:17:32 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (!d && !s)
		return (NULL);
	if (s >= d)
		ft_memcpy(d, s, len);
	else if (s < d)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (d);
}
