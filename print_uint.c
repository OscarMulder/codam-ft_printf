/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_uint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:53:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_uint(t_fmt fmt, unsigned int num)
{
	int ilen;

	ilen = ft_uintlen(num, find_base(fmt));
	if (fmt.HASH && (fmt.conv == 'o' || fmt.conv == 'O') && fmt.prec < (ilen + 1))
	{
		if (num == 0)
			ilen--;
		fmt.prec = ilen + 1;
	}
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	put_upaddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_uintlen(num, find_base(fmt))));
	if (fmt.MIN)
		print_prehex(fmt);
	if (!(fmt.prec == 0 && num == 0))
		ft_putunbr_base(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
