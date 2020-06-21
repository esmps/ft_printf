/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 06:21:19 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/19 19:51:33 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int64_t	fmtptrlen(char *ptr_str, t_fmt format)
{
	int64_t	str;
	int64_t	strlen;

	str = (int64_t)ft_strlen(ptr_str) - 2;
	if (str < format.flags.precision && format.flags.precision > 0)
		strlen = format.flags.precision + 2;
	else
		strlen = str + 2;
	return (strlen);
}

static int64_t	setstart(int64_t strlen, t_fmt format)
{
	int64_t	start;

	if (format.flags.leftal == 0 && format.flags.width > strlen)
		start = format.flags.width - strlen;
	else
		start = 0;
	return (start);
}

static char		*allocptr(int64_t strlen, t_fmt format)
{
	int64_t	len;
	char	*print;

	len = format.flags.width >= strlen ? format.flags.width : strlen;
	print = ft_strnew(len);
	if (strlen > format.flags.width)
		ft_memset(print, '0', len);
	else
		ft_memset(print, ' ', len);
	return (print);
}

static char		*assignptr(char *print, char *ptr_str,
	int64_t start, t_fmt format)
{
	int		i;
	int64_t	strlen;

	i = 2;
	strlen = fmtptrlen(ptr_str, format);
	print[start++] = '0';
	print[start++] = 'x';
	if (format.flags.precision > (int64_t)ft_strlen(ptr_str) - 2 &&
		format.flags.width < format.flags.precision && format.flags.leftal == 0)
		while (start < format.flags.precision - (int64_t)ft_strlen(ptr_str) + 4)
			start++;
	if (strlen > format.flags.width || (format.flags.leftal == 1))
		print = ft_strncpy(print + start, ptr_str + i, strlen - start);
	else
	{
		while (start < format.flags.width - (int64_t)ft_strlen(ptr_str)
			+ 2 && format.flags.leftal == 0)
			print[start++] = '0';
		print = ft_strncpy(print + start, ptr_str + i,
			format.flags.width - start);
	}
	return (print);
}

char			*ft_fmtptr(char *ptr_str, t_fmt format)
{
	int64_t	strlen;
	int64_t	start;
	char	*print;

	strlen = fmtptrlen(ptr_str, format);
	start = setstart(strlen, format);
	print = allocptr(strlen, format);
	assignptr(print, ptr_str, start, format);
	return (print);
}
