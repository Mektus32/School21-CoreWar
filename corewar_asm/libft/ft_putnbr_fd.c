/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:08 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 16:16:51 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int index;
	int number[20];

	index = -1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			nb = -214748364;
			number[++index] = 8;
		}
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	while (nb / 10 != 0)
	{
		number[++index] = nb % 10;
		nb /= 10;
	}
	number[++index] = nb % 10;
	index++;
	while (index != 0)
		ft_putchar_fd('0' + number[--index], fd);
}
