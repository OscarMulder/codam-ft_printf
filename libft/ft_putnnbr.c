/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnnbr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:16:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 14:23:38 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnnbr(int n, int len)
{
	if (len > 0 && n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnnbr((n / 10) * -1, len - 2);
		ft_putchar(-(n % 10) + '0');
	}
	else if (len > 0)
	{
		if (n > 9)
			ft_putnnbr(n / 10, len - 1);
		ft_putchar((n % 10) + '0');
	}
}
