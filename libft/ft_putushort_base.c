/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putushort_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:55:10 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 11:30:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putushort_base(unsigned long long n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;
	unsigned short	num;

	num = (unsigned short)n;
	if (up)
		ptr = upc;
	else
		ptr = low;
	if (num > (unsigned short)(base - 1))
		ft_putushort_base(num / base, base, up);
	ft_putchar(ptr[(num % base)]);
}
