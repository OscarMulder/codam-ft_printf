/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 20:30:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/28 14:58:19 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
