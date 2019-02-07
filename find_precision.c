/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_precision.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:03:11 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:03:44 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_precision(const char **format, t_fmt *fmt)
{
	if (**format == '.')
	{
		(*format)++;
		fmt->prec = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}
