/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:03:46 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/23 22:03:47 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_st_write(t_cor *cor, t_carr *tmp, int b2_2)
{
	int				a;
	unsigned char	*p;
	unsigned char	t_ind[IND_SIZE];
	unsigned char	t_reg;
	unsigned char	t_reg_2;

	ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 2));
	if ((int)t_reg > 0 && (int)t_reg < REG_NUMBER)
	{
		a = 0;
		if (b2_2 == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 3));
			a = (IFR8(t_ind)) % IDX_MOD;
			p = inttobyte(tmp->reg[(int) t_reg]);
			ft_memcpy_all(cor->code + (tmp->cur + a) % IDX_MOD, p, 4, 0);
			free(p);
		}
		else
		{
			ft_memcpy_all(&t_reg_2, cor->code, 1, (tmp->cur + 3));
			if ((int) t_reg_2 > 0 && (int) t_reg_2 < REG_NUMBER)
				tmp->reg[(int) t_reg_2] = (int) tmp->reg[(int) t_reg];
		}
	}

}

void	ft_st(t_cor *cor, t_carr *tmp)
{
	char	*b2;
	int		i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if ((b2[2] == 0 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 1))
	{
		if (i == 3)
		{
			ft_st_write(cor, tmp, b2[2]);
			i += (b2[2] == 1) ? 2 : 1;
		}
		else
			i = i + (b2[2] == 0 ? 1 : 2);
	}
	else if (b2[2] == 1 && b2[3] == 0)
		i += 4;
	tmp->i = i;
	free(b2);
}
