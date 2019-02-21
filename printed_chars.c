/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_chars.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:58:28 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:45:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_chars(t_fmt fmt, long long num)
{
	int	ilen;

	ilen = ft_longlen(num, find_base(fmt));
	if (is_hex(fmt.conv, fmt.length) && num < 0 &&
	!is_long(fmt.conv, fmt.length))
		ilen = ft_intlen(num, find_base(fmt));
	if (find_base(fmt) == 10 && num < 0)
		ilen++;
	if (fmt.prec == 0 && num == 0)
		ilen = 0;
	if (fmt.opt[0] && is_hex(fmt.conv, fmt.length) &&
	(num != 0 || fmt.conv == 'p'))
		ilen += 2;
	if (fmt.prec > ilen || fmt.width > ilen)
	{
		if (fmt.prec > fmt.width && num >= 0)
		{
			ilen = fmt.prec;
			if (fmt.opt[0] && is_hex(fmt.conv, fmt.length) &&
			(num != 0 || fmt.conv == 'p'))
				ilen += 2;
		}
		else if (fmt.prec >= fmt.width && num < 0 &&
		find_base(fmt) == 10)
			ilen = fmt.prec + 1;
		else
			ilen = fmt.width;
	}
	if (fmt.width <= ft_longlen(num, find_base(fmt)) &&
	num >= 0 && (fmt.opt[3] || fmt.opt[4]) && find_base(fmt) == 10)
		ilen++;
	return (ilen);
}
