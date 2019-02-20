/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 16:36:22 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 20:27:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	t_fmt	fmt;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fmt = reset_fmt(fmt);
			fmt = check_format(fmt, &format, ap);
			//debug_printfmt(fmt);
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
