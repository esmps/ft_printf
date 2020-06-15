/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 23:35:26 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/14 23:36:50 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*intspecifiers(char c, int64_t integer, t_fmt format, int64_t *printlen)
{
	char	*print;

	if (c == 'c')
		print = ft_argc(integer, format);
	if (c == '%')
		print = ft_argpercent(format);
	if (c == 'd' || c == 'i')
		print = ft_argdi(integer, format);
	if (c == 'u')
		print = ft_argu((uint64_t)integer, format);
	if (c == 'p')
		print = ft_argp(integer, format);
	if (c == 'x')
		print = ft_argx(integer, format);
	if (c == 'X')
		print = ft_argxcap(integer, format);
	if (c == 'c' || c == '%')
		*printlen += format.flags.width > 1 ? format.flags.width : 1;	
	else
		*printlen += (int64_t)ft_strlen(print);
	return (print);
}

char	*charspecifiers(char *string, t_fmt format, int64_t *printlen)
{
	char	*print;

	print = ft_args(string, format);
	*printlen += ft_strlen(print);
	return (print);
}


char	*readspec(const char fmt, va_list ap, t_fmt format, int64_t *printlen)
{
	char	*temp;
	char	*strarg;
	int64_t	arg;

	if (fmt == 's')
	{
		strarg = va_arg(ap, void *);
		temp = charspecifiers(strarg, format, printlen);
	}
	else
	{
		if (fmt == '%')
			arg = 0;
		else if (fmt == 'u')
			arg = va_arg(ap, uint64_t);
		else
			arg = va_arg(ap, int64_t);
		temp = intspecifiers(fmt, arg, format, printlen);
	}
	return (temp);
}

