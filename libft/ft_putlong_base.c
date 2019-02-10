/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlong_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:36:09 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 20:05:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putlong_base(long long n, int base, int up)
{
	const char			upc[] = "0123456789ABCDEF";
	const char			low[] = "0123456789abcdef";
	const char			*ptr;
	unsigned long long	num;

	if (up)
		ptr = upc;
	else
		ptr = low;
	if (n < 0 && base == 10)
	{
		ft_putchar('-');
		if (n < -(base - 1))
			ft_putlong_base((n / base) * -1, base, up);
		ft_putchar(ptr[(-(n % base))]);
	}
	num = (unsigned long long)n;
	if ((n >= 0 && base == 10) || base != 10)
	{
		if (num > (unsigned long long)(base - 1))
			ft_putlong_base(num / base, base, up);
		ft_putchar(ptr[(num % base)]);
	}
}
