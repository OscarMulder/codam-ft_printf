/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 15:14:38 by omulder        #+#    #+#                */
/*   Updated: 2019/02/28 14:58:28 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar(int c)
{
	char ca;

	ca = (char)c;
	write(1, &ca, 1);
	return (1);
}
