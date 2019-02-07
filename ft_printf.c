/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 16:36:22 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 13:40:38 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int		is_int(char c)
{
	if (c == 'd' || c == 'i' || c == 'o')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int 	is_double(char c)
{
	if (c == 'e' || c == 'E')
		return (1);
	if (c == 'f' || c == 'F')
		return (1);
	if (c == 'g' || c == 'G')
		return (1);
	if (c == 'a' || c == 'A')
		return (1);
	return (0);
}

int		is_char(char c)
{
	if (c == 'C' || c == 'c')
		return (1);
	return (0);
}

int		is_charp(char c)
{
	if (c == 's')
		return (1);
	return (0);
}

int		is_voidp(char c)
{
	if (c == 'p')
		return (1);
	return (0);
}

int		is_longint(char c)
{
	if (c == 'D' || c == 'O' || c == 'U')
		return (1);
	return (0);
}

int		is_wcharp(char c, int l)
{
	if (c == 's' && l == 'l')
		return (1);
	if (c == 'S')
		return (1);
	return (0);
}

int		print_var(t_fmt *fmt, va_list ap)
{
	if (is_int(fmt->conv))
		return (ft_rputnbr(va_arg(ap, int)));
	if (is_double(fmt->conv))
		return (0);
	if (is_char(fmt->conv))
	{
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	if (is_wcharp(fmt->conv, fmt->length))
		return (0);
	if (is_charp(fmt->conv))
		return (ft_rputstr(va_arg(ap, char*)));
	if (is_voidp(fmt->conv))
		return (0);
	if (is_longint(fmt->conv))
		return (0);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int len;
	t_fmt *fmt;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fmt = check_format(&format);
			len += print_var(fmt, ap);
		}
		else
		{
			ft_putchar(*format);
			format++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
