/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 12:42:35 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 21:13:31 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

static int 		round_expo(double expo, int prec)
{
	int cpy;

	cpy = expo * ft_pow(10, prec + 1);
	if (cpy < 0)
		cpy = -cpy;
	if (cpy % 10 >= 5)
	{
		return (((cpy / 10) + 1));
	}
	return ((cpy / 10));
}

int				print_double(t_fmt fmt, double num)
{
	long long	n;
	int			prec;
	int			neg;
	int 		ret;

	prec = fmt.prec;
	ret = 0;
	if (fmt.prec == -1)
		prec = 6;
	n = (long long)num;
	num = (double)n - num;
	if (prec != 0 && prec != -1)
		fmt.width = (fmt.width - fmt.prec - 1);
	fmt.prec = -1;
	fmt.conv = 'd';
	ret += print_long(fmt, n);
	if (prec != 0)
		ret += ft_putchar('.');
	neg = 0;
	if (n < 0)
		neg = 1;
	num = round_expo(num, prec);
	if (num < 0)
		num = -num;
	fmt.width = -1;
	fmt.prec = prec;
	if (prec != 0)
		ret += print_long(fmt, num);
	return (ret);
}
