/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:00:11 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 17:29:24 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


char	*ft_stralloc(char *string, t_fmt format)
{
	char	*print;
	int64_t	strlen;

	strlen = (int64_t)ft_strlen(string);
	if ((format.flags.precision > strlen && strlen > format.flags.width) || (format.flags.precision == 0 && format.flags.width == 0))
	{
		print = (char *)malloc(sizeof(char) * strlen + 1);
		print[strlen] = '\0';
	}
	else if (strlen > format.flags.precision && format.flags.precision > format.flags.width)
	{
		print = (char *)malloc(sizeof(char) * format.flags.precision + 1);
		print[format.flags.precision] = '\0';
	}
	else
	{
		print = (char *)malloc(sizeof(char) * format.flags.width + 1);
		print[format.flags.width] = '\0';
	}
	return (print);
}
int64_t	ft_strleftal(int64_t strlen, t_fmt format)
{
	int64_t j;

	j = 0;
	if (format.flags.leftal == 1 || (format.flags.precision > strlen && strlen > format.flags.width) \
		|| (strlen > format.flags.precision && strlen > format.flags.width))
		j = 0;
	else if (format.flags.width > strlen && strlen > format.flags.precision && format.flags.precision > 0)
		j = format.flags.width - format.flags.precision;
	else
		j = format.flags.width - strlen;
	return (j);
}

char	*ft_strassign(char *string, char *print, t_fmt format, int64_t j)
{
	int64_t	i;
	int64_t strlen;

	i = 0;
	strlen = (int64_t)ft_strlen(string);
	if (format.flags.leftal == 1)
	{
		if (format.flags.precision > strlen)
		{
			while (j < strlen && format.flags.precision > strlen)
				print[j++] = string[i++];
		}
		else
		{
			while (j < format.flags.precision)
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
	print = ft_stralloc(string, format);
	ft_memset(print, ' ', (int64_t)ft_strlen(print));
	j = ft_strleftal(strlen, format);
	ft_strassign(string, print, format, j);
	return (print);
}
