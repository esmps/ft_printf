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

t_flags			*initflags(t_flags *subspec)
{
	subspec->zero = 0;
	subspec->leftal = 0;
	subspec->precision = -1;
	subspec->width = 0;
	return (subspec);
}

static int64_t	int_to_string(const char *fmt)
{
	int			i;
	int64_t		res;
	char		*str;

	i = 0;
	res = 0;
	str = ft_strnew(strlenint(fmt));
	while (*fmt >= '0' && *fmt <= '9')
		str[i++] = *fmt++;
	res = ft_atoi(str);
	free(str);
	return (res);
}

static t_flags	*precision(const char *fmt, int64_t arg, t_flags *subspec)
{
	if (*fmt == '*')
	{
		if (arg >= 0)
			subspec->precision = arg;
		else
			subspec->precision = -1;
	}
	else if (*fmt >= '0' && *fmt <= '9')
		subspec->precision = int_to_string(fmt);
	else
		subspec->precision = 0;
	return (subspec);
}

static t_flags	*assignflags(const char *fmt, int64_t arg, t_flags *subspec)
{
	if (*fmt == '0')
		subspec->zero = 1;
	else if (*fmt == '-')
		subspec->leftal = 1;
	else if (*fmt == '*')
	{
		if (arg < 0)
			subspec->leftal = 1;
		subspec->width = (int64_t)ft_abs(arg);
	}
	else if (*fmt >= '1' && *fmt <= '9')
		subspec->width = int_to_string(fmt);
	else if (*fmt == '.')
	{
		fmt++;
		precision(fmt, arg, subspec);
	}
	return (subspec);
}

int				set_flag(va_list ap, const char *fmt, t_fmt *format)
{
	int			arg;
	int			i;

	i = 0;
	arg = 0;
	if ((fmt[i] == '.' && fmt[i + 1] == '*') || (fmt[i] == '*'))
		arg = va_arg(ap, int);
	assignflags(&fmt[i], arg, &(format->flags));
	if (fmt[i] == '.' && fmt[i + 1] >= '0' && fmt[i + 1] <= '9')
	{
		i++;
		i = i + (strlenint(&fmt[i]));
	}
	else if (fmt[i] == '.' && fmt[i + 1] == '*')
		i += 2;
	else if (fmt[i] == '0')
		i++;
	else
		i = i + (strlenint(&fmt[i]));
	return (i);
}
