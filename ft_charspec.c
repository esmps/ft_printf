/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:33:11 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 23:35:03 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


char	*ft_argc(int64_t character, t_fmt format)
{
	char	*print;

	print = (char *)malloc(sizeof(char) * 2);
	print[0] = character;
	print[1] = '\0';
	print = ft_fmtstr(print, format);
	return (print);
}

char	*ft_args(char *string, t_fmt format)
{
	char	*print;
	int64_t	i;

	i = 0;
	print = ft_fmtstr(string, format);
	return (print);
}

char	*ft_argp(int64_t pointer, t_fmt format)
{
	char	*print;
	int64_t	i;

	i = 0;
	print = ft_strdup("0x");
	print = ft_strjoin(print, ft_itoa_hex(pointer, 0));
	print = ft_fmtstr(print, format);
	return (print);
}

char	*ft_argpercent(t_fmt format)
{
	char	*print;

	print = (char *)malloc(sizeof(char) * 2);
	print = "%";
	print = ft_fmtstr(print, format);
	return (print);
}

char	*charspecifiers(char *string, t_fmt format)
{
	char	*print;

	print = ft_args(string, format);
	return (print);
}
