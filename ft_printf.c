/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:49:55 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 01:35:21 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static	char *process_non_fmt(const char *fmt, int i, char *print, t_print *printint)
{
	char	*temp;

	if (fmt[i + 1] == '\0')
	{
		temp = ft_substr(fmt, printint->last_pos, i - printint->last_pos + 1);
		printint->len++;
		temp = ft_printstring(print, temp, *printint);
		free(print);
		print = temp;
	}
	else
	{
		temp = ft_substr(fmt, printint->last_pos, i - printint->last_pos);
		printint->templen = printint->len - ft_strlen(temp);
		temp = ft_printstring(print, temp, *printint);
		printint->templen = printint->len;
		free (print);
		print = temp;
	}
	return (print);
}

static int	process(va_list ap, const char *fmt)
{
	char	*print;
	char	*temp;
	int		i;
	t_fmt	format;
	t_print	printint;

	i = 0;
	ft_memset(&printint, 0, sizeof(printint));
	print = ft_strnew(0);
	while (fmt && fmt[i])
	{	
		if (fmt[i] == '%' || fmt[i + 1] == '\0')
		{	
			if (fmt[i + 1] == '\0')
				print = process_non_fmt(fmt, i, print, &printint);
			else if (fmt[i] == '%')
			{
				initflags(&(format.flags));
				if (isspec(fmt[i + 1]) == 1 || isflag(fmt[i + 1]) == 1 || (fmt[i + 1] >= '1' && fmt[i + 1] <= '9'))
				{
					print = process_non_fmt(fmt, i, print, &printint);	
					i++;
					while (isflag(fmt[i]) || (fmt[i] >= '1' && fmt[i] <= '9'))
						i += set_flag(ap, &fmt[i], &format);
					if (isspec(fmt[i]))
					{
						temp = readspec(fmt[i], ap, format, &printint);
						temp = ft_printstring(print, temp, printint);
						free (print);
						print = temp;
						printint.templen = printint.len;
					}
				}
				printint.last_pos = i + 1;
			}
			i++;
		}
		else
		{
			i++;
			printint.len++;
		}
	}
	write(1, print, printint.len);
	return(printint.len);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int64_t	printlen;

	va_start(ap, fmt);
	printlen = process(ap, fmt);
	va_end(ap);
	return (printlen);
}
