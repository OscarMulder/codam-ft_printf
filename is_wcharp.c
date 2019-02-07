/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_wcharp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:52:13 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 13:52:15 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_wcharp(char c, int l)
{
	if (c == 's' && l == 'l')
		return (1);
	if (c == 'S')
		return (1);
	return (0);
}
