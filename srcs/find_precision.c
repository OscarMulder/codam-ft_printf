/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_precision.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:03:11 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 20:52:58 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	find_precision(const char **format, t_fmt fmt, va_list ap)
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
		if (**format == '*')
		{
			fmt.prec = va_arg(ap, int);
			if (fmt.prec < 0)
				fmt.prec = -1;
			(*format)++;
		}
	}
	return (fmt);
}
