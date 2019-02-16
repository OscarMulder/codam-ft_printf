/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:29:06 by omulder        #+#    #+#                */
/*   Updated: 2019/02/14 15:34:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_pow(double x, double y)
{
	int i;
	int f;

	i = 1;
	f = x;
	while (i < y)
	{
		x *= f;
		i++;
	}
	return (x);
}
