/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 01:19:44 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/18 01:19:48 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(uint64_t num)
{
	int		i;

	i = 1;
	while (num /= 16)
		i++;
	return (i);
}

static char		*ft_rev(char *s, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
		len--;
	}
	return (s);
}

char			*ft_calcnum(uint64_t num, int letter, char *str)
{
	int		rem;
	int		i;

	i = 0;
	rem = 0;
	while (num != 0)
	{
		rem = num % 16;
		if (letter == 0)
			str[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		else
			str[i] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_hex(uint64_t num, int letter)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(int_len(num))))
		return (NULL);
	if (num == 0)
	{
		str[i] = '0';
		i++;
		str[i] = '\0';
		return (str);
	}
	if (num > 0)
		str = ft_calcnum(num, letter, str);
	ft_rev(str, ft_strlen(str) - 1);
	return (str);
}
