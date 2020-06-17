/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:42:42 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 23:44:40 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int64_t	strlenint(const char *fmt)
{
	int64_t	i;

	i = 0;
	if (*fmt >= '0' && *fmt <= '9')
		while (*fmt >= '0' && *fmt++ <= '9')
			i++;
	else
		i = 1;
	return (i);
}

int		isflag(char c)
{
	return (ft_strchr(".-0*", c) ? 1 : 0);
}

int		isspec(char c)
{
	return (ft_strchr("cspdiuxX%", c) ? 1 : 0);
}
