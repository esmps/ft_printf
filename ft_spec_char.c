/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:33:11 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 01:23:52 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


char	*ft_argc(int64_t character, t_fmt format)
{
	char	*print;

	print = ft_fmtchar((char)character, format);
	return (print);
}

char	*ft_args(char *string, t_fmt format)
{
	char	*print;

	print = ft_fmtstr(string, format);
	return (print);
}

char	*ft_argp(int64_t pointer, t_fmt format)
{
	char	*print;

	print = ft_strdup("0x");
	if (format.flags.precision != 0)
		print = ft_strjoin(print, ft_itoa_hex(pointer, 0));
	print = ft_fmtptr(print, format);
	return (print);
}

char	*ft_argpercent(t_fmt format)
{
	char	*print;

	print = ft_strnew(1);
	print[0] = '%';
	print = ft_fmtchar('%', format);
	return (print);
}

char	*assignint_helper(char *string, char *print, t_fmt format, int64_t start, int64_t str)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (string[i] == '-')
		i++;
	if (format.flags.precision > str)
	{
		while (j++ < format.flags.precision - str)
			print[start++] = '0';
		while (j++ <= format.flags.precision)
			print[start++] = string[i++];
	}
	else if (format.flags.leftal == 0 && format.flags.zero == 1 && format.flags.width > str && format.flags.precision == -1)
	{
		if (string[0] == '-')
			while (j++ < format.flags.width - str - 1)
				start++;
		while (j++ < format.flags.width)
			print[start++] = string[i++];
	}
	else
		while (j++ < str)
			print[start++] = string[i++];
	return (print);
}