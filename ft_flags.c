/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:36:55 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 22:04:48 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

t_flags	*initflags(t_flags *subspec)
{
	subspec->zero = 0;
	subspec->leftal = 0;
	subspec->precision = -1;
	subspec->width = 0;
	return (subspec);
}

t_flags	*assignflags(const char *fmt, int64_t arg, t_flags *subspec)
{
	int64_t	res;
	int64_t	 x;
	int64_t	i;
	char	*str;

	x = 0;
	i = 0;
	res = 0;
	if (*fmt == '0')
		subspec->zero = 1;
	else if (*fmt == '-')
		subspec->leftal = 1;
	else if (*fmt == '*')
		subspec->width = (int64_t)ft_abs(arg);
	else if (*fmt >= '1' && *fmt <= '9')
	{
		str = ft_strnew(strlenint(fmt));
		while (*fmt >= '0' && *fmt <= '9')
		{
			str[i] = *fmt;
			fmt++;
			i++;
		}
		res = ft_atoi(str);
		subspec->width = res;
	}
	else if (*fmt == '.')
	{
		fmt++;
		if (*fmt == '*')
			subspec->precision = (int64_t)ft_abs(arg);
		else if (*fmt >= '0' && *fmt <= '9')
		{
			str = ft_strnew(strlenint(fmt));
			while (*fmt >= '0' && *fmt <= '9')
			{
				str[i] = *fmt;
				fmt++;
				i++;
			}
			 res = ft_atoi(str);
			subspec->precision = res;
		}
		else
			subspec->precision = 0;
	}
	return (subspec);
}
