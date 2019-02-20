/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ulong.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:06:33 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 14:20:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_ulong(t_fmt fmt, unsigned long long num)
{
	int ilen;

	ilen = ft_ulonglen(num, find_base(fmt.conv));
	if (fmt.opt[0] && (fmt.conv == 'o' || fmt.conv == 'O') && fmt.prec < (ilen + 1))
	{
		if (num == 0)
			ilen--;
		fmt.prec = ilen + 1;
	}
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	put_upaddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
	{
		print_padding('0', (fmt.prec -
		ft_ulonglen(num, find_base(fmt.conv))));
	}
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	if (!(fmt.prec == 0 && num == 0))
		ft_putulong_base(num, find_base(fmt.conv), find_case(fmt.conv));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
