/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 12:42:35 by omulder        #+#    #+#                */
/*   Updated: 2019/02/27 13:14:42 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

static long long	round_expo(double expo, int prec)
{
	long long cpy;

	cpy = expo * ft_pow(10, prec + 1);
	if (cpy < 0)
		cpy = -cpy;
	if (cpy % 10 >= 5)
	{
		return (((cpy / 10) + 1));
	}
	return ((cpy / 10));
}

static long long 	round_num(long long num, double expo)
{
	long long cpy;

	cpy = expo * ft_pow(10, 1);
	if (cpy < 0)
		cpy = -cpy;
	if (cpy % 10 >= 5)
	{
		if (num > 0)
			return (num + 1);
		else
			return (num - 1);	
	}
	return (num);
}

static int		check_special(t_fmt fmt, double num)
{
	if (num == (1.0/0.0))
	{
		fmt.conv = 's';
		return (print_charp(fmt, "inf"));
	}
	else if (num == (-1.0/0.0))
	{
		fmt.conv = 's';
		return (print_charp(fmt, "-inf"));
	}
	else if (num != num)
	{
		fmt.conv = 's';
		return (print_charp(fmt, "nan"));
	}
	return (-1);
}

int				is_negzero(double num)
{
	if (num == 0 && 1 / num == (-1.0/0.0))
		return (1);
	return (0);
}

int				print_double(t_fmt fmt, double num)
{
	long long	n;
	long long	ex;
	int			ret;
	int			neg;
	t_fmt		copy;

	ret = check_special(fmt, num);
	neg = is_negzero(num);
	if (ret != -1)
		return (ret);
	ret = 0;
	if (fmt.prec == -1)
		fmt.prec = 6;
	copy = copy_fmt(fmt);
	n = (long long)num;
	num = (double)n - num;
	if (copy.prec != 0 && copy.prec != -1)
		fmt.width = (fmt.width - fmt.prec - 1);
	fmt.prec = -1;
	fmt.conv = 'D';
	if (fmt.MIN)
	{
		fmt.MIN = 0;
		fmt.width = 0;
	}
	if (fmt.width > 1)
		fmt.width--;
	if (copy.prec == 0)
		n = round_num(n, num);
	if (neg)
		fmt.PLUS = -1;
	ret += print_signed(fmt, n);
	if (copy.prec != 0 || fmt.HASH)
		ret += ft_putchar('.');
	ex = round_expo(num, copy.prec);
	if (ex < 0)
		ex = -ex;
	fmt.width = -1;
	fmt.SPACE = 0;
	fmt.MIN = copy.MIN;
	if (fmt.MIN)
		fmt.width = copy.width - ret;
	fmt.PLUS = 0;
	fmt.prec = copy.prec;
	fmt.HASH = 0;
	if (fmt.prec != 0 || (fmt.MIN && fmt.width > 0))
		ret += print_signed(fmt, ex);
	return (ret);
}
