/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_conversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:02:07 by omulder        #+#    #+#                */
/*   Updated: 2019/02/19 17:06:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	find_conversion(const char **format, t_fmt fmt)
{
	while (is_option(**format) && !(ft_isalpha(**format) || **format == '%'))
		(*format)++;
	if (ft_isalpha(**format) || **format == '%')
	{
		fmt.conv = **format;
		(*format)++;
	}
	return (fmt);
}
