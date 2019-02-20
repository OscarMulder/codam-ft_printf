/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnwstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:40:46 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 15:15:40 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnwstr(wchar_t const *s, size_t len)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	while (s[i] != '\0' && (c + ft_charsize(s[i])) <= len)
	{
		c += ft_putchar_uni(s[i]);
		i++;
	}
}
