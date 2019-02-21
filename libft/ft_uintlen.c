/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uintlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/21 12:03:02 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_uintlen(unsigned long long n, int base)
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
