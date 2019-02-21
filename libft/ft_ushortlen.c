/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ushortlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:59:47 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 11:29:25 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_ushortlen(unsigned long long n, int base)
{
	int	len;
	unsigned short num;

	num = (unsigned short)n;
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
