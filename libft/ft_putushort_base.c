/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putushort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:55:10 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 13:04:02 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putushort_base(unsigned short n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;

	if (up)
		ptr = upc;
	else
		ptr = low;
	if (n > (unsigned short)(base - 1))
		ft_putushort_base(n / base, base, up);
	ft_putchar(ptr[(n % base)]);
}
