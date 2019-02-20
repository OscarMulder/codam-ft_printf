/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_ushort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:56:45 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 13:23:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_ushort(t_fmt fmt)
{
	char	c;
	int 	l;

	c = fmt.conv;
	l = fmt.length;
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
	{
		if (l == 'h')
			return (1);
		return (0);
	}
	return (0);
}
