/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_length.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:02:41 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:02:52 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_length(const char **format, t_fmt *fmt)
{
	while (is_length(**format))
	{
		if (fmt->length == -1)
			fmt->length = **format;
		else
			fmt->length += **format;
		(*format)++;
	}
}
