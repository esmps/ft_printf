/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:54:00 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/10 22:12:38 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	templen;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		j = 0;
		templen = len - i;
		while (templen > 0 && haystack[i + j] \
				!= '\0' && haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
			templen--;
		}
		i++;
	}
	return (NULL);
}
