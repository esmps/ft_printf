/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:11:03 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 01:39:15 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static char	*ft_intnegalloc(int64_t strlen,  t_fmt format)
{
	char	*print;
	
	if ((format.flags.precision > format.flags.width && format.flags.width > strlen)\
	 || (format.flags.precision > strlen && strlen > format.flags.width))
	{
		print = ft_strnew((int)format.flags.precision + 1);
		ft_memset(print, ' ', format.flags.precision + 1);
	}
	else if ((format.flags.width > format.flags.precision && format.flags.precision > strlen) \
	|| (format.flags.width > strlen && strlen > format.flags.precision))
	{
		print = ft_strnew((int)format.flags.width);
		ft_memset(print, ' ',format.flags.width);
	}
	else
	{
		print = ft_strnew((int)strlen + 1);
		ft_memset(print, ' ', strlen + 1);
	}
	return (print);
}

static char	*ft_intposalloc(int64_t strlen, t_fmt format)
{
	char	*print;

	if ((format.flags.precision > format.flags.width && format.flags.width > strlen) || (format.flags.precision > strlen && strlen > format.flags.width))
	{
		print = ft_strnew((int)format.flags.precision);
		ft_memset(print, ' ', format.flags.precision);
	}
	else if ((format.flags.width > format.flags.precision && format.flags.precision > strlen) || (format.flags.width > strlen && strlen > format.flags.precision))
	{
		print = ft_strnew((int)format.flags.width);
		ft_memset(print, ' ', format.flags.width);
	}
	else
	{
		print = ft_strnew(strlen);
		ft_memset(print, ' ', strlen);
	}
	return (print);
}

static int64_t	ft_intnegleftal(char *string, int64_t strlen, t_fmt format)
{
	int64_t	j;

	j = 0;
	if (format.flags.leftal == 0 && format.flags.width > format.flags.precision && format.flags.precision > strlen)
		j = format.flags.width - format.flags.precision;
	else if (format.flags.leftal == 0 && format.flags.width > strlen && strlen > format.flags.precision)
		j = format.flags.width - strlen;
	else if (string[0] == '-')
		j = 1;
	return (j);

}

static int64_t	ft_intposleftal(int64_t strlen, t_fmt format)
{
	int64_t	j;

	j = 0;
	if (format.flags.leftal == 0 && format.flags.width > format.flags.precision && format.flags.precision > strlen) 
		j = format.flags.width - format.flags.precision;
	else if (format.flags.leftal == 0 && format.flags.width > strlen && strlen > format.flags.precision)
		j = format.flags.width - strlen;
	return (j);
}

static char	*ft_intnegassign(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;
	
	i = 1;
	if (format.flags.width > format.flags.precision && format.flags.precision > strlen)
		print[format.flags.width - format.flags.precision - 1] = '-';
	else if (format.flags.width > strlen && strlen > format.flags.precision)
		print[format.flags.width - strlen - 1] = '-';
	else 
		print[0] = '-';
	if (format.flags.width > format.flags.precision && format.flags.precision > strlen)
	{	
		while (j < format.flags.width - strlen)
			print[j++] = '0';	
		while (j < format.flags.width + 1)
			print[j++] = string[i++];	
	}
	else if (format.flags.precision > strlen && format.flags.precision > format.flags.width)
	{
		while (j < format.flags.precision - strlen + 1)
			print[j++] = '0';
		while (j < format.flags.precision + 1)
			print[j++] = string[i++];
	}
	else if (format.flags.width > strlen && strlen > format.flags.precision)
	{
		while (j < format.flags.width + 1)
			print[j++] = string[i++];
	}
	else
	{
		while (j < strlen + 1)
			print[j++] = string[i++];
	}
	return (print);
}

static char	*ft_intposassign(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	if (format.flags.width > format.flags.precision && format.flags.precision > strlen)
	{
		if (format.flags.leftal == 0)
		{
			while (j < format.flags.width - strlen)
				print[j++] = '0';
			while (j < format.flags.width)
				print[j++] = string[i++];
		}
		else
		{
			while (j < format.flags.precision - strlen && format.flags.leftal == 1)
				print[j++] = '0';
			while (j < format.flags.precision)
				print[j++] = string[i++];
		}
	}
	else if (format.flags.precision > strlen && format.flags.precision > format.flags.width)
	{
		while (j < format.flags.precision - strlen)
			print[j++] = '0';
		while (j < format.flags.precision)
			print[j++] = string[i++];
	}
	else if (format.flags.width > strlen && strlen > format.flags.precision)
	{
		if (format.flags.leftal == 1)
		{
			while (j < strlen)
				print[j++] = string[i++];
		}
		else
		{
			while (j < format.flags.width)
				print[j++] = string[i++];
		}
	}
	else
	{
		while (j < strlen)
			print[j++] = string[i++];
	}
	return (print);
}

char	*ft_fmtint(char *string, t_fmt format)
{
	char	*print;
	int64_t	strlen;
	int64_t	j;

	if (string[0] == '-')
	{
		strlen = (int64_t)ft_strlen(string) - 1;
		print = ft_intnegalloc(strlen, format);
		j = ft_intnegleftal(string, strlen, format);
		ft_intnegassign(string, strlen, print, format, j);
	}
	else
	{
		strlen = (int64_t)ft_strlen(string);
		print = ft_intposalloc(strlen, format);
		j = ft_intposleftal(strlen, format);
		ft_intposassign(string, strlen, print, format, j);
	}
	return (print);
}
