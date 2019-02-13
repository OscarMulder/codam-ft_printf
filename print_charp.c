/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_charp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:14:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/13 13:48:16 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_padding(t_fmt *fmt, int slen)
{
	if (!fmt->opt[2] && (!fmt->opt[1] || fmt->prec != -1))
		print_padding(' ', (fmt->width - slen));
	if (!fmt->opt[2] && fmt->opt[1] && fmt->prec == -1)
		print_padding('0', (fmt->width - slen));
}

int				print_charp(t_fmt *fmt, char *str)
{
	int	slen;

	if (str)
		slen = ft_strlen(str);
	else
		slen = ft_strlen("(null)");
	if (fmt->prec != -1 && fmt->prec < slen)
		slen = fmt->prec;
	put_padding(fmt, slen);
	if (str)
	{
		if (fmt->prec == -1)
			ft_putstr(str);
		else
			ft_putnstr(str, fmt->prec);
	}
	else
		ft_putstr("(null)");
	if (fmt->opt[2])
		print_padding(' ', (fmt->width - slen));
	if (fmt->width > slen)
		slen = fmt->width;
	return (slen);
}
