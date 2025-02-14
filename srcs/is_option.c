/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_option.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 13:13:57 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:14:18 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_option(char c)
{
	if (is_conversion(c))
		return (1);
	if (is_length(c))
		return (1);
	if (ft_isdigit(c))
		return (1);
	if (is_flag(c))
		return (1);
	if (c == '.')
		return (1);
	return (0);
}
