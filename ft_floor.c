/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:35:11 by omulder        #+#    #+#                */
/*   Updated: 2019/02/14 15:40:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_floor(double x)
{
	if (x > 0)
		return ((int)x);
	if (x < 0)
		return ((int)x - 1);
	return (0);
}
