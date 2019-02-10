/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:53:49 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 10:20:42 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int n)
{
	char	*num;
	int		tmp;
	int		i;

	i = (ft_intlen(n, 10) - 1);
	tmp = n;
	num = (char*)malloc(sizeof(char) * ft_intlen(n, 10) + 1);
	if (num == NULL)
		return (NULL);
	num[i + 1] = '\0';
	if (n == 0)
		num[i] = '0';
	while (tmp != 0)
	{
		if (tmp > 0)
			num[i] = ((tmp % 10) + '0');
		else
			num[i] = (-(tmp % 10) + '0');
		i--;
		tmp = (tmp / 10);
	}
	if (n < 0)
		num[i] = '-';
	return (num);
}
