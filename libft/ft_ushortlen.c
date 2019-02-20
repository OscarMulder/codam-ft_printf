/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shortlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:59:47 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 13:00:39 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_ushortlen(unsigned short n, int base)
{
	int	len;

	len = 1;
	if (n != 0)
		len--;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
