/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:36:09 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 11:39:53 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_base(unsigned long long n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;
	unsigned int	num;

	num = (unsigned int)n;
	if (up)
		ptr = upc;
	else
		ptr = low;
	if (num > (unsigned int)(base - 1))
		ft_putunbr_base(num / base, base, up);
	ft_putchar(ptr[(num % base)]);
}
