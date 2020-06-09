/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:00:11 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 01:02:08 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


char	*ft_stralloc(int64_t strlen, t_fmt format)
{
	char *print;
	int64_t	len;

	len = 0;
	if (format.flags.precision >= 0 && format.flags.width > 0 && strlen > 0)
	{
		if (format.flags.precision == format.flags.width)
		{
			if(format.flags.precision == strlen)
				len = strlen;
			else
				len = format.flags.precision;
		}
		else if (format.flags.precision == strlen || format.flags.width == strlen)
		{
			if (format.flags.precision == strlen && format.flags.width > strlen)
				len = format.flags.width;
			else
				len = strlen;
		}
		else if (format.flags.precision > format.flags.width)
		{
			if (strlen > format.flags.precision)
				len = format.flags.precision;
			else if (format.flags.width > strlen)
				len = format.flags.width;
			else 
				len = strlen;
		}
		else if (format.flags.width > format.flags.precision)
		{
			len = format.flags.width;
		}
	}
	else
	{
		if (format.flags.width > strlen)
			len = format.flags.width;
		else if (strlen > format.flags.precision && format.flags.width == 0)
			len = format.flags.precision;
		else
			len = strlen;
	}
	print = ft_strnew(len);
	ft_memset(print, ' ', len);
	return (print);	
}

int64_t	ft_str_setj(int64_t strlen, t_fmt format)
{
	int64_t j;

	j = 0;
	if (format.flags.leftal == 1)
		j = 0;
	else if (format.flags.precision > 0 && format.flags.width > 0 && strlen > 0)
	{
		if (format.flags.precision == format.flags.width)
		{
			if (format.flags.precision > strlen)
				j = format.flags.precision - strlen;
			else
				j = 0;
		}
		else if (format.flags.precision == strlen || format.flags.width == strlen)
		{
			if (format.flags.precision == strlen && format.flags.width > strlen)
				j = format.flags.width - strlen;
			else if (format.flags.width == strlen && format.flags.precision < strlen)
				j = format.flags.width - format.flags.precision;
			else
				j = 0;
		}
		else if (format.flags.precision > format.flags.width)
		{
			if (strlen > format.flags.precision)
				j = 0;
			else if (format.flags.width > strlen)
				j = format.flags.width - strlen;
			else 
				j = 0;
		}
		else if (format.flags.width > format.flags.precision)
		{
			if (format.flags.precision > strlen)
				j = format.flags.width - strlen;
			else
				j = format.flags.width - format.flags.precision;
		}
	}
	else
	{
		if (format.flags.width > strlen)
			j = format.flags.width - strlen;	
		else
			j = 0;
	}
	return (j);
}

char	*ft_strassign(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	if (format.flags.leftal == 1)
	{
		if (format.flags.width > format.flags.precision && format.flags.precision < strlen)
		{
			while (j < format.flags.precision)
				print[j++] = string[i++];
		}
		else
		{
			while (j < strlen)
				print[j++] = string[i++];
		}
	}
	else
	{
		while (j < (int64_t)ft_strlen(print))
			print[j++] = string[i++];
	}
	return (print);
}

char	*ft_fmtstr(char *string, t_fmt format)
{
	int64_t	strlen;
	int64_t	j;
	char 	*print;
	
	strlen = (int64_t)ft_strlen(string);
	print = ft_stralloc(strlen, format);
	j = ft_str_setj(strlen, format);
	ft_strassign(string, strlen, print, format, j);
	return (print);
}
