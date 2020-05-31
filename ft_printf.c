/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:49:55 by epines-s          #+#    #+#             */
/*   Updated: 2020/05/30 20:16:59 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

t_flags	*initflags(t_flags *subspec)
{
	subspec->zero = 0;
	subspec->leftal = 0;
	subspec->precision = 0;
	subspec->width = 0;
	return (subspec);
}

int64_t	strlenint(const char *fmt)
{
	int64_t	i;

	i = 0;
	while (*fmt >= '1' && *fmt <= '9')
	{
		i++;
		fmt++;
	}
	return (i);
}

t_flags	*assignflags(const char *fmt, int64_t arg, t_flags *subspec)
{
	int	res;
	int	 x;
	int 	i;
	char	*str;

	x = 0;
	i = 0;
	res = 0;
	if (*fmt == '0')
		subspec->zero = 1;
	if (*fmt == '-')
		subspec->leftal = 1;
	if (*fmt == '.')
	{
		if (*fmt == '*')
			subspec->precision = arg;
		if (*fmt >= '1' && *fmt <= '9')
		{
			str = NULL;
			while (*fmt >= '1' && *fmt <= '9')
			{
				str[i] = *fmt;
				fmt++;
				i++;
			}
			res = ft_atoi(str);
			subspec->precision = res;
		}
		fmt++;
	}
	if (*fmt == '*')
		subspec->width = arg;
	if (*fmt >= '1' && *fmt <= '9')
	{
		str = (char *)malloc(sizeof(char) * strlenint(fmt) + 1);
		while (*fmt >= '1' && *fmt <= '9')
		{
			str[i] = *fmt;
			fmt++;
			i++;
		}
		res = ft_atoi(str);
		subspec->width = res;
	}
	return (subspec);
}

char	*width(char *string, t_fmt format)
{
	int	i;
	int	j;
	int64_t	strlen;
	char	*print;

	i = 0;
	j = 0;
	print = (char *)malloc(sizeof(char) * (format.flags.width + 1));
	memset(print, ' ', (format.flags.width));
	if ((format.flags.precision) > 0)
		strlen = (format.flags.precision);
	else 
		strlen = (int64_t)ft_strlen(string);
	if (strlen < (format.flags.width) && ((format.flags.leftal) == 0))
		j = ((format.flags.width) - strlen);
	while (i < strlen)
		print[j++] = string[i++];
	print[(format.flags.width)] = '\0';
	return (print);
}

char	*ft_argc(int64_t character, t_fmt format)
{
	char	*print;

	print = (char *)malloc(sizeof(char) * 2);
	print[0] = character;
	print[1] = '\0';
	if ((format.flags.width) != 0 && ((int64_t)(ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_args(char *string, t_fmt format)
{
	char	*print;

	if ((format.flags.width) != 0 && ((int64_t)(ft_strlen(string)) < (format.flags.width)))
		print = width(string, format);
	else
		print = ft_strdup(string);
	return (print);
}

char	*ft_argp(long long int pointer, t_fmt format)
{
	char	*print;

	print = ft_strdup("0x");
	print = ft_strjoin(print, ft_itoa_hex(pointer, 0));
	if ((format.flags.width) != 0 && (((int64_t)ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_argdi(int64_t decimal, t_fmt format)
{
	char	*print;

	print = ft_itoa((int)decimal);
	if ((format.flags.width) != 0 && (((int64_t)ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_argu(uint64_t unsignedint, t_fmt format)
{
	char	*print;

	print = ft_itoa_unsigned(unsignedint);
	if ((format.flags.width) != 0 && ((int64_t)ft_strlen(print) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_argx(int64_t hex, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hex, 0);
	if ((format.flags.width) != 0 && (((int64_t)ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_argxcap(int64_t hexcap, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hexcap, 1);
	if ((format.flags.width) != 0 && (((int64_t)ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*ft_argpercent(t_fmt format)
{
	char	*print;

	print = (char *)malloc(sizeof(char) * 2);
	print = "%";
	if ((format.flags.width) != 0 && (((int64_t)ft_strlen(print)) < (format.flags.width)))
		print = width(print, format);
	return (print);
}

char	*charspecifiers(char *string, t_fmt format)
{
	char	*print;

	print = ft_args(string, format);
	return (print);
}
	
char	*intspecifiers(char c, int64_t integer, t_fmt format)
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
	return (print);
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

int	ft_printf(const char *fmt, ...)
{
	va_list 	ap;
	char		*print;
	char		*temp;
	char		*spec;
	char		*temparg;
	int64_t		intarg;
	int		last_pos;
	int		arg;
	int		i;
	int		j;
	t_fmt		format;

	i = 0;
	j = 0;
	last_pos = -1;
	initflags(&(format.flags));
	va_start(ap, fmt);
	print = (char *)malloc(sizeof(char));
	ft_bzero(print, sizeof(print));
	while (fmt && fmt[i])
	{	
		if (fmt[i] == '%' || fmt[i + 1] == '\0')
		{	
			
			if (fmt[i + 1] == '\0')
			{	
				temp = ft_substr(fmt, last_pos + 1, i - last_pos + 1);
				temp = ft_strjoin(print, temp);
				free(print);
				print = temp;
				i++;
			}
			else if (fmt[i] == '%')
			{
				if (isspec(fmt[i + 1]) == 1 || isflag(fmt[i + 1] == 1) || (fmt[i + 1] >= '1' && fmt[i + 1] <= '9'))
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
							arg = va_arg(ap, int64_t);
						assignflags(&fmt[i], arg, &(format.flags));
						i = i + (strlenint(&fmt[i]));
					}	
					if (isspec(fmt[i]))
					{
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
	return (j);
}
