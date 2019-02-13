/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_long.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:06:33 by omulder        #+#    #+#                */
/*   Updated: 2019/02/12 16:07:43 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_long(t_fmt *fmt, long long num)
{
	int ilen;

	ilen = ft_longlen(num, find_base(fmt->conv));
	if (fmt->prec > ilen)
		ilen = fmt->prec;
	if (find_base(fmt->conv) == 10 &&
	(num < 0 || (num >= 0 && fmt->opt[3]) || (num >= 0 && fmt->opt[4])))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt->prec != -1)
		print_padding('0', (fmt->prec - ft_longlen(num, find_base(fmt->conv))));
	if (fmt->opt[2])
		print_prehex(fmt->opt[0], fmt->conv);
	if (fmt->prec != 0)
	{
		if (find_base(fmt->conv) == 8)
			ft_putchar('0');
		ft_putlong_base(num, find_base(fmt->conv), find_case(fmt->conv));
	}
	put_backpadding(fmt, num, ilen);
	return (printed_chars(fmt, num));
}
