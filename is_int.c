/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_int.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:50:19 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 13:50:35 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_int(char c)
{
	if (c == 'd' || c == 'i' || c == 'o')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
