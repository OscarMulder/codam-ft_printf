/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ucharlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 13:30:58 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:05:13 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_ucharlen(unsigned long long n, int base)
{
	int				len;
	unsigned char	num;

	num = (unsigned char)n;
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
