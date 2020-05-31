/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:36:13 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/23 19:23:19 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		x;
	int		i;

	i = 0;
	x = 1;
	if (s[i] != c && s[i] != '\0')
		x++;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
				x++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (x);
}

static int	count_word_len(char const *s, char c)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i + 1);
}

static char	*ft_new(int size)
{
	char	*word;

	if (!(word = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(word, size);
	return (word);
}

static char	*make_array(char **arr, char const *s, int i, char c)
{
	int	j;

	j = 0;
	if (!(arr[i] = ft_new(count_word_len(s, c))))
		return (NULL);
	while (*s != c && *s != '\0')
	{
		arr[i][j] = *s;
		j++;
		s++;
	}
	return (arr[i]);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	words = count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * words)))
		return (NULL);
	while (i < words - 1)
	{
		while (s[k] == c)
			k++;
		arr[i] = make_array(arr, &s[k], i, c);
		while (s[k] != c && s[k] != '\0')
			k++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
