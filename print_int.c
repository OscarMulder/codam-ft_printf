/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 20:06:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		find_case(char c)
{
	if (c == 'x')
		return (0);
	return (1);
}

static int		find_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o')
		return (8);
	return (10);
}

static int		printed_chars(t_fmt *fmt, int num)
{
	int	ilen;

	ilen = ft_intlen(num, find_base(fmt->conv));
	if (find_base(fmt->conv) == 10 && num < 0)
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

static void		put_paddingandsign(t_fmt *fmt, int num, int ilen)
{
	if (!fmt->opt[2] && (!fmt->opt[1] || fmt->prec != -1))
		print_padding(' ', (fmt->width - ilen));
	if (num >= 0 && fmt->opt[3] && !fmt->opt[4] && find_base(fmt->conv) == 10)
		ft_putchar(' ');
	if (num >= 0 && fmt->opt[4] && find_base(fmt->conv) == 10)
		ft_putchar('+');
	if (num < 0 && find_base(fmt->conv) == 10)
		ft_putchar('-');
	if (!fmt->opt[2] && fmt->opt[1] && fmt->prec == -1)
		print_padding('0', (fmt->width - ilen));
}

int				print_int(t_fmt *fmt, long long num)
{
	int ilen;

	ilen = ft_intlen(num, find_base(fmt->conv));
	if (fmt->prec > ilen)
		ilen = fmt->prec;
	if (find_base(fmt->conv) == 10 &&
	(num < 0 || (num >= 0 && fmt->opt[3]) || (num >= 0 && fmt->opt[4])))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt->prec != -1)
		print_padding('0', (fmt->prec - ft_intlen(num, find_base(fmt->conv))));
	if (fmt->length == 'l' || fmt->length == ('l' + 'l'))
		ft_putlong_base(num, find_base(fmt->conv), find_case(fmt->conv));
	else
		ft_putnbr_base(num, find_base(fmt->conv), find_case(fmt->conv));
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - ilen));
	return (printed_chars(fmt, num));
}
