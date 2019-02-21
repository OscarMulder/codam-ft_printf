/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 11:17:53 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:45:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_unsigned(t_fmt fmt, unsigned long long num,
int (*ulen)(unsigned long long, int),
void (*putu)(unsigned long long, int, int))
{
	int ilen;

	ilen = ulen(num, find_base(fmt));
	if (fmt.opt[0] && is_octal(fmt) && fmt.prec < (ilen + 1))
	{
		if (num == 0)
			ilen--;
		fmt.prec = ilen + 1;
	}
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	put_upaddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ulen(num, find_base(fmt))));
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	if (!(fmt.prec == 0 && num == 0))
		putu(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
