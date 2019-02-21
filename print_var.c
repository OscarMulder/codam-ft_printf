/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_var.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:52:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:12:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*get_uputfunc(t_fmt fmt))(unsigned long long, int, int)
{
	if (is_uchar(fmt))
		return (&ft_putuchar_base);
	if (is_ushort(fmt))
		return (&ft_putushort_base);
	if (is_uint(fmt))
		return (&ft_putunbr_base);
	if (is_ulong(fmt))
		return (&ft_putulong_base);
	return (&ft_putulong_base);
}

int		(*get_ulenfunc(t_fmt fmt))(unsigned long long, int)
{
	if (is_uchar(fmt))
		return (&ft_ucharlen);
	if (is_ushort(fmt))
		return (&ft_ushortlen);
	if (is_uint(fmt))
		return (&ft_uintlen);
	if (is_ulong(fmt))
		return (&ft_ulonglen);
	return (&ft_ulonglen);
}

int		print_var(t_fmt fmt, va_list ap)
{
	if (fmt.conv == '\0')
		return (0);
	if (fmt.conv == '%')
		return (print_char(fmt, '%'));
	if (is_unsigned(fmt))
		return (print_unsigned(fmt, va_arg(ap, unsigned long long), get_ulenfunc(fmt), get_uputfunc(fmt)));	
	if (is_long(fmt.conv, fmt.length))
		return (print_long(fmt, va_arg(ap, long long)));
	if (is_int(fmt.conv) && !is_short(fmt.length) &&
		!is_charsign(fmt.conv, fmt.length))
		return (print_int(fmt, va_arg(ap, int)));
	if (is_int(fmt.conv) && is_short(fmt.length))
		return (print_short(fmt, va_arg(ap, int)));
	if (is_double(fmt.conv))
		return (print_double(fmt, va_arg(ap, double)));
	if (is_char(fmt.conv))
		return (print_char(fmt, va_arg(ap, unsigned int)));
	if (is_charsign(fmt.conv, fmt.length))
		return (print_int(fmt, (signed char)va_arg(ap, int)));
	if (is_wcharp(fmt.conv, fmt.length))
		return (print_wcharp(fmt, va_arg(ap, wchar_t*)));
	if (is_charp(fmt.conv))
		return (print_charp(fmt, va_arg(ap, char*)));
	if (is_voidp(fmt.conv))
		return (print_pointer(fmt, va_arg(ap, unsigned long long)));
	return (print_char(fmt, fmt.conv));
}
