/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 23:33:11 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 01:23:52 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_argc(int64_t character, t_fmt format)
{
	char	*print;

	print = ft_fmtchar((char)character, format);
	return (print);
}

char	*ft_args(char *string, t_fmt format)
{
	char	*print;

	print = ft_fmtstr(string, format);
	return (print);
}

char	*ft_argp(int64_t pointer, t_fmt format)
{
	char	*print;
	char	*tmp_ptr;
	char	*tmp_print;

	tmp_ptr = ft_itoa_hex(pointer, 0);
	if (pointer == 0 && format.flags.precision == 0)
		tmp_print = ft_strdup("0x");
	else if (pointer == 0)
		tmp_print = ft_strdup("0x0");
	else
		tmp_print = ft_strjoin("0x", tmp_ptr);
	print = ft_fmtptr(tmp_print, format);
	free(tmp_ptr);
	free(tmp_print);
	return (print);
}

char	*ft_argpercent(t_fmt format)
{
	char	*print;

	print = ft_fmtchar('%', format);
	return (print);
}
