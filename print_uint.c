/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_uint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:29:02 by omulder        #+#    #+#                */
/*   Updated: 2019/02/18 14:44:08 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_uint(t_fmt fmt, unsigned int num)
{
	int ilen;

	ilen = ft_uintlen(num, find_base(fmt.conv));
	if (fmt.prec > ilen)
		ilen = fmt.prec;
	put_upaddingandsign(fmt, num, ilen);
	if (fmt.prec != -1)
		print_padding('0', (fmt.prec - ft_uintlen(num, find_base(fmt.conv))));
	if (fmt.opt[2])
		print_prehex(fmt.opt[0], fmt.conv);
	ft_putunbr_base(num, find_base(fmt.conv), find_case(fmt.conv));
	put_backpadding(fmt, num, ilen);
	return (printed_uchars(fmt, num));
}
