/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_paddingandsign.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:07:28 by omulder        #+#    #+#                */
/*   Updated: 2019/02/18 14:43:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_paddingandsign(t_fmt fmt, long long num, int ilen)
{
	if (!fmt.opt[2] && (!fmt.opt[1] || fmt.prec != -1))
	{
		if (fmt.opt[0] && (fmt.conv == 'x' || fmt.conv == 'X') && num != 0)
		{
			print_padding(' ', (fmt.width - ilen) - 2);
			print_prehex(fmt.opt[0], fmt.conv);
		}
		else
			print_padding(' ', (fmt.width - ilen));
	}
	if (num >= 0 && fmt.opt[3] && !fmt.opt[4] && find_base(fmt.conv) == 10)
		ft_putchar(' ');
	if (num == 0 && fmt.prec == 0 && fmt.width != -1)
		ft_putchar(' ');
	if (num >= 0 && fmt.opt[4] && find_base(fmt.conv) == 10)
		ft_putchar('+');
	if (num < 0 && find_base(fmt.conv) == 10)
		ft_putchar('-');
	if (!fmt.opt[2] && fmt.opt[1] && fmt.prec == -1)
	{
		if (fmt.opt[0] && (fmt.conv == 'x' || fmt.conv == 'X') && num != 0)
		{
			print_prehex(fmt.opt[0], fmt.conv);
			print_padding('0', (fmt.width - ilen) - 2);
		}
		else
			print_padding('0', (fmt.width - ilen));
	}
}
