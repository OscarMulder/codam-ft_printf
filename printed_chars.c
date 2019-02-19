/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_chars.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:58:28 by omulder        #+#    #+#                */
/*   Updated: 2019/02/19 16:45:55 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_chars(t_fmt fmt, long long num)
{
	int	ilen;

	ilen = ft_longlen(num, find_base(fmt.conv));
	if (is_hex(fmt.conv, fmt.length) && num < 0 &&
	!is_long(fmt.conv, fmt.length))
		ilen = ft_intlen(num, find_base(fmt.conv));
	if (fmt.opt[0] && is_hex(fmt.conv, fmt.length) &&
	(num != 0 || fmt.conv == 'p'))
		ilen += 2;
	if (find_base(fmt.conv) == 10 && num < 0)
		ilen++;
	if (fmt.prec == 0 && num == 0)
		ilen = 0;
	if (fmt.prec > ilen || fmt.width > ilen)
	{
		if (fmt.prec > fmt.width && num >= 0)
			ilen = fmt.prec;
		else if (fmt.prec >= fmt.width && num < 0 &&
		find_base(fmt.conv) == 10)
			ilen = fmt.prec + 1;
		else
			ilen = fmt.width;
	}
	if (fmt.width <= ft_longlen(num, find_base(fmt.conv)) &&
	num >= 0 && (fmt.opt[3] || fmt.opt[4]))
		ilen++;
	return (ilen);
}
