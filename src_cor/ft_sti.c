#include "corewar.h"

/*
** 1. тут дир по 2 байта
** Эта операция записывает значение регистра, переданного в качестве первого параметра,
** по адресу — текущая позиция + (<ЗНАЧЕНИЕ_ВТОРОГО_АРГУМЕНТА> + <ЗНАЧЕНИЕ_ТРЕТЕГО_АРГУМЕНТА>) % IDX_MOD.
** t_reg - куда записывает
** Размер T_DIR = 2
** i = 2 - учитывает что прочитали программу и код параметров
** l - на сколько надо двигаться
** t_dir на 2 байта
**
**
** если IND мы считываем 4 байта по ссылке, а если дир то 2
 *
 * убрать один рег - сначала проверить последний а потом первый уже оставлять
**/

void    ft_sti(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	int i;
	int		l;
	short		t_ind;
	int f_err;
	char *b2;
	unsigned char *p;


	f_err = 0;
	i = 2;
	l = 0;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + i++);
		if (!(t_reg > 0 && (t_reg) <= REG_NUMBER))
			f_err = 1;
	}
	else
	{
		f_err = 1;
		if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
			i += 2;
	}

	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
		if (!((t_reg_2 > 0) && t_reg_2 <= REG_NUMBER))
			f_err = 1;
		else
			l = tmp->reg[t_reg_2 - 1];

	}
	else if ((b2[2] == 1 && b2[3] == 0) || (b2[2] == 1 && b2[3] == 1))
	{
		if (b2[3] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + i);
			i += 2;
			//тут мб 0 вместо i
			l += read_byte_4(cor->code, tmp->cur + i + (t_ind) % IDX_MOD);
		}
		else
		{
			l += read_byte_2(cor->code, tmp->cur + i);
			i += 2;
		}
	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
		if (!(((t_reg_2) > 0) && (t_reg_2) <= REG_NUMBER))
			f_err = 1;
		else
			l = l + tmp->reg[t_reg_2 - 1];
	}
	else if (b2[4] == 1 && b2[5] == 0)
	{

		l+= read_byte_2(cor->code, tmp->cur + i);
		i += 2;
	}
	else
	{
		i += 2 * b2[4];
		f_err = 1;
	}
	if (!f_err)
	{
		p = inttobyte(tmp->reg[t_reg - 1]);
		l = tmp->cur + 0 + l % IDX_MOD;
		copy_p(cor->code, p, l, 0);
		free(p);
	}
	tmp->i = i;
	free(b2);
}



//void    ft_sti(t_cor *cor, t_carr *tmp)
//{
//	unsigned char t_reg;
//	unsigned char t_reg_2;
//	char *b2;
//	unsigned char *p;
//	int f_err;
//	int i;
//	int		l;
//	short	t_dir;
//	//unsigned int	t_dir_1;
//
////	unsigned int	t_dir;
//	unsigned int	t_dir_1;
//
//	i = 2;
//	l = 0;
//	f_err = 0;
//	b2 = base16_2_cor(cor, tmp);
//	if (b2[0] == 0 && b2[1] == 1)
//	{
//		t_reg = read_byte_1(cor->code, tmp->cur + i++);
//		if (!(t_reg > 0 && (t_reg) <= REG_NUMBER))
//			f_err = 1;
//	}
//	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
//	{
//		f_err = 1;
//		i += 2;
//	}
//	else
//		f_err = 1;
//
//	if (b2[2] == 0 && b2[3] == 1)
//	{
//		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
//		if (!((t_reg_2 > 0) && t_reg_2 <= REG_NUMBER))
//			f_err = 1;
//		else
//			l =  (int)tmp->reg[t_reg_2 - 1];
//
//	}
//	else if ((b2[2] == 1 && b2[3] == 0) || (b2[2] == 1 && b2[3] == 1))
//	{
//		t_dir_1 = 0;
//		t_dir = 0;
//		if (b2[3] == 1)
//		{
//			t_dir = read_byte_2(cor->code, tmp->cur + i);
//			i += 2;
//			t_dir_1 = read_byte_4(cor->code, tmp->cur + i + (t_dir) % IDX_MOD);
//		}
//		else
//		{
//			t_dir_1 = read_byte_4(cor->code, tmp->cur + i);
//			i += 4;
//		}
//		l = t_dir + t_dir_1;
//	}
//	else
//		f_err = 1;
//	if (b2[4] == 0 && b2[5] == 1)
//	{
//		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
//		if (!(((t_reg_2) > 0) && (t_reg_2) <= REG_NUMBER))
//			f_err = 1;
//		else
//			l = l + (int)tmp->reg[t_reg_2 - 1];
//	}
//	else if (b2[4] == 1 && b2[5] == 0)
//	{
//
//		t_dir_1 = read_byte_4(cor->code, tmp->cur + i);
//		i += 4;
//		l = l + t_dir_1;
//	}
//	else
//	{
//		i += 2 * b2[4];
//		f_err = 1;
//	}
//
//	if (!f_err)
//	{
//
////
////		unsigned char	c[1];
////		int k = 0;
////		write(1,"!!\n",3);
//
////		while (k < 8)
////		{
////			ft_memcpy(c, (cor->code + tmp->cur +  (l + k++) % IDX_MOD % MEM_SIZE), 1);
////			ft_printf("|%x| %x|\n",c[0], c[1]);
////		}
//		p = inttobyte(tmp->reg[t_reg - 1]);
//		l = tmp->cur + i + l % IDX_MOD;
//		//printf("tmp->reg[t_reg] = %d\n", tmp->reg[t_reg]);
//		copy_p(cor->code, p, l, 0);
//		tmp->i = i;
////		write(1,"!!\n",3);
////		k = 0;
////		while (k <8)
////		{
////			ft_memcpy(c, (cor->code + tmp->cur + (l + k++) % IDX_MOD % MEM_SIZE), 1);
////			ft_printf("|%x| %x|\n",c[0], c[1]);
////		}
//		free(p);
//	}
//	//ft_printf("tmp_num = %d, tmp_car = %d, l = %d, IDX_MOD = %d\n", tmp->num, tmp->cur, l, (tmp->cur+ l) % IDX_MOD);
//	else
//	{
//		if ((b2[2] == 1 && b2[3] == 0))
//			i = i - 2;
//		if (b2[4] == 1 && b2[5] == 0)
//			i = i - 2;
//
//		tmp->i = i;
//	}
//	free(b2);
//}
///*безavantdebut работает
// * sti - точно считывает правильно
// *
// * */
