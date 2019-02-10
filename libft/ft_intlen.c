/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 20:21:26 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(long long n, int base)
{
	int					len;
	unsigned long long	num;

	num = (unsigned long long)n;
	len = 1;
	if (num != 0)
		len--;
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
