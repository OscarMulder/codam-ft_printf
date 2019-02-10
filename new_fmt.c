/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_fmt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 12:05:31 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 10:27:34 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*new_fmt(void)
{
	int		i;
	t_fmt	*fmt;

	fmt = (t_fmt*)malloc(sizeof(fmt));
	i = 0;
	while (i < 6)
	{
		fmt->opt[i] = 0;
		i++;
	}
	fmt->width = -1;
	fmt->prec = -1;
	fmt->length = -1;
	fmt->conv = '\0';
	return (fmt);
}
