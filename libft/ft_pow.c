/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:24:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 13:31:55 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int power)
{
	int		i;
	int		res;

	i = -1;
	res = 1;
	if (nbr == 0 && power == 0)
		return (1);
	else if (nbr == 0 && power != 0)
		return (0);
	while (++i < power)
		res *= nbr;
	return (res);
}
