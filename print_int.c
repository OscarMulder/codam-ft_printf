/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:45:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_int(t_fmt fmt, int num)
{
	int ilen;

	ilen = ft_intlen(num, find_base(fmt));
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	if (find_base(fmt) == 10 &&
	(num < 0 || (num >= 0 && fmt.opt[3]) || (num >= 0 && fmt.opt[4])))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_intlen(num, find_base(fmt))));
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	if (!(fmt.prec == 0 && num == 0))
		ft_putnbr_base(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_chars(fmt, num));
}
