/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuchar_base.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 13:33:12 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 11:39:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuchar_base(unsigned long long n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;
	unsigned char	num;

	num = (unsigned char)n;
	if (up)
		ptr = upc;
	else
		ptr = low;
	if (num > (unsigned char)(base - 1))
		ft_putuchar_base(num / base, base, up);
	ft_putchar(ptr[(num % base)]);
}
