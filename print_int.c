/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/08 14:31:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printed_chars(t_fmt *fmt, int num)
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
	if (num >= 0 && (fmt->opt[3] || fmt->opt[4]))
		ilen++;
	return (ilen);
}

static void	put_paddingandsign(t_fmt *fmt, int num, int ilen)
{
	if (!fmt->opt[2] && (!fmt->opt[1] || fmt->prec != -1))
		print_padding(' ', (fmt->width - ilen));
	if (num >= 0 && fmt->opt[3] && !fmt->opt[4])
		ft_putchar(' ');
	if (num >= 0 && fmt->opt[4])
		ft_putchar('+');
	if (num < 0)
		ft_putchar('-');
	if (!fmt->opt[2] && fmt->opt[1] && fmt->prec == -1)
		print_padding('0', (fmt->width - ilen));
}

int		print_int(t_fmt *fmt, int num)
{
	int ilen;

	ilen = ft_intlen(num);
	if (fmt->prec > ilen)
		ilen = fmt->prec;
	if (num < 0 || (num >= 0 && fmt->opt[3]) || (num >= 0 && fmt->opt[4]))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt->prec != -1)
		print_padding('0', (fmt->prec - ft_intlen(num)));
	ft_rputnbr(num);
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - ilen));
	return (printed_chars(fmt, num));
}
