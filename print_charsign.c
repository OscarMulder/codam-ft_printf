/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_charsign.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 18:46:23 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 18:51:50 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_padding(t_fmt *fmt)
{
	if (!fmt->opt[1] && !fmt->opt[2])
		print_padding(' ', (fmt->width - 1));
	if (fmt->opt[1] && !fmt->opt[2])
		print_padding('0', (fmt->width - 1));
}

int			print_charsign(t_fmt *fmt, int c)
{
	put_padding(fmt);
	ft_putcharsign(c);
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - 1));
	if (fmt->width > 1)
		return (fmt->width);
	return (1);
}
