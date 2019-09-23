/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:35:55 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/23 21:35:57 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
{
	int				a;
	unsigned char	t_ind[IND_SIZE];
	unsigned char	t_dir[DIR_SIZE];
	unsigned char	t_reg;

	a = 0;
	if (i == 5)
	{
		ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
		a = (l == 1) ? IFR8(t_ind) : (IFR8(t_ind)) % IDX_MOD;
	}
	ft_memcpy(&t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
	ft_memcpy_all(&t_reg, cor->code + (tmp->cur + (i - 1)) % MEM_SIZE, 1);
	if ((int)t_reg > 0 && (int)t_reg < REG_NUMBER)
	{
		tmp->reg[(int)t_reg] = (IFR16(t_dir));
		tmp->carry = (tmp->reg[(int)t_reg] == 0) ? 1 : 0;
	}
	else
		return (1);
}

void	ft_ld(t_cor *cor, t_carr *tmp, int l)
{
	char	*b2;
	int		i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	else if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		if (i == 5 || i == 7)
			ft_ld_write(cor, tmp, i, l);
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	free(b2);
	tmp->i = i;
}
