/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:12:45 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/06 23:27:10 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(uint64_t num)
{
	int			i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

char			*ft_itoa_unsigned(uint64_t n)
{
	size_t		len;
	uint64_t	x;
	char		*s;
	char		*res;

	len = int_len(n);
	s = ft_strnew(int_len(n));
	res = s;
	if (!s)
		return (NULL);
	ft_memset(s, '0', (sizeof(char) * (len + 1)));
	s[len] = '\0';
	x = ft_pow(10, len - 1);
	if (n == 0)
		s++;
	while (n)
	{
		*s++ = n / x + '0';
		n = n % x;
		x = x / 10;
	}
	return (res);
}
