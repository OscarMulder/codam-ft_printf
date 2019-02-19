/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_base.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:40:23 by omulder        #+#    #+#                */
/*   Updated: 2019/02/19 16:26:47 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'p')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	return (10);
}
