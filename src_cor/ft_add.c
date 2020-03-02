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

static unsigned int	arg_dir(char *b2, t_cor *cor, t_carr *tmp)
{
	unsigned int	t_dir;
	short			t_ind;

	t_dir = 0;
	if (b2[1] == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
		t_dir = read_byte_4(cor->code, tmp->cur + idx_mod(t_ind));
	}
	else
	{
		t_dir = read_byte_4(cor->code, tmp->cur + tmp->i);
		tmp->i += 2;
	}
	return (t_dir);
}

int					arg_4(char *b2, t_carr *tmp, t_cor *cor, int *f_err)
{
	unsigned char	t_reg_3;
	unsigned int	t_dir;

	t_dir = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		t_dir = tmp->reg[t_reg_3 - 1];
		if(!(*f_err))
		*f_err = (VAL_REG(t_reg_3)) ? 0 : 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		t_dir = arg_dir(b2, cor, tmp);
		tmp->i += 2;
	}
	else
		*f_err = 1;
	return (t_dir);
}

unsigned int			read_byte_2_int( unsigned char *src, int i)
{
    unsigned int	c_2;

    while (i < 0)
        i = MEM_SIZE + i;
    c_2 = 0;
    c_2 = (c_2 << 8);
    c_2 = c_2 | (unsigned char)src[(i) % MEM_SIZE];
    c_2 = (c_2 << 8);
    c_2 = c_2 | (unsigned char)src[(i + 1) % MEM_SIZE];
    return (c_2);
}



int arg_2(char *b2, t_carr *tmp, t_cor *cor, int *f_err)
{
	int			a1;
	unsigned char	t_reg_3;
	short			t_ind;

	a1 = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (VAL_REG(t_reg_3))
		    a1 = tmp->reg[t_reg_3 - 1];
		if(!(*f_err))
		*f_err = (VAL_REG(t_reg_3)) ? 0 : 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			a1 = read_byte_4(cor->code, tmp->cur + idx_mod(t_ind));
            int a2;
            a2 = read_byte_4_c(cor->code, tmp->cur + idx_mod(t_ind));
            a2 = read_byte_4(cor->code, tmp->cur + idx_mod(t_ind));
            a2 = read_byte_2_int(cor->code, tmp->cur + idx_mod(t_ind));
            a2 = arg_dir(b2, cor, tmp);

		}
		else
			//a1 = idx_mod(read_byte_2(cor->code, tmp->cur + tmp->i));
            a1 = (read_byte_2(cor->code, tmp->cur + tmp->i));
        tmp->i += 2;
	}
	else
		*f_err = 1;
	return ((int)a1);
}

static void			write_add(t_carr *tmp, unsigned char t_reg,
		unsigned char t_reg_2, unsigned char t_reg_3)
{
	tmp->reg[t_reg_3 - 1] = tmp->reg[t_reg - 1] +
							tmp->reg[t_reg_2 - 1];
	tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
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
		write_add(tmp, t_reg, t_reg_2, t_reg_3);
	free(b2);
}
