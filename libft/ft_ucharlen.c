/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ucharlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 13:30:58 by omulder        #+#    #+#                */
/*   Updated: 2019/02/20 13:31:14 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_ucharlen(unsigned char n, int base)
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
