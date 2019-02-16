/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_var.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:52:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:16:24 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_var(t_fmt *fmt, va_list ap)
{
	if (fmt->conv == '\0')
		return (0);
	if (fmt->conv == '%')
		return (print_char(fmt, '%'));
	if (is_unsigned(fmt->conv) && is_long(fmt->conv, fmt->length))
		return (print_ulong(fmt, va_arg(ap, unsigned long long)));
	if (is_unsigned(fmt->conv) && is_int(fmt->conv))
		return (print_uint(fmt, va_arg(ap, unsigned int)));
	if (is_long(fmt->conv, fmt->length))
		return (print_long(fmt, va_arg(ap, long long)));
	if (is_int(fmt->conv) && !is_short(fmt->length) &&
		!is_charsign(fmt->conv, fmt->length))
		return (print_int(fmt, va_arg(ap, int)));
	if (is_int(fmt->conv) && is_short(fmt->length))
		return (print_short(fmt, va_arg(ap, int)));
	if (is_double(fmt->conv))
		return (print_double(fmt, va_arg(ap, double)));
	if (is_char(fmt->conv))
		return (print_char(fmt, va_arg(ap, int)));
	if (is_charsign(fmt->conv, fmt->length))
		return (print_int(fmt, (signed char)va_arg(ap, int)));
	if (is_wcharp(fmt->conv, fmt->length))
		return (0);
	if (is_charp(fmt->conv))
		return (print_charp(fmt, va_arg(ap, char*)));
	if (is_voidp(fmt->conv))
		return (0);
	return (0);
}
