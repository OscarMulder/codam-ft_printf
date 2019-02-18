/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printed_uchars.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:00:06 by omulder        #+#    #+#                */
/*   Updated: 2019/02/18 14:47:25 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printed_uchars(t_fmt fmt, unsigned long long num)
{
	int	ilen;

	ilen = ft_ulonglen(num, find_base(fmt.conv));
	if (fmt.opt[0] && (fmt.conv == 'x' || fmt.conv == 'X') && num != 0)
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
