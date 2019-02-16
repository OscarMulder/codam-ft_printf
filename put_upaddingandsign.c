/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_upaddingandsign.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:06:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:16:40 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_upaddingandsign(t_fmt *fmt, unsigned long long num, int ilen)
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
