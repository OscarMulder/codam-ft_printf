/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_options.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:05:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 17:23:54 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_options(const char **format, t_fmt *fmt)
{
	while (is_flag(**format))
	{
		if (**format == '#')
			fmt->opt[0] = 1;
		if (**format == '0')
			fmt->opt[1] = 1;
		if (**format == '-')
			fmt->opt[2] = 1;
		if (**format == ' ')
			fmt->opt[3] = 1;
		if (**format == '+')
			fmt->opt[4] = 1;
		if (**format == '\'')
			fmt->opt[5] = 1;
		(*format)++;
	}
}
