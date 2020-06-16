/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 00:53:28 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/11 01:58:54 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_printstring(char *print, char *spec, t_print printint)
{
	char	*printstring;
	int	x;
	int	y;

	x = 0;
	y = 0;
	printstring = ft_strnew((size_t)printint.len);
	while (x < printint.templen)
	{
		printstring[x] = print[x];
		x++;
	}
	while (x < printint.len)
	{
		printstring[x] = spec[y++];
		x++;
	}
	return (printstring);
}
