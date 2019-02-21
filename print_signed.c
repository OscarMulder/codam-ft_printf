/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_signed.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 12:54:56 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 15:04:51 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	typecast(t_fmt fmt, long long num)
{
	if (is_charsign(fmt))
		return ((char)num);
	if (is_short(fmt))
		return ((short)num);
	if (is_int(fmt))
		return ((int)num);
	if (is_long(fmt))
		return (num);
	return (num);
}

int					print_signed(t_fmt fmt, long long num)
{
	int ilen;

	num = typecast(fmt, num);
	ilen = ft_longlen(num);
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	if (num < 0 || (num >= 0 && fmt.SPACE) || (num >= 0 && fmt.PLUS))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_longlen(num)));
	if (!(fmt.prec == 0 && num == 0))
		ft_putlong(num);
	put_backpadding(fmt, num, ilen);
	return (printed_chars(fmt, num));
}
