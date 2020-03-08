/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:14:34 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 19:14:36 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** 1. тут дир по 2 байта
** Эта операция записывает значение регистра,
** переданного в качестве первого параметра,
** по адресу — текущая позиция +
** (<ЗНАЧЕНИЕ_ВТОРОГО_АРГУМЕНТА> + <ЗНАЧЕНИЕ_ТРЕТЕГО_АРГУМЕНТА>) % IDX_MOD.
** t_reg - куда записывает
** Размер T_DIR = 2
** i = 2 - учитывает что прочитали программу и код параметров
** l - на сколько надо двигаться
** t_dir на 2 байта
**
**
** если IND мы считываем 4 байта по ссылке, а если дир то 2
**
** убрать один рег - сначала проверить последний а потом первый уже оставлять
*/

static int len_l(t_cor *cor, t_carr *tmp, char *b2, int *f_err, int *l_2)
{
	int				l;
	unsigned char	t_reg_2;

	l = 0;
	l += arg_2(b2 + 2, tmp, cor, f_err);
    l_2[0] = l;
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (b2[4] == 0 && b2[5] == 1 && !(VAL_REG(t_reg_2)))
			*f_err = 1;
		if (VAL_REG(t_reg_2))
        {
		    l = l + (int)tmp->reg[t_reg_2 - 1];
		    l_2[0] = l;
        }


	}
	else if (b2[4] == 1 && b2[5] == 0)
	{
	    l_2[1] = read_byte_2(cor->code, tmp->cur + tmp->i);
		l += l_2[1];
		tmp->i += 2;
	}
	else
	{
		tmp->i += 2 * b2[4];
		*f_err = 1;
	}
	return (l);
}

static void write_sti(t_cor *cor, t_carr *tmp, unsigned char t_reg, int l, int *l_2)
{
	unsigned char	*p;

	p = inttobyte(tmp->reg[t_reg - 1]);
	write_map_color(cor, l, 4, tmp);
	copy_p(cor->code, p, l, 0);
	free(p);
	if(cor->v_print[2])
    {
	    ft_printf("P    %d | sti r%d %d %d\n", tmp->id_par, t_reg, l_2[0], l_2[1], l);
	    ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", l_2[0], l_2[1], l_2[0] + l_2[1], l);
    }
}

void			ft_sti(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	int				l;
	int             l_2[2];
	int				f_err;
	char			*b2;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	f_err = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
	}
	else
	{
		f_err = 1;
		if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
			tmp->i += 2;
	}
	l = mem_size(tmp->cur + len_l(cor, tmp, b2, &f_err, l_2) % IDX_MOD);
	if (!f_err && VAL_REG(t_reg))
        write_sti(cor, tmp, t_reg, l, l_2);
	free(b2);
}
