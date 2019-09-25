#include "corewar.h"

void    ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);
	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		f_err = 1;
	}
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (i == 5)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 1 + 1 + 1));
		ft_memcpy_all(&t_reg_2,  cor->code , 1, (tmp->cur + 1 + 1 + 2));
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1 + 3));
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER) &&
			((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER) &&
				((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] + tmp->reg[(int)t_reg_2];
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
			//tmp->cur = (tmp->cur + i) % MEM_SIZE;
		}
		else
			f_err = 1;
	}
	//if (f_err)
		//tmp->cur = (tmp->cur + i) % MEM_SIZE;
		tmp->i = i;
}

void    ft_sub(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);
	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		f_err = 1;
	}
	if (b2[2] == 0 && b2[3] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (i == 5)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 1 + 1 + 1));
		ft_memcpy_all(&t_reg_2,  cor->code, 1, (tmp->cur + 1 + 1 + 2));
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1 + 3));
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER) &&
			((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER) &&
			((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] - tmp->reg[(int)t_reg_2];
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
			//tmp->cur = (tmp->cur + i) % MEM_SIZE;
		}
		else
			f_err = 1;
	}
//	if (f_err)
//		tmp->cur = (tmp->cur + i) % MEM_SIZE;
	tmp->i = i;
}

void    ft_and(t_cor *cor, t_carr *tmp)
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
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1));
		a1 = (int)t_reg_3;
		if ( !((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[0] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1));
			a = IFR8(t_ind) % IDX_MOD; //((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + a));
		a1 = IFR16(t_dir);
	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1));
		if ( !((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
			f_err = 1;
		a2 = (int)t_reg_3;


	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{

		a = 0;
		if (b2[2] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + i));
			a = IFR8(t_ind);
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy_all(t_dir, cor->code , DIR_SIZE, (tmp->cur + i + a) );
		a2 = IFR16(t_dir);

	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 1 + 1));
		if (((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER) && !f_err)
		{
			tmp->reg[(int)t_reg_3] = a1 & a2;
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
		}


	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
//	unsigned char t_reg;
//	unsigned char t_reg_2;
//	unsigned char t_reg_3;
//	unsigned char	c[1];
//	char *b2;
//	int f_err;
//	int i;
//	int a;
//	unsigned char t_ind[IND_SIZE];
//	unsigned char t_dir[DIR_SIZE];
//	unsigned char t_dir_1[DIR_SIZE];
//
//	i = 1;
//	a = 0;
//	f_err = 0;
//	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
//	b2 = base16_2(c[0]);
//
//	if (b2[0] == 0 && b2[1] == 1)
//	{
//		i += 1;
//		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
//		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
//			f_err = 1;
//	}
//	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
//	{
//
//		a = 0;
//		if (b2[0] == 1)
//		{
//			ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
//			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
//		}
//		i += 4 * (int)b2[4] - 2 * (int)b2[5];
//		ft_memcpy(t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
//		a = 1;
//
//	}
//	else
//		f_err = 1;
//
//	if (b2[2] == 0 && b2[3] == 1)
//	{
//		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
//		if ((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER)
//		{
//
//		}
//		else
//			f_err = 1;
//	}
//	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
//	{
//
//		a = 0;
//		if (b2[2] == 1)
//		{
//			ft_memcpy(t_ind, cor->code + (tmp->cur + i) % MEM_SIZE, IND_SIZE);
//			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
//		}
//		ft_memcpy(t_dir_1, cor->code + (tmp->cur + i + a) % MEM_SIZE, DIR_SIZE);
//		i += 4 * (int)b2[2] - 2 * (int)b2[3];
//		a = 2;
//	}
//	else
//		f_err = 1;
//
//
//
//	if (b2[4] == 0 && b2[5] == 1)
//	{
//		i++;
//		if (f_err == 0)
//		{
//			ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
//			if ((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER)
//			{
//				if (a == 0 && i == 5)
//					tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg_2] & tmp->reg[(int)t_reg];
//				else if (a == 1 && (i == 6 || i == 8))
//					tmp->reg[(int)t_reg_3] = (int)t_dir & tmp->reg[(int)t_reg_2];
//				else if (a == 2 && (i == 6 || i == 8))
//					tmp->reg[(int)t_reg_3] = (int)t_dir_1 & tmp->reg[(int)t_reg];
//				else if (a == 2 && (i == 7 || i == 9 || i == 11))
//					tmp->reg[(int)t_reg_3] = (int)t_dir_1 & (int)t_dir;
//				else
//					f_err = 1;
//				if (f_err == 0)
//				{
//					tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
//				}
//			}
//		}
//
//	}
//	else
//	{
//		i += 4 * (int)b2[4] - 2 * (int)b2[5];
//		f_err = 1;
//	}
//	//if (f_err)
//		//tmp->cur = (tmp->cur + i) % MEM_SIZE;
//	tmp->i = i;
}



void    ft_zjmp(t_cor *cor, t_carr *tmp)
{
	unsigned char t_ind[IND_SIZE];
	int a;

	if (tmp->carry == 1)
	{
		ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1));
		a = IFR8(t_ind) % IDX_MOD;//((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		tmp->cur = (tmp->cur + a) % MEM_SIZE;
		// НАДО ЛИ
//		ft_memcpy(&tmp->prog, cor->code + tmp->cur, 1);		//ft_memcpy(&(tmp->prog), cor->code + (tmp->cur + a) % MEM_SIZE, 1);
//		tmp->cycles_to = ft_cycles_to(tmp->prog);

	}
	tmp->i = 3;

}

void    ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char t_reg;
	unsigned char	*c;
	char *b2;
	int f_err;
	int i;
	int a;
	int k;// на сколько надо передвинуть
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char res[DIR_SIZE];

	i = 1;
	a = 0;
	f_err = 0;
	k = 0;
	c = malloc(sizeof(char));
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 1 + 1));
		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
		k = k + (int)t_reg;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{

		a = 0;
		if (b2[0] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1));
			a = IFR8(t_ind)% IDX_MOD;
		}
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + a));
		a = 1;
		k = k + IFR16(t_dir);


	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 1 + i++));
		if (!((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
		k = k + (int)t_reg;
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{

		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + i));
		i += 4;
		a = 2;
		k = k + IFR16(t_dir);
	}
	else
	{
			i += 4 * (int)b2[2] - 2 * (int)b2[3];
			f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + i));
			if ((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER)
			{
				ft_memcpy_all(res,  cor->code , 4, (tmp->cur + k) % (IDX_MOD - l *  IDX_MOD + 1 * l) % MEM_SIZE);
				tmp->reg[(int)t_reg] = IFR16(res);
			}
		}
	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
}

