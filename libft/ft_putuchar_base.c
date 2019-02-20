/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuchar_base.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 13:33:12 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 13:36:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuchar_base(unsigned char n, int base, int up)
{
	const char		upc[] = "0123456789ABCDEF";
	const char		low[] = "0123456789abcdef";
	const char		*ptr;

	if (up)
		ptr = upc;
	else
		ptr = low;
	if (n > (unsigned char)(base - 1))
		ft_putuchar_base(n / base, base, up);
	ft_putchar(ptr[(n % base)]);
}
