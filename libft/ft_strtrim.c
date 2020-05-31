/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:30:24 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/10 22:13:14 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (s1 && set)
	{
		end = ft_strlen(s1) - 1;
		while (is_set(s1[start], set) && s1[start] != '\0')
			start++;
		if (s1[start] == '\0')
		{
			result = ft_calloc(0, 0);
			return (result);
		}
		while (is_set(s1[end], set) && end >= start)
			end--;
		result = ft_substr(s1, start, end - start + 1);
		if (!result)
			return (NULL);
		return (result);
	}
	return (NULL);
}
