/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_var.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:52:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 21:01:27 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding(char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
	return (size);
}

int		printed_chars(t_fmt *fmt, int num)
{
	int	ilen;

	ilen = ft_intlen(num);
	if (num < 0)
		ilen++;
	if (fmt->prec > ilen || fmt->width > ilen)
	{
		if (fmt->prec > fmt->width && num >= 0)
			ilen = fmt->prec;
		else if (fmt->prec >= fmt->width && num < 0)
			ilen = fmt->prec + 1;
		else
			ilen = fmt->width;
	}
	if (num >= 0 && fmt->opt[3])
		ilen++;
	return (ilen);
}

int		print_int(t_fmt *fmt, int num)
{
	int ilen;

	ilen = ft_intlen(num);
	if (fmt->prec > ilen)
		ilen = fmt->prec;
	if (num < 0 || (num >= 0 && fmt->opt[3]) || fmt->opt[4])
	ilen++;
	if (num < 0)
	{
		if (fmt->prec == -1 && fmt->opt[1])
			ft_putchar('-');
		if (!fmt->opt[2] && (!fmt->opt[1] || fmt->prec != -1))
			print_padding(' ', (fmt->width - ilen));
		if (!fmt->opt[2] && fmt->prec == -1)
			print_padding('0', (fmt->width - ilen));
		if (!fmt->opt[1] || fmt->prec != -1)
			ft_putchar('-');
	}
	else
	{
		if ((!fmt->opt[2] && !fmt->opt[1]) && (!fmt->opt[2] && fmt->opt[4]))
			print_padding(' ', (fmt->width - ilen));
		if (fmt->opt[3] && !fmt->opt[4])
			ft_putchar(' ');
		if (fmt->opt[4])
			ft_putchar('+');
		if (!fmt->opt[2] && fmt->prec == -1)
			print_padding('0', (fmt->width - ilen));
	}
	if (fmt->prec != -1)
		print_padding('0', (fmt->prec - ft_intlen(num)));
	ft_rputnbr(num);
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - ilen));
	return (printed_chars(fmt, num));
}

int		print_var(t_fmt *fmt, va_list ap)
{
	if (is_int(fmt->conv))
		return (print_int(fmt, va_arg(ap, int)));
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
