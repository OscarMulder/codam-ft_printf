/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_escape.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:23:49 by omulder        #+#    #+#                */
/*   Updated: 2019/02/08 13:24:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_escape(const char **format, t_fmt *fmt)
{
	if (**format == '%')
		fmt->conv = '%';
}
