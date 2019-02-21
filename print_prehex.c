/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_prehex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:41:39 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:51:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_prehex(t_fmt fmt)
{
	int		hash;
	char	c;

	hash = fmt.HASH;
	c = fmt.conv;
	if (hash)
	{
		if (c == 'X')
		{
			ft_putstr("0X");
			return (1);
		}
		else if (c == 'x' || c == 'p')
		{
			ft_putstr("0x");
			return (1);
		}
	}
	return (0);
}
