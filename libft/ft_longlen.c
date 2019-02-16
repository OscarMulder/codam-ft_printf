/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:15:08 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:14:47 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_longlen(long long n, int base)
{
	int					len;
	unsigned long long	num;

	if (n < 0 && base == 10)
		num = (unsigned long long)(n * -1);
	else
		num = (unsigned long long)n;
	len = 1;
	if (num != 0)
		len--;
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
