/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_charsign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 18:50:19 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:14:08 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_charsign(char c, int l)
{
	if (c == 'd' || c == 'i')
	{
		if (l == ('h' + 'h'))
			return (1);
	}
	return (0);
}
