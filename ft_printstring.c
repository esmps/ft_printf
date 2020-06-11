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

char	*ft_printstring(char *print, char *spec, int64_t printlen, int j)
{
	char	*printstring;
	int	x;
	int	y;

	x = 0;
	y = 0;
	printstring = ft_strnew((size_t)printlen);
	while (x < j)
	{
		printstring[x] = print[x];
		x++;
	}
	while (x < printlen)
	{
		printstring[x] = spec[y++];
		x++;
	}
	return (printstring);
}
