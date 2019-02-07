/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_options.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:05:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/07 12:14:17 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_options(const char **format, t_fmt *fmt)
{
	int	i;
	
	i = 0;
	while (is_flag(**format))
	{
		fmt->opt[i] = **format;
		(*format)++;
		i++;
	}
}
