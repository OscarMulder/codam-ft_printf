/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 12:42:35 by omulder        #+#    #+#                */
/*   Updated: 2019/02/16 15:15:12 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int		print_double(t_fmt *fmt, double num)
{
	int		n;
	int		prec;

	prec = fmt->prec;
	if (fmt->prec == -1)
		prec = 6;
	n = (int)num;
	num = (double)n - num;
	if (prec != 0 && prec != -1)
		fmt->width = (fmt->width - fmt->prec - 1);
	fmt->prec = -1;
	fmt->conv = 'd';
	print_int(fmt, n);
	if (prec != 0)
		ft_putchar('.');
	num = num * ft_pow(10, prec);
	if (num < 0)
		num = -num;
	fmt->width = -1;
	fmt->prec = prec;
	if (prec != 0)
		print_int(fmt, num);
	return (0);
}
