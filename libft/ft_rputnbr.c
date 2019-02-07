/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rputnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/06 20:10:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_rputnbr(int n)
{
	int len;

	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			len = (2 + ft_rputnbr((n / 10) * -1));
		else
			len = 2;
		ft_putchar(-(n % 10) + '0');
	}
	else
	{
		if (n > 9)
			len = (1 + ft_rputnbr(n / 10));
		else
			len = 1;
		ft_putchar((n % 10) + '0');
	}
	return (len);
}
