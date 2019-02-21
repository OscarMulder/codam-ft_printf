/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_uchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 13:30:19 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:53:57 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_uchar(t_fmt fmt, unsigned char num)
{
	int ilen;

	ilen = ft_ucharlen(num, find_base(fmt));
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	if (find_base(fmt) == 10 &&
	(num < 0 || (num >= 0 && fmt.SPACE) || (num >= 0 && fmt.PLUS)))
		ilen++;
	put_paddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_longlen(num, find_base(fmt))));
	if (fmt.MIN)
		print_prehex(fmt);
	ft_putuchar_base(num, find_base(fmt), find_case(fmt));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
