/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:02:45 by epines-s          #+#    #+#             */
/*   Updated: 2020/05/29 21:42:52 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int64_t num)
{
	int	i;

	i = 1;
	if (num < 0)
	i++;
	while (num /= 10)
		i++;
	return (i);
}

static int64_t		pow(int n, int64_t p)
{
	int64_t	res;

	res = 1;
	if (p < 0)
		return (0);
	while (p)
	{
		res = res * n;
		p--;
	}
	return (res);
}

char			*ft_itoa(int64_t n)
{
	size_t	len;
	int64_t	x;
	char	*s;
	char	*res;

	len = int_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	res = s;
	if (!s)
		return (NULL);
	ft_memset(s, '0', (sizeof(char) * (len + 1)));
	s[len] = '\0';
	x = pow(10, len - 1);
	if (n == 0)
		s++;
	if (n < 0)
		*s++ = '-';
	while (n)
	{
		*s++ = ft_abs(n / x) + '0';
		n = n % x;
		x = x / 10;
	}
	return (res);
}
