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


//char	*ft_readspec(const char *fmt, va_list ap, t_fmt format)


int	ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	char		*print;
	char		*temp;
	char		*spec;
	char		*temparg;
	int64_t		intarg;
	int		arg;
	int		last_pos;
	int		i;
	t_fmt		format;

	i = 0;
	last_pos = -1;
	//USE AP TO USE VA ARG IN ANOTHER FUNCTION WHAT A REVELATION!!!!
	va_start(ap, fmt);
	print = ft_strnew(0);
	while (fmt && fmt[i])
	{	
		if (fmt[i] == '%' || fmt[i + 1] == '\0')
		{	
			
			if (fmt[i + 1] == '\0')
			{	
				// put the following into a new function and include the one after the % specifier make sure you note the difference between last_pos -/+ 1
				temp = ft_substr(fmt, last_pos + 1, i - last_pos + 1);
				temp = ft_strjoin(print, temp);
				free(print);
				print = temp;
				i++;
			}
			//put this into a whole new function && make it smaller
			else if (fmt[i] == '%')
			{
				initflags(&(format.flags));
				if (isspec(fmt[i + 1]) == 1 || isflag(fmt[i + 1]) == 1 || (fmt[i + 1] >= '1' && fmt[i + 1] <= '9'))
				{
					temp = ft_substr(fmt, last_pos + 1, i - last_pos - 1);
					temp = ft_strjoin(print, temp);
					free (print);
					print = temp;
					i++;
					while (isflag(fmt[i]) || (fmt[i] >= '1' && fmt[i] <= '9'))
					{
						arg = 0;
						if ((fmt[i] == '.' && fmt[i + 1] == '*') || (fmt[i] == '*'))
							arg = va_arg(ap, int);
						assignflags(&fmt[i], arg, &(format.flags));
						i++;
						while (fmt[i] >= '0' && fmt[i] <= '9' && fmt[i - 1] == '.')
							i++;
					}


					if (isspec(fmt[i]))
					{
						// combine these if/else statments and make one specifiers function that will take specarg and use else if statements for characters and what type of arg they take aka compress the lines below
						if (fmt[i] == 's')
						{
							temparg = va_arg(ap, void *);
							spec = charspecifiers(temparg, format);
						}
						else
						{
							if (fmt[i] == '%')
								intarg = 0;
							else if (fmt[i] == 'u')
								intarg = va_arg(ap, uint64_t);
							else
								intarg = va_arg(ap, int64_t);
							spec = intspecifiers(fmt[i], intarg, format);
						}
						temp = ft_strjoin(print, spec);
						free (print);
						print = temp;
					}
					last_pos = i;
				}
				i++;
			}
		}
		else
			i++;
	}
	va_end(ap);
	ft_putstr_fd(print, 1);
	return (ft_strlen(print));
}
