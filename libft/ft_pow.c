/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:05:45 by epines-s          #+#    #+#             */
/*   Updated: 2020/02/19 15:49:01 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int p)
{
	int	res;

	res = 1;
	if (p < 0)
		return (0);
	while (p)
	{
		res = res * n;
		p--;
	}
	return (res);
}
