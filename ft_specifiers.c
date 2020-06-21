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

char	*intspecifiers(char c, int64_t integer, t_fmt format, t_print *printint)
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
		printint->len += format.flags.width > 1 ? format.flags.width : 1;
	else
		printint->len += (int64_t)ft_strlen(print);
	return (print);
}

char	*charspecifiers(char *string, t_fmt format, t_print *printint)
{
	char	*print;

	print = ft_args(string, format);
	printint->len += ft_strlen(print);
	return (print);
}

char	*readspec(const char fmt, va_list ap, t_fmt *format)
{
	char	*print;
	char	*strarg;
	int64_t	arg;

	if (fmt == 's')
	{
		strarg = va_arg(ap, void *);
		print = charspecifiers(strarg, *format, &format->print);
	}
	else
	{
		if (fmt == '%')
			arg = 0;
		else if (fmt == 'u' || fmt == 'x' || fmt == 'X')
			arg = (int64_t)va_arg(ap, uint32_t);
		else
			arg = (int64_t)va_arg(ap, int64_t);
		print = intspecifiers(fmt, arg, *format, &format->print);
	}
	return (print);
}
