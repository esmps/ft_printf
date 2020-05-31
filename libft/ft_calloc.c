/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:38:30 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/23 19:39:07 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = count * size;
	str = (void *)malloc(i);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ft_bzero(str, i);
	return (str);
}
