/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_unsigned.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 13:43:34 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 14:11:23 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_unsigned(char c)
{
	if (c == 'u' || c == 'U')
		return (1);
	if (c == 'o' || c == 'O')
		return (1);
	return (0);
}
