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

static void			write_add(t_carr *tmp, unsigned char t_reg,
		unsigned char t_reg_2, unsigned char t_reg_3, t_cor *cor)
{
	tmp->reg[t_reg_3 - 1] = tmp->reg[t_reg - 1] +
							tmp->reg[t_reg_2 - 1];
	tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
	if (cor->v_print[2])
	    ft_printf("P    %d | add r%d r%d r%d\n", tmp->id_par, t_reg, t_reg_2, t_reg_3);
}

void				ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	unsigned char	t_reg_2;
	unsigned char	t_reg_3;
	char			*b2;
	int				f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
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
	if (tmp->i == 5 && (!f_err) && VAL_REG(t_reg) && VAL_REG(t_reg_2) &&
	VAL_REG(t_reg_3))
		write_add(tmp, t_reg, t_reg_2, t_reg_3, cor);
	free(b2);
}
