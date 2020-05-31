/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:13 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/09 15:23:43 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = ft_strlen(s);
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		else
			i--;
	}
	return (NULL);
}
