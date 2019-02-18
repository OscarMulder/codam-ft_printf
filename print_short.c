/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_short.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 14:33:59 by omulder        #+#    #+#                */
/*   Updated: 2019/02/18 14:44:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_short(t_fmt fmt, short num)
{
	int ilen;

	ilen = ft_longlen(num, find_base(fmt.conv));
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	if (find_base(fmt.conv) == 10 &&
	(num < 0 || (num >= 0 && fmt.opt[3]) || (num >= 0 && fmt.opt[4])))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_longlen(num, find_base(fmt.conv))));
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	if (fmt.prec != 0)
	{
		if (find_base(fmt.conv) == 8)
			ft_putchar('0');
		ft_putshort(num);
	}
	put_backpadding(fmt, num, ilen);
	return (printed_chars(fmt, num));
}
