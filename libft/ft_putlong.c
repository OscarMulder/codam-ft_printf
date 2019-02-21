/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlong.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 14:01:23 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 14:23:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(long long n)
{
	if (n < 0)
	{
		if (n < -9)
			ft_putlong((n / 10) * -1);
		ft_putchar(-(n % 10) + '0');
	}
	else
	{
		if (n > 9)
			ft_putlong(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
