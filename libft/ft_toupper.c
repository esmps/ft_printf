/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:05:35 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/20 13:05:29 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (islower(c))
		c = c - 32;
	return (c);
}
