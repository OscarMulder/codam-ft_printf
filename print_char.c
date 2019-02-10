/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 14:46:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 10:27:47 by omulder       ########   odam.nl         */
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

int			print_char(t_fmt *fmt, int c)
{
	put_padding(fmt);
	ft_putchar(c);
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - 1));
	if (fmt->width > 1)
		return (fmt->width);
	return (1);
}
