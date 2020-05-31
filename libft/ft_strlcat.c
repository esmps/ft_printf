/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:29:33 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/10 22:11:35 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	dlen;
	int	slen;
	int	i;
	int	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dstsize;
	j = 0;
	if (dlen >= i)
		return (dstsize + (size_t)(slen));
	while ((i - dlen - 1 > j) && src[j])
	{
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = '\0';
	return ((size_t)(dlen + slen));
}
