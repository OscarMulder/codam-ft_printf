/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 14:00:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n)
{
	int num;

	num = (int)n;
	if (num < 0)
	{
		if (num < -9)
			ft_putnbr((num / 10) * -1);
		ft_putchar(-(num % 10) + '0');
	}
	else
	{
		if (num > 9)
			ft_putnbr(num / 10);
		ft_putchar((num % 10) + '0');
	}
}
