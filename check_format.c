/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:01:23 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:01:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*check_format(const char **format)
{
	t_fmt	*fmt;

	if (**format == '%')
	{
		ft_putchar('%');
		return (NULL);
	}
	fmt = new_fmt();
	find_options(format, fmt);
	find_width(format, fmt);
	find_precision(format, fmt);
	find_length(format, fmt);
	find_conversion(format, fmt);
	if (!fmt->conv)
	{
		free(fmt);
		return (NULL);
	}
	return (fmt);
}
