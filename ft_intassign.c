/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epines-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:26:01 by epines-s          #+#    #+#             */
/*   Updated: 2020/06/07 22:49:03 by epines-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_p_rightal(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	if (format.flags.precision > strlen)
	{
		if (format.flags.width > format.flags.precision)
		{
			while (j < format.flags.width - strlen)
				print[j++] = '0';
		}
		else
		{
			while (j < format.flags.precision - strlen)
				print[j++] = '0';
		}
	}
	if (format.flags.zero == 1 && format.flags.width > strlen && format.flags.precision == 0)
	{
		while (j < format.flags.width - strlen)
			print[j++] = '0';
		while (j < format.flags.width)
			print[j++] = string[i++];
	}
	if (format.flags.precision > strlen || format.flags.width > strlen)
	{
		if (format.flags.width > format.flags.precision)
		{
			while (j < format.flags.width)
				print[j++] = string[i++];
		}
		else if (format.flags.precision > format.flags.width)
			while (j < format.flags.precision)
				print[j++] = string[i++];
	}
	else
	{
		while (j < strlen)
			print[j++] = string[i++];
	}
	return (print);
}

char	*ft_p_leftal(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	if (format.flags.precision > strlen)
	{
		while (j < format.flags.precision - strlen)
			print[j++] = '0';
		while (j < format.flags.precision)
			print[j++] = string[i++];
	}
	else
	{
		while (j < strlen)
			print[j++] = string[i++];
	}
	return (print);
}

char	*ft_n_rightal(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	print[j++] = string[i++];
	if (format.flags.precision > strlen)
	{
		if (format.flags.width > format.flags.precision)
		{
			while (j < format.flags.width - strlen)
				print[j++] = '0';
		}
		else
		{
			while (j < format.flags.precision - strlen + 1)
				print[j++] = '0';
		}
	}
	else if (format.flags.width > strlen && format.flags.precision == 0)
	{
		while (j < format.flags.width - strlen)
			print[j++] = '0';
	}
	if (strlen < format.flags.precision || strlen < format.flags.width)
	{
		if (format.flags.width > format.flags.precision)
		{
			while (j < format.flags.width + 1)
				print[j++] = string[i++];
		}
		else if (format.flags.precision > format.flags.width)
			while (j < format.flags.precision + 1)
				print[j++] = string[i++];
	}
	else
	{
		while (j < strlen + 1)			
			print[j++] = string[i++];
	}
	return (print);
}

char	*ft_n_leftal(char *string, int64_t strlen, char *print, t_fmt format, int64_t j)
{
	int64_t	i;

	i = 0;
	print[j++] = string[i++];
	if (format.flags.precision > strlen)
	{
		if (format.flags.width > format.flags.precision)
		{
			while (j < format.flags.width - format.flags.precision - strlen + 1)
				print[j++] = '0';
		}
		else
		{
			while (j < format.flags.precision - strlen + 1)
				print[j++] = '0';
		}
		while (j < format.flags.precision + 1)
			print[j++] = string[i++];
	}
	else
	{
		while (j < strlen + 1)
			print[j++] = string[i++];
	}
	return (print);
}
