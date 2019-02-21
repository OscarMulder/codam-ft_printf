/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ushort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:59:25 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:45:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_ushort(t_fmt fmt, unsigned long long num)
{
	int ilen;

	ilen = ft_ushortlen(num, find_base(fmt));
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	if (find_base(fmt) == 10 && (fmt.opt[3] || fmt.opt[4]))
		ilen++;
	put_upaddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_longlen(num, find_base(fmt))));
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	ft_putushort_base(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
