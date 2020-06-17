/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 23:35:21 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/10 23:49:15 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static int64_t	setstart(t_fmt format)
{
	int64_t	start;

	start = 0;
	if (format.flags.width > 1 && format.flags.leftal == 0)
		start = format.flags.width - 1;
	else
		start = 0;
	return (start);
}

static char		*allocchar(t_fmt format)
{
	int64_t	len;
	char	*print;

	len = format.flags.width >= 1 ? format.flags.width : 1;
	print = ft_strnew(len);
	if (format.flags.zero == 1 && format.flags.leftal == 0)
		ft_memset(print, '0', len);
	else if (format.flags.width > 1)
		ft_memset(print, ' ', len);
	else
		ft_memset(print, '\0', len);
	return (print);
}

char			*ft_fmtchar(char character, t_fmt format)
{
	char	*print;
	int64_t	start;

	start = setstart(format);
	print = allocchar(format);
	print[start] = character;
	return (print);
}
