/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:48:39 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/09 14:57:54 by epines-s         ###   ########.fr       */
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

typedef struct	s_flags
{
	int64_t	zero;
	int64_t	leftal;
	int64_t	precision;
	int64_t	width;
}				t_flags;

typedef struct	s_print
{
	int64_t	len;
	int64_t	templen;
	int64_t	last_pos;
}				t_print;

typedef struct	s_fmt
{
	struct s_flags	flags;
	struct s_print	print;
	const char		*fmt;
}				t_fmt;

int				ft_printf(const char *fmt, ...);
char			*ft_fmtstr(char *string, t_fmt format);
char			*ft_fmtint(char *string, t_fmt format);
char			*ft_fmtchar(char character, t_fmt format);
char			*intspecifiers(char c, int64_t integer,
					t_fmt format, t_print *printint);
char			*assignint(char *string, char *print,
					t_fmt format, int64_t start);
char			*charspecifiers(char *string, t_fmt format, t_print *printint);
char			*readspec(const char fmt, va_list ap, t_fmt *format);
char			*ft_fmtptr(char *string, t_fmt format);
char			*ft_argdi(int64_t decimal, t_fmt format);
char			*ft_argu(uint64_t unsignedint, t_fmt format);
char			*ft_argx(uint64_t hex, t_fmt format);
char			*ft_argxcap(uint64_t hexcap, t_fmt format);
char			*ft_argp(int64_t pointer, t_fmt format);
char			*ft_args(char *string, t_fmt format);
char			*ft_argc(int64_t character, t_fmt format);
char			*ft_argpercent(t_fmt format);

int				isflag(char c);
int				isspec(char c);
int				set_flag(va_list ap, const char *fmt, t_fmt *format);
int				process(va_list ap, const char *fmt);
int64_t			actual_str_len(char *string, t_fmt format);
int64_t			strlenint(const char *fmt);

t_flags			*initflags(t_flags *subspec);

#endif
