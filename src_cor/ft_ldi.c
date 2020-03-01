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

static int len_k(t_cor *cor, t_carr *tmp, char *b2, int *f_err)
{
	int			k;
	unsigned char	t_reg;

	k = 0;
	k += arg_2(b2, tmp, cor, f_err);
	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg = read_byte_1(cor->code, (tmp->cur + tmp->i++));
		if (VAL_REG(t_reg))
			k += tmp->reg[(int)t_reg - 1];
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


unsigned int	read_byte_4_c( unsigned char *src, int i)
{
    unsigned int	c_4;

    while (i < 0)
        i = MEM_SIZE + i;
    c_4 = 0;
    c_4 = (c_4 << 8);
    c_4 = c_4 | ( char)(src[(i) % MEM_SIZE]);
    c_4 = (c_4 << 8);
    c_4 = c_4 | ( char)(src[(i + 1) % MEM_SIZE]);
    c_4 = (c_4 << 8);
    c_4 = c_4 | ( char)(src[(i + 2) % MEM_SIZE]);
    c_4 = (c_4 << 8);
    c_4 = c_4 | ( char)(src[(i + 3) % MEM_SIZE]);
    return ((unsigned int)c_4);
}

void				ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char	t_reg;
	char			*b2;
	int				f_err;
	int			k;
	int addr;

	tmp->i = 2;
	if (cor->live.cyc == 12713)
    cor->live.cyc = 12713;
	b2 = base16_2_cor(cor, tmp);
	//ft_printf("%d %d %d %d %d %d %d %d\n", b2[0], b2[1], b2[2],b2[3], b2[4], b2[5], b2[6], b2[7]);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	k = len_k(cor, tmp, b2, &f_err);
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (f_err == 0 && (VAL_REG(t_reg)))
		{
            if(!l)
                k = k % IDX_MOD;
            k = mem_size(k);
		    addr = mem_size(tmp->cur + k);
			tmp->reg[(int)t_reg - 1] =
					read_byte_4(cor->code, mem_size(tmp->cur + k));
			int a2;
			a2 = read_byte_4(cor->code, mem_size(tmp->cur + k));
			//a2 = read_byte_4_c(cor->code, mem_size(tmp->cur + k));


			//ft_printf("adr = %d",addr);
			if (l)
				tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
		}
	}
	else
		tmp->i += 2 * b2[4];
	free(b2);
}
