/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_width.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:04:30 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:53:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	find_width(const char **format, t_fmt fmt, va_list ap)
{
	while (is_flag(**format))
		(*format)++;
	if (ft_isdigit(**format) || **format == '*')
	{
		if (ft_isdigit(**format))
			fmt.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		if (**format == '*')
		{
			fmt.width = va_arg(ap, int);
			if (fmt.width < 0)
			{
				fmt.MIN = 1;
				fmt.width = ft_abs(fmt.width);
			}
		}
		while (**format == '*')
			(*format)++;
		if (ft_isdigit(**format))
			fmt.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	return (fmt);
}
