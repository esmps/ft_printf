/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:21:22 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 23:24:10 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_argdi(int64_t decimal, t_fmt format)
{
	char	*print;

	print = ft_itoa((int)decimal);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argu(uint64_t unsignedint, t_fmt format)
{
	char	*print;

	print = ft_itoa_unsigned(unsignedint);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argx(int64_t hex, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hex, 0);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argxcap(int64_t hexcap, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hexcap, 1);
	print = ft_fmtint(print, format);
	return (print);
}

char	*assignint(char *string, char *print, t_fmt format, int64_t start)
{
	int64_t	j;
	int64_t	i;
	int64_t	str;

	i = 0;
	j = 0;
	str = actual_str_len(string, format);
	if (string[i] == '-')
		print[start++] = string[i++];
	if (format.flags.precision > str)
	{
		while (j++ < format.flags.precision - str)
			print[start++] = '0';
		ft_strncpy(print + start, string + i, format.flags.precision - j + 1);
	}
	else if (format.flags.leftal == 0 && format.flags.zero == 1
		&& format.flags.width > str && format.flags.precision == -1)
	{
		while (string[0] == '-' && j++ < format.flags.width - str - 1)
			start++;
		print = ft_strncpy(print + start, string + i, format.flags.width - j);
	}
	else
		print = ft_strncpy(print + start, string + i, str - j);
	return (print);
}
