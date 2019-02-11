/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:36:09 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 14:25:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;
	unsigned int	num;

	if (up)
		ptr = upc;
	else
		ptr = low;
	if (n < 0 && base == 10)
	{
		if (n < -(base - 1))
			ft_putnbr_base((n / base) * -1, base, up);
		ft_putchar(ptr[(-(n % base))]);
	}
	num = (unsigned int)n;
	if ((n >= 0 && base == 10) || base != 10)
	{
		if (num > (unsigned int)(base - 1))
			ft_putnbr_base(num / base, base, up);
		ft_putchar(ptr[(num % base)]);
	}
}
