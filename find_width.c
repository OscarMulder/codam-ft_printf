/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_width.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:04:30 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:04:43 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_width(const char **format, t_fmt *fmt)
{
	if (ft_isdigit(**format))
	{
		fmt->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}
