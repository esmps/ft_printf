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
	char	*tmp_dec;

	tmp_dec = ft_itoa((int)decimal);
	print = ft_fmtint(tmp_dec, format);
	free(tmp_dec);
	return (print);
}

char	*ft_argu(uint64_t unsignedint, t_fmt format)
{
	char	*print;
	char	*tmp_unsigned;

	tmp_unsigned = ft_itoa_unsigned(unsignedint);
	print = ft_fmtint(tmp_unsigned, format);
	free(tmp_unsigned);
	return (print);
}

char	*ft_argx(uint64_t hex, t_fmt format)
{
	char	*print;
	char	*tmp_hex;

	tmp_hex = ft_itoa_hex(hex, 0);
	print = ft_fmtint(tmp_hex, format);
	free(tmp_hex);
	return (print);
}

char	*ft_argxcap(uint64_t hexcap, t_fmt format)
{
	char	*print;
	char	*tmp_hex;

	tmp_hex = ft_itoa_hex(hexcap, 1);
	print = ft_fmtint(tmp_hex, format);
	free(tmp_hex);
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
		print = ft_strncpy(print + start, string + i, str);
	}
	else if (format.flags.leftal == 0 && format.flags.zero == 1
		&& format.flags.width > str && format.flags.precision == -1)
	{
		while (string[0] == '-' && j++ < format.flags.width - str - 1)
			start++;
		print = ft_strncpy(print + start, string + i, str);
	}
	else
		print = ft_strncpy(print + start, string + i, str);
	return (print);
}
