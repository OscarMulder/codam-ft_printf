/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 20:09:51 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 14:14:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_long(char c, int l)
{
	if (is_int(c))
	{
		if (l == 'l' || l == ('l' + 'l') || l == 'j')
			return (1);
		if (l == 'z')
			return (1);
	}
	if (is_longint(c))
		return (1);
	return (0);
}
