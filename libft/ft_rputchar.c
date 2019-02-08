/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rputchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:18:32 by omulder        #+#    #+#                */
/*   Updated: 2019/02/08 13:21:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_rputchar(int c)
{
	char uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
	return (1);
}
