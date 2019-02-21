/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_upaddingandsign.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:06:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:53:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_upaddingandsign(t_fmt fmt, unsigned long long num, int ilen)
{
	if (!fmt.MIN && (!fmt.ZERO || fmt.prec != -1))
	{
		if (fmt.HASH && is_hex(fmt.conv, fmt.length) && (num != 0 || fmt.conv == 'p'))
		{
			print_padding(' ', (fmt.width - ilen) - 2);
			print_prehex(fmt);
		}
		else
			print_padding(' ', (fmt.width - ilen));
	}
	if (num == 0 && fmt.prec == 0 && fmt.width != -1)
		ft_putchar(' ');
	if (!fmt.MIN && fmt.ZERO && fmt.prec == -1)
	{
		if (fmt.HASH && is_hex(fmt.conv, fmt.length) && (num != 0 || fmt.conv == 'p'))
		{
			print_prehex(fmt);
			print_padding('0', (fmt.width - ilen) - 2);
		}
		else
			print_padding('0', (fmt.width - ilen));
	}
}
