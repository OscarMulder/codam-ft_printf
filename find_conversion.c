/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_conversion.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:02:07 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 13:19:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_conversion(const char **format, t_fmt *fmt)
{
	while (is_option(**format) && !is_conversion(**format))
		(*format)++;
	if (is_conversion(**format))
	{
		fmt->conv = **format;
		(*format)++;
	}
}
