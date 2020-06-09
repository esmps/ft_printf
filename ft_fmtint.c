/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:11:03 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 23:14:46 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

// rename this to ft_n_intalloc
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
//rename this to ft_p_intalloc
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
static int64_t	ft_n_setj(int64_t strlen, t_fmt format)
{
	int64_t	j;

	j = 0;	
	if (format.flags.leftal == 0 && format.flags.width > strlen)
	{
		if (format.flags.precision > strlen)
			j = format.flags.width - format.flags.precision - 1;
		else if (strlen > format.flags.precision && format.flags.zero == 0)
			j = format.flags.width - strlen - 1;
		else if (format.flags.width > format.flags.precision && strlen > format.flags.precision && format.flags.zero == 1 && format.flags.precision > 0)
			j = format.flags.width - strlen - 1;
	}
	return (j);

}
static int64_t	ft_p_setj(int64_t strlen, t_fmt format)
{
	int64_t	j;

	j = 0;
	if (format.flags.leftal == 0 && format.flags.width > strlen)
	{
		if (format.flags.precision > strlen)
			j = format.flags.width - format.flags.precision;	
		else if (strlen > format.flags.precision && format.flags.zero == 0)
			j = format.flags.width - strlen;
		else if (format.flags.width > format.flags.precision && strlen > format.flags.precision && format.flags.zero == 1 && format.flags.precision > 0)
			j = format.flags.width - strlen;
	}
	return (j);
}

static char	*ft_intassign(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	if (string[0] == '-')
	{
		if (format.flags.leftal == 1)
			ft_n_leftal(string, strlen, print, format, j);
		else
			ft_n_rightal(string, strlen, print, format, j);
	}
	else 
	{
		if (format.flags.leftal == 1)
			ft_p_leftal(string, strlen, print, format, j);
		else 
			ft_p_rightal(string, strlen, print, format, j);
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
		j = ft_n_setj(strlen, format);
		ft_intassign(string, strlen, print, format, j);
	}
	else
	{
		strlen = (int64_t)ft_strlen(string);
		print = ft_intposalloc(strlen, format);
		j = ft_p_setj(strlen, format);
		ft_intassign(string, strlen, print, format, j);
	}
	return (print);
}
