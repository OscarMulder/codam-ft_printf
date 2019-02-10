/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/10 11:29:05 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int n, int base)
{
	int				len;
	unsigned int	num;

	num = (unsigned int)n;
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
