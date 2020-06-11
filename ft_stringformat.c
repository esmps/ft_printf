/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:11:17 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/09 14:58:40 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int64_t	fmtstrlen(char *string, t_fmt format)
{
	int64_t	str;
	int64_t	strlen;

	str = ft_strlen(string);
	if (str > format.flags.precision && format.flags.precision > -1)
		strlen = format.flags.precision;
	else
		strlen = str;
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

static char	*allocstring(int64_t strlen, t_fmt format)
{
	int64_t	len;
	char	*print;

	len = format.flags.width >= strlen ? format.flags.width : strlen;
	print = ft_strnew(len);
	ft_memset(print, ' ', len);
	return (print);
}

static char	*assignstr(char *print, char *string, int64_t strlen, int64_t start, t_fmt format)
{
	int	i;

	i = 0;	
	if (format.flags.leftal == 1)
	{
		while (start < strlen)
			print[start++] = string[i++];
	}
	else
	{
			// add zero flag here? undefined behav. but if i feel like it sure.
		while (start < (int64_t)ft_strlen(print))
			print[start++] = string[i++];
	}
	return (print);	

}

char	*ft_fmtstr(char *string, t_fmt format)
{
	int64_t	strlen;
	int64_t	start;
	char 	*print;
	
	strlen = fmtstrlen(string, format);
	start = setstart(strlen, format);
	print = allocstring(strlen, format);
	assignstr(print, string, strlen, start, format);
	return (print);
}

