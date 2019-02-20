/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putwstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 11:39:45 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 15:15:33 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t const *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_uni(s[i]);
		i++;
	}
}
