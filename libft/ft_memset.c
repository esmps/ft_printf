/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:45:57 by epines-s          #+#    #+#             */
/*   Updated: 2020/03/09 14:29:00 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*str;
	size_t			i;

	i = 0;
	str = (char *)b;
	ch = (unsigned char)c;
	while (len > 0)
	{
		str[i] = ch;
		i++;
		len--;
	}
	return (str);
}
