/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putulong_base.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:36:09 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 14:09:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putulong_base(unsigned long long n, int base, int up)
{
	const char			upc[] = "0123456789ABCDEF";
	const char			low[] = "0123456789abcdef";
	const char			*ptr;

	if (up)
		ptr = upc;
	else
		ptr = low;
	if (n > (unsigned long long)(base - 1))
		ft_putulong_base(n / base, base, up);
	ft_putchar(ptr[(n % base)]);
}
