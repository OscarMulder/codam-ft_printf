/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_options.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:05:01 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 16:31:41 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fmt	set_option(char c, t_fmt fmt)
{
	if (c == '#')
		fmt.HASH = 1;
	if (c == '0')
		fmt.ZERO = 1;
	if (c == '-')
		fmt.MIN = 1;
	if (c == ' ')
		fmt.SPACE = 1;
	if (c == '+')
		fmt.PLUS = 1;
	if (c == '\'')
		fmt.APST = 1;
	return (fmt);
}

t_fmt		find_options(const char **format, t_fmt fmt)
{
	const char *tmp;

	tmp = *format;
	while (*tmp && !is_conversion(*tmp))
	{
		if (!ft_isdigit(*tmp) || *tmp == '0')
		{
			fmt = set_option(*tmp, fmt);
		}
		while (ft_isdigit(*tmp))
			tmp++;
		if (is_flag(*tmp))
		{
			if (*tmp != '0')
				fmt = set_option(*tmp, fmt);
		}
		if (*tmp && !is_conversion(*tmp))
			tmp++;
	}
	return (fmt);
}
