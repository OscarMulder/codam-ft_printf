/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_precision.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:03:11 by omulder        #+#    #+#                */
/*   Updated: 2019/02/18 14:38:19 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	find_precision(const char **format, t_fmt fmt)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
			fmt.prec = ft_atoi(*format);
		else
			fmt.prec = 0;
		while (ft_isdigit(**format))
			(*format)++;
	}
	return (fmt);
}
