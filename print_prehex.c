/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_prehex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 12:41:39 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 13:21:06 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_prehex(int hash, char c)
{
	if (hash)
	{
		if (c == 'X')
		{
			ft_putstr("0X");
			return (1);
		}
		else if (c == 'x')
		{
			ft_putstr("0x");
			return (1);
		}
	}
	return (0);
}
