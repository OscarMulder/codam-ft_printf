/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_var.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:52:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/08 16:15:18 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_var(t_fmt *fmt, va_list ap)
{
	if (fmt->conv == '%')
		return (print_char(fmt, '%'));
	if (is_int(fmt->conv))
		return (print_int(fmt, va_arg(ap, int)));
	if (is_double(fmt->conv))
		return (0);
	if (is_char(fmt->conv))
		return(print_char(fmt, va_arg(ap, int)));
	if (is_wcharp(fmt->conv, fmt->length))
		return (0);
	if (is_charp(fmt->conv))
		return (print_charp(fmt, va_arg(ap, char*)));
	if (is_voidp(fmt->conv))
		return (0);
	if (is_longint(fmt->conv))
		return (0);
	return (0);
}
