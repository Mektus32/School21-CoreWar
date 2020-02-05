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

static int		len_l(t_cor *cor, t_carr *tmp, char *b2, int *f_err)
{
	int				l;
	unsigned char	t_reg_2;

	l = 0;
	l += arg_2(b2 + 2, tmp, cor, f_err);
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (!(VAL_REG(t_reg_2)))
			*f_err = 1;
		l = l + (int)tmp->reg[t_reg_2 - 1];
	}
	else if (b2[4] == 1 && b2[5] == 0)
	{
		l += read_byte_2(cor->code, tmp->cur + tmp->i);
		tmp->i += 2;
	}
	else
	{
		tmp->i += 2 * b2[4];
		*f_err = 1;
	}
	return (l);
}

static void		write_sti(t_cor *cor, t_carr *tmp, unsigned char t_reg, int l)
{
	unsigned char	*p;



	//fprintf("c = %d",cor->live->cyc);
	p = inttobyte(tmp->reg[t_reg - 1]);
	write_map_color(cor, l, 4, tmp);
	copy_p(cor->code, p, l, 0);
	free(p);
}

void			ft_sti(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	int				l;
	int				f_err;
	char			*b2;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (!(VAL_REG(t_reg)))
			f_err = 1;
	}
	else
	{
		f_err = 1;
		if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
			tmp->i += 2;
	}
	l = mem_size(tmp->cur + (len_l(cor, tmp, b2, &f_err)) % IDX_MOD);
	//l = mem_size((tmp->cur + len_l(cor, tmp, b2, &f_err)) % IDX_MOD);
	if (!f_err)
		write_sti(cor, tmp, t_reg, l);
	free(b2);
}
