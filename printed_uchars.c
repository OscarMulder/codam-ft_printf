/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_uchars.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:00:06 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 17:16:20 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_uchars(t_fmt fmt, unsigned long long num)
{
	int	ilen;

	ilen = ft_ulonglen(num, find_base(fmt));
	if ((fmt.HASH && is_hex(fmt) &&
	num != 0) || fmt.conv == 'p')
		ilen += 2;
	if (fmt.prec == 0 && num == 0 && fmt.conv != 'p')
		ilen = 0;
	if (fmt.prec == 0 && num == 0 && fmt.conv == 'p')
		ilen = 2;
	if (fmt.prec > ilen || fmt.width > ilen)
	{
		if (fmt.prec > fmt.width)
		{
			ilen = fmt.prec;
			if (fmt.HASH && is_hex(fmt) &&
			(num != 0 || fmt.conv == 'p'))
				ilen += 2;
		}
		else
			ilen = fmt.width;
	}
	return (ilen);
}
