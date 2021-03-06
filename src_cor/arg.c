/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:26:40 by qgilbert          #+#    #+#             */
/*   Updated: 2020/03/03 16:26:47 by qgilbert         ###   ########.fr       */
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

/*
**	if (!(*f_err))
**	*f_err = (VAL_REG(t_reg_3)) ? 0 : 1;
** если была ошибка или регистр невалидный  = ошибка : ошибки нет
*/

int					arg_4(char *b2, t_carr *tmp, t_cor *cor, int *f_err)
{
	unsigned char	t_reg_3;
	unsigned int	t_dir;

	t_dir = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		t_dir = tmp->reg[t_reg_3 - 1];
		*f_err = (*f_err || !(val_reg(t_reg_3))) ? 1 : 0;
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

int					arg_2(char *b2, t_carr *tmp, t_cor *cor, int *f_err)
{
	int				a1;
	unsigned char	t_reg_3;

	a1 = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (val_reg(t_reg_3))
			a1 = tmp->reg[t_reg_3 - 1];
		*f_err = (*f_err || !(val_reg(t_reg_3))) ? 1 : 0;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
			a1 = read_byte_4(cor->code, tmp->cur +
				idx_mod(read_byte_2(cor->code, tmp->cur +
				tmp->i)));
		else
			a1 = (read_byte_2(cor->code, tmp->cur + tmp->i));
		tmp->i += 2;
	}
	else
		*f_err = 1;
	return ((int)a1);
}

char				*base16_2_cor(t_cor *cor, t_carr *tmp)
{
	char			*b2;
	unsigned char	c;
	int				i;

	if ((b2 = (char *)ft_memalloc(sizeof(char) * 9)) == NULL)
		exit_print(cor, "memory not allocated\n");
	c = read_byte_1(cor->code, tmp->cur + 1);
	i = 7;
	while (i >= 0)
	{
		b2[i--] = c % 2;
		c = c / 2;
	}
	return (b2);
}

unsigned char		*inttobyte(int a, t_cor *cor)
{
	unsigned char	*bt;

	if ((bt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 4)) == NULL)
		exit_print(cor, "memory not allocated\n");
	bt[0] = (unsigned char)((a >> 24) & 0xff);
	bt[1] = (unsigned char)((a >> 16) & 0xff);
	bt[2] = (unsigned char)((a >> 8) & 0xff);
	bt[3] = (unsigned char)((a >> 0) & 0xff);
	return (bt);
}
