/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:48:39 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:28:49 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct flags
{
	int64_t	zero;
	int64_t	leftal;
	int64_t	precision;
	int64_t	width;
}			t_flags;

typedef struct fmt
{
	struct flags	flags;
}			t_fmt;


int	ft_printf(const char *fmt, ...);
char	*ft_itoa_hex(long long int num, int letter);
char	*ft_itoa_unsigned(uint64_t n);
char	*ft_fmtstr(char *string, t_fmt format);
char	*ft_fmtint(char *string, t_fmt format);


#endif
