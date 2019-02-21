/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putcharsign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:07:22 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 14:02:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharsign(long long c)
{
	char cs;

	cs = (char)c;
	if (cs < 0)
	{
		if (cs < -9)
			ft_putcharsign((cs / 10) * -1);
		ft_putchar(-(cs % 10) + '0');
	}
	else
	{
		if (cs > 9)
			ft_putcharsign(cs / 10);
		ft_putchar((cs % 10) + '0');
	}
}
