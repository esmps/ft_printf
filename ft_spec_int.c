/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:21:22 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 23:24:10 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_argdi(int64_t decimal, t_fmt format)
{
	char	*print;
	int newdecimal = (int)decimal;

	print = ft_itoa(newdecimal);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argu(uint64_t unsignedint, t_fmt format)
{
	char	*print;

	print = ft_itoa_unsigned(unsignedint);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argx(int64_t hex, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hex, 0);
	print = ft_fmtint(print, format);
	return (print);
}

char	*ft_argxcap(int64_t hexcap, t_fmt format)
{
	char	*print;

	print = ft_itoa_hex(hexcap, 1);
	print = ft_fmtint(print, format);
	return (print);
}