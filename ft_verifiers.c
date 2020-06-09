/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:42:42 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 23:44:40 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int64_t	strlenint(const char *fmt)
{
	int64_t	i;

	i = 0;
	if (*fmt >= '0' && *fmt <= '9')
	{
		while (*fmt >= '0' && *fmt <= '9')
		{
			i++;
			fmt++;
		}
	}
	else
		i = 1;
	return (i);
}

int	isflag(char c)
{
	int	res;

	res = 0;
	if (c == '0' || c == '-' || c == '.' || c== '*')
		res = 1;
	return (res);
}

int	isspec(char c)
{
	int	res;

	res = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		res = 1;
	return (res);
}
