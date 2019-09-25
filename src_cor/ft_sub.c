/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:14:15 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/25 21:14:16 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_sub_1(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	unsigned char	t_reg_2;
	unsigned char	t_reg_3;

	ft_memcpy_all(&t_reg, cor->code, 1, (tmp->cur + 2 + 1));
	ft_memcpy_all(&t_reg_2, cor->code, 1, (tmp->cur + 2 + 2));
	ft_memcpy_all(&t_reg_3, cor->code, 1, (tmp->cur + 2 + 3));
	if (((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER) &&
		((int)t_reg_2 > 0 && (int)(t_reg_2) < REG_NUMBER) &&
		((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
	{
		tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] -
									tmp->reg[(int)t_reg_2];
		tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
	}
}

void		ft_sub(t_cor *cor, t_carr *tmp)
{
	char			*b2;
	int				i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		i += 1;
	else
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		i += 1;
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	if (i == 5)
		ft_sub_1(cor, tmp);
	free(b2);
	tmp->i = i;
}
