/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_double.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:50:43 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 10:25:09 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_double(char c)
{
	if (c == 'e' || c == 'E')
		return (1);
	if (c == 'f' || c == 'F')
		return (1);
	if (c == 'g' || c == 'G')
		return (1);
	if (c == 'a' || c == 'A')
		return (1);
	return (0);
}
