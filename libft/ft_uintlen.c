/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uintlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: omulder <omulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:21:44 by omulder        #+#    #+#                */
/*   Updated: 2019/02/11 14:11:46 by omulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_uintlen(unsigned int n, int base)
{
	int					len;

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
