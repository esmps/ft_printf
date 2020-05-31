/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:45:17 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/20 13:06:43 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

static int	isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int			ft_isalpha(int c)
{
	if (isupper(c) || islower(c))
		return (1);
	return (0);
}
