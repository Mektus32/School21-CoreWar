/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:55:18 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/12 16:59:44 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_get_argc(char *b2, t_cor *cor, t_carr *tmp, int f_err)
{
	unsigned char	t_reg;
	unsigned char	t_reg_2;
	unsigned char	t_reg_3;

	if (b2[0] == 0 && b2[1] == 1)
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[0] - 2 * b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		t_reg_2 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[2] - 2 * b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[4] - 2 * b2[5];
	if (tmp->i == 5 && (!f_err) && val_reg(t_reg) && val_reg(t_reg_2) &&
		val_reg(t_reg_3))
	{
		tmp->reg[t_reg_3 - 1] = tmp->reg[t_reg - 1] + tmp->reg[t_reg_2 - 1];
		tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
		if (cor->v_print[2] == 1)
			ft_printf("P %4d | add r%d r%d r%d\n",
					tmp->num, t_reg, t_reg_2, t_reg_3);
	}
}

void			ft_add(t_cor *cor, t_carr *tmp)
{
	char			*b2;
	int				f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	ft_get_argc(b2, cor, tmp, f_err);
	free(b2);
}
