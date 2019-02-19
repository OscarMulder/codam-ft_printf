/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_pointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:11:25 by omulder        #+#    #+#                */
/*   Updated: 2019/02/19 16:28:37 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_pointer(t_fmt fmt, unsigned long long num)
{
	int ret;

	ret = 0;
	fmt.opt[0] = 1;
	return (ret + print_ulong(fmt, num));
}
