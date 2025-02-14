/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wstrlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:44:47 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 14:38:03 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_charsize(unsigned int c)
{
	if (c <= 0x7f)
		return (1);
	else if (c > 0x7f && c <= 0x7FF)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF)
		return (3);
	else if (c > 0xFFFF && c <= 0x001FFFFF)
		return (4);
	return (1);
}

size_t	ft_wstrlen(const wchar_t *s, int prec)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (prec != -1)
		{
			if (len + ft_charsize(s[i]) <= (size_t)prec)
				len += ft_charsize(s[i]);
		}
		else
			len += ft_charsize(s[i]);
		i++;
	}
	return (len);
}
