/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:25:07 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/10 15:34:48 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int64_t	fmtstrlen(char *string, t_fmt format)
{
	int64_t	str;
	int64_t	strlen;

	if (string[0] == '-')
		str = ft_strlen(string) - 1;
	else
		str = ft_strlen(string);
	if (str < format.flags.precision && format.flags.precision > -1)
		strlen = format.flags.precision;
	else if ((string[0] == '0' && string[1] == '\0' && format.flags.precision == 0) || string[0] == '\0')
		strlen = 0;
	else
		strlen = str;
	return (strlen);
}

static int64_t setstart(char *string, int64_t strlen, t_fmt format)
{
	int64_t start;

	start = 0;
	if (string[0] == '-')
	{
		if ((format.flags.width > strlen && format.flags.leftal == 0 && format.flags.zero == 0) \
			|| (format.flags.width > strlen && format.flags.precision > -1 && format.flags.zero == 1 && format.flags.leftal == 0))
			start = format.flags.width - strlen - 1;
		else
			start = 0;
	}
	else
	{
		if (format.flags.width > strlen && format.flags.leftal == 0 && strlen > 0)
			start = format.flags.width - strlen;
		else
			start = 0;
		
	}
	return (start);
}

static char	*allocint(char *string, int64_t strlen, t_fmt format)
{
	int64_t	len;
	char	*print;

	if (string[0] == '-')
		len = format.flags.width >= strlen ? format.flags.width : strlen + 1;
	else
		len = format.flags.width >= strlen ? format.flags.width : strlen;
	print = ft_strnew(len);
	if (format.flags.leftal == 0 && format.flags.zero == 1 && format.flags.precision == -1)
		ft_memset(print, '0', len);
	else
		ft_memset(print, ' ', len);
	return (print);
}

static char	*assignint(char *string, char *print, t_fmt format, int64_t start)
{
	int64_t i;
	int64_t j;
	int64_t str;

	i = 0;
	j = 0;
	if (string[i] == '-')
	{
		str = (int64_t)ft_strlen(string) - 1;
		print[start++] = '-';
		i++;
	}
	else if (string[0] == '0' && string[1] =='\0' && format.flags.precision == 0)
		str = 0;
	else
		str = (int64_t)ft_strlen(string);
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

char	*ft_fmtint(char *string, t_fmt format)
{
	char	*print;
	int64_t	strlen;
	int64_t	start;

	strlen = fmtstrlen(string, format);
	start = setstart(string, strlen, format);
	print = allocint(string, strlen, format);
	assignint(string, print, format, start);
	return (print);
}
