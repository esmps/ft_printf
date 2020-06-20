/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:27:44 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/16 22:28:14 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static char	*ft_printstring(char *print, char *spec, t_print printint)
{
	char	*printstring;
	int		x;
	int		y;

	x = 0;
	y = 0;
	printstring = ft_strnew((size_t)printint.len);
	while (x < printint.templen)
	{
		printstring[x] = print[x];
		x++;
	}
	while (x < printint.len)
	{
		printstring[x] = spec[y++];
		x++;
	}
	return (printstring);
}

static char	*process_non_fmt(const char *fmt, int i,
	char *print, t_print *printint)
{
	char	*tmp_print;
	char	*substr_toadd;

	if (fmt[i + 1] == '\0')
	{
		substr_toadd = ft_substr(fmt, printint->last_pos,
			i - printint->last_pos + 1);
		printint->len++;
		tmp_print = ft_printstring(print, substr_toadd, *printint);
		free(print);
		free(substr_toadd);
		print = tmp_print;
	}
	else
	{
		substr_toadd = ft_substr(fmt, printint->last_pos,
			i - printint->last_pos);
		printint->templen = printint->len - ft_strlen(substr_toadd);
		tmp_print = ft_printstring(print, substr_toadd, *printint);
		printint->templen = printint->len;
		free(substr_toadd);
		free(print);
		print = tmp_print;
	}
	return (print);
}

static char	*process_spec_fmt(const char fmt, char *print,
	va_list ap, t_fmt *format)
{
	char	*tmp_print;
	char	*spec_print;

	spec_print = readspec(fmt, ap, format);
	tmp_print = ft_printstring(print, spec_print, format->print);
	free(spec_print);
	free(print);
	print = tmp_print;
	format->print.templen = format->print.len;
	return (print);
}

static char	*process_flag_spec(char *print, int *i, va_list ap, t_fmt *format)
{
	const char	*fmt;

	fmt = format->fmt;
	if (fmt[*i + 1] == '\0')
		print = process_non_fmt(fmt, *i, print, &format->print);
	else if (fmt[*i] == '%')
	{
		initflags(&format->flags);
		if (isspec(fmt[*i + 1]) == 1 || isflag(fmt[*i + 1]) == 1
			|| (fmt[*i + 1] >= '1' && fmt[*i + 1] <= '9'))
		{
			print = process_non_fmt(fmt, *i, print, &format->print);
			(*i)++;
			while (isflag(fmt[*i]) || (fmt[*i] >= '1' && fmt[*i] <= '9'))
				*i += set_flag(ap, &fmt[*i], format);
			if (isspec(fmt[*i]))
				print = process_spec_fmt(fmt[*i], print, ap, format);
		}
		format->print.last_pos = *i + 1;
	}
	return (print);
}

int			process(va_list ap, const char *fmt)
{
	char	*print;
	int		i;
	t_fmt	format;

	i = 0;
	print = ft_strnew(0);
	ft_memset((&(format.print)), 0, sizeof(format.print));
	format.fmt = fmt;
	while (fmt[i])
	{
		if (fmt[i] == '%' || fmt[i + 1] == '\0')
		{
			print = process_flag_spec(print, &i, ap, &format);
			i++;
		}
		else
		{
			format.print.len++;
			i++;
		}
	}
	write(1, print, format.print.len);
	free(print);
	return (format.print.len);
}
