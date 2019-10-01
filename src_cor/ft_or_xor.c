#include "corewar.h"
/*
 *
 *
 * */
void    ft_or(t_cor *cor, t_carr *tmp)
{
	int a1;
	int a2;
	unsigned char t_reg_3;
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];

	i = 2;
	a = 0;
	f_err = 0;
	b2 = base16_2_cor(cor, tmp);
	//printf("b = 0|%d 1|%d 2|%d 3|%d 4|%d 5|%d 6|%d 7|%d\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5], b2[6], b2[7]);
	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1),0);
		a1 = (int)t_reg_3;
		if ( !((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1),0);
			a = IFR8(t_ind) % IDX_MOD; //((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE,  (tmp->cur + 1 + 1 + a),0);
		a1 = IFR16(t_dir);
	}
	else
		f_err = 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1),0);
		if (!((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
		a2 = (int)t_reg_3;


	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{

		a = 0;
		if (b2[3] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE,  (tmp->cur + i),0);
			a = IFR8(t_ind);
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy_all(t_dir, cor->code , DIR_SIZE, (tmp->cur + i + a),0);
		a2 = IFR16(t_dir);

	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1),0);
			if (((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER) && !f_err)
			{
				tmp->reg[(int)t_reg_3] = a1 | a2;
				tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;

			}

		}
	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
}

void    ft_xor(t_cor *cor, t_carr *tmp)
{
	int a1;
	int a2;
	unsigned char t_reg_3;
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];

	i = 2;
	a = 0;
	f_err = 0;
	b2 = base16_2_cor(cor, tmp);
	//printf("b = 0|%d 1|%d 2|%d 3|%d 4|%d 5|%d 6|%d 7|%d\n", b2[0], b2[1], b2[2], b2[3], b2[4], b2[5], b2[6], b2[7]);
	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1), 0);
		a1 = (int)t_reg_3;
		if ( !((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1),0);
			a = IFR8(t_ind) % IDX_MOD; //((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + a), 0);
		a1 = IFR16(t_dir);
	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1),0);
		if ( !((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
		a2 = (int)t_reg_3;


	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{
		a = 0;
		if (b2[3] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + i),0);
			a = IFR8(t_ind);
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + i + a),0);
		a2 = IFR16(t_dir);

	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code, 1,  (tmp->cur + 1 + 1),0);
			if (((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER) && f_err == 0)
			{
				tmp->reg[(int)t_reg_3] = a1 ^ a2;
				tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;

			}
		}
	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
}