/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_uchars.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:00:06 by omulder        #+#    #+#                */
/*   Updated: 2019/02/19 16:45:59 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_uchars(t_fmt fmt, unsigned long long num)
{
	int	ilen;

	ilen = ft_ulonglen(num, find_base(fmt.conv));
	if (fmt.opt[0] && is_hex(fmt.conv, fmt.length) &&
	(num != 0 || fmt.conv == 'p'))
		ilen += 2;
	if (fmt.prec > ilen || fmt.width > ilen)
	{
		if (fmt.prec > fmt.width)
			ilen = fmt.prec;
		else
			ilen = fmt.width;
	}
	return (ilen);
}
