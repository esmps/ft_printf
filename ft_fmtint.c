/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:11:03 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 22:14:12 by epines-s         ###   ########.fr       */
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
		print = (char *)malloc(sizeof(char) * format.flags.precision + 2);
		print[format.flags.precision + 1] = '\0';
	}
	else if ((format.flags.width > format.flags.precision && format.flags.precision > strlen) \
	|| (format.flags.width > strlen && strlen > format.flags.precision))
	{
		print = (char *)malloc(sizeof(char) * format.flags.width + 1);
		print[format.flags.width] = '\0';
	}
	else
	{
		print = (char *)malloc(sizeof(char) * strlen + 2);
		print[strlen + 1] = '\0';
	}
	return (print);
}

static char	*ft_intposalloc(int64_t strlen, t_fmt format)
{
	char	*print;

	if ((format.flags.precision > format.flags.width && format.flags.width > strlen) || (format.flags.precision > strlen && strlen > format.flags.width))
	{
		print = (char *)malloc(sizeof(char) * format.flags.precision + 1);
		print[format.flags.precision] = '\0';
	}
	else if ((format.flags.width > format.flags.precision && format.flags.precision > strlen) || (format.flags.width > strlen && strlen > format.flags.precision))
	{
		print = (char *)malloc(sizeof(char) * format.flags.width + 1);
		print[format.flags.width] = '\0';
	}
	else
	{
		print = (char *)malloc(sizeof(char) * strlen + 1);
		print[strlen] = '\0';
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
		while (j < format.flags.width)
			print[j++] = string[i++];
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
		ft_memset(print, ' ', (int64_t)ft_strlen(print));
		j = ft_intnegleftal(string, strlen, format);
		ft_intnegassign(string, strlen, print, format, j);
	}
	else
	{
		strlen = (int64_t)ft_strlen(string);
		print = ft_intposalloc(strlen, format);
		ft_memset(print, ' ', (int64_t)ft_strlen(print));
		j = ft_intposleftal(strlen, format);
		ft_intposassign(string, strlen, print, format, j);
	}
	return (print);
}
