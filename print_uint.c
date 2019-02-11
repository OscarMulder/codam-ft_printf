/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_uint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 14:22:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printed_chars(t_fmt *fmt, int num)
{
	int	ilen;

	ilen = ft_uintlen(num, find_base(fmt->conv));
	if (fmt->opt[0] && (fmt->conv == 'x' || fmt->conv == 'X') && num != 0)
		ilen += 2;
	if (fmt->prec > ilen || fmt->width > ilen)
	{
		if (fmt->prec > fmt->width)
			ilen = fmt->prec;
		else
			ilen = fmt->width;
	}
	return (ilen);
}

static void		put_paddingandsign(t_fmt *fmt, unsigned int num, int ilen)
{
	if (!fmt->opt[2] && (!fmt->opt[1] || fmt->prec != -1))
	{
		if (fmt->opt[0] && (fmt->conv == 'x' || fmt->conv == 'X') && num != 0)
		{
			print_padding(' ', (fmt->width - ilen) - 2);
			print_prehex(fmt->opt[0], fmt->conv);
		}
		else
			print_padding(' ', (fmt->width - ilen));
	}
	if (!fmt->opt[2] && fmt->opt[1] && fmt->prec == -1)
	{
		if (fmt->opt[0] && (fmt->conv == 'x' || fmt->conv == 'X') && num != 0)
		{
			print_prehex(fmt->opt[0], fmt->conv);			
			print_padding('0', (fmt->width - ilen) - 2);
		}
		else
			print_padding('0', (fmt->width - ilen));
	}
}

static void		put_backpadding(t_fmt *fmt, unsigned int num, int ilen)
{
	if (fmt->opt[2])
	{
		if (fmt->opt[0] && (fmt->conv == 'x' || fmt->conv == 'X') && num != 0)
			print_padding(' ', (fmt->width - ilen) - 2);
		else
			print_padding(' ', (fmt->width - ilen));
	}
}

int				print_uint(t_fmt *fmt, unsigned int num)
{
	int ilen;

	ilen = ft_uintlen(num, find_base(fmt->conv));
	if (fmt->prec > ilen)
		ilen = fmt->prec;
	put_paddingandsign(fmt, num, ilen);
	if (fmt->prec != -1)
		print_padding('0', (fmt->prec - ft_uintlen(num, find_base(fmt->conv))));
	if (fmt->opt[2])
		print_prehex(fmt->opt[0], fmt->conv);
	ft_putunbr_base(num, find_base(fmt->conv), find_case(fmt->conv));
	put_backpadding(fmt, num, ilen);
	return (printed_chars(fmt, num));
}
