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

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*print;
	char	*temp;
	int		last_pos;
	int		i;
	int		j;
	int64_t	printlen;
	t_fmt	format;

	i = 0;
	j = 0;
	last_pos = 0;
	printlen = 0;
	va_start(ap, fmt);
	print = ft_strnew(0);
	while (fmt && fmt[i])
	{	
		if (fmt[i] == '%' || fmt[i + 1] == '\0')
		{	
			if (fmt[i + 1] == '\0')
			{	
				temp = ft_substr(fmt, last_pos, i - last_pos + 1);
				printlen++;
				temp = ft_printstring(print, temp, printlen, j);
				free(print);
				print = temp;
				i++;
			}
			else if (fmt[i] == '%')
			{
				initflags(&(format.flags));
				if (isspec(fmt[i + 1]) == 1 || isflag(fmt[i + 1]) == 1 || (fmt[i + 1] >= '1' && fmt[i + 1] <= '9'))
				{
					temp = ft_substr(fmt, last_pos, i - last_pos);
					j = printlen - ft_strlen(temp);
					temp = ft_printstring(print, temp, printlen, j);
					j = printlen;
					free (print);
					print = temp;
					i++;
					while (isflag(fmt[i]) || (fmt[i] >= '1' && fmt[i] <= '9'))
						i += set_flag(ap, &fmt[i], &format);
					if (isspec(fmt[i]))
					{
						
						temp = readspec(fmt[i], ap, format, &printlen);
						temp = ft_printstring(print, temp, printlen, j);
						free (print);
						print = temp;
						j = printlen;
					}
				}
				i++;
				last_pos = i;
			}
		}
		else
		{
			i++;
			printlen++;
		}
	}
	va_end(ap);
	write(1, print, printlen);
	return (printlen);
}
