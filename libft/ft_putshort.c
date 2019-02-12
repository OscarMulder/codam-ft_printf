/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putshort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 20:03:36 by omulder        #+#    #+#                */
/*   Updated: 2019/02/12 14:21:08 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putshort(int c)
{
	char cs;

	cs = (signed char)c;
	if (cs < 0)
	{
		if (cs < -9)
			ft_putshort((cs / 10) * -1);
		ft_putchar(-(cs % 10) + '0');
	}
	else
	{
		if (cs > 9)
			ft_putshort(cs / 10);
		ft_putchar((cs % 10) + '0');
	}
}
