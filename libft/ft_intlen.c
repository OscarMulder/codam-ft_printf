/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 14:47:28 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long long n, int base)
{
	int					len;
	unsigned int		num;

	if (n < 0 && base == 10)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
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
