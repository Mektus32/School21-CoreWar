/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:44:18 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/12 17:00:10 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static short		len_k(t_cor *cor, t_carr *tmp, char *b2, int *f_err)
{
	short			k;
	unsigned char	t_reg;

	k = 0;
	k += arg_2(b2, tmp, cor, f_err);
	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg = read_byte_1(cor->code, (tmp->cur + tmp->i++));
		if (VAL_REG(t_reg))
			k += (short)tmp->reg[(int)t_reg - 1];
		else
			*f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{
		k += read_byte_2(cor->code, tmp->cur + tmp->i);
		tmp->i += 2;
	}
	else
	{
		tmp->i += 2 * b2[2];
		*f_err = 1;
	}
	return (k);
}

void				ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char	t_reg;
	char			*b2;
	int				f_err;
	short			k;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	k = len_k(cor, tmp, b2, &f_err);
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (f_err == 0 && (VAL_REG(t_reg)))
		{
		    k = mem_size(k);
			tmp->reg[(int)t_reg - 1] =
					read_byte_4(cor->code, tmp->cur +
					k % (IDX_MOD - l * IDX_MOD + 1 * l));
			if (l)
				tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
		}
	}
	else
		tmp->i += 2 * b2[4];
	free(b2);
}
