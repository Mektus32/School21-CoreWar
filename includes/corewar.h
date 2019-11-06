/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:43:57 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/02 20:43:59 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"


#define VAL_REG(reg) (reg > 0 && reg <= REG_NUMBER) ? 1 : 0
#define  TO_INT(c) ((c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3])


typedef struct		s_champ
{
	unsigned int		id;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	unsigned int		magic;
	char				*code;
}						t_champ;

/*
 * каретка:
 *
 * Название регистра (r1, r2...) в байт-коде занимает 1 байт.
 * Но сам регистр вмещает в себя 4 байта, как указано в константе REG_SIZE.
 * num - уникальный номер каретки !!! ЗАЧЕМ?
 * cur - текущее положение
 * cycles_live - цикл когда проводилась оп live
 * carry - Carry - нужен в функции zjmp, который исполняется в том случае, что у каретки->carry = 1.
 * id_par - родитель
 * reg
 * live -  1 или 0 жива или нет
 * prog - команду которую он исполняет
 * cycles_to - количество циклов, сколько ему осталось ждать до исполнения команды.
 * i - перемещение каретки на шаге (длина предыдущего хода)
 * */

typedef struct 			s_carr
{
	int					num;
	int					cur;
	int					cycles_live;
	int					carry;
	int					id_par;
	unsigned int		reg[REG_NUMBER];
	unsigned char		prog;
	int					cycles_to;
	int					i;
	struct s_carr		*next;
}						t_carr;
/*
** все о текузем положении и live:
** id_live - игрок, о котором в последний раз сказали, что он жив (ПОБЕДИТЕЛЬ)
** ИНФОРМАЦИЮ О НЁМ МЫ ПОЛУЧАЕМ ТОЛЬКО В оп_LIVE ????
** cyc - количество прошедших с начала игры циклов
** live_count - количество выполненных операций live за последний период, длинной в cyc_to_die
** обнуляется каждую проверку?
** cyc_to_die - длительность периода до проверки
** изменяется в 2ух случаях
** check_count - количество проведенных проверок
** - обнуляется, если меняется cyc to die
** cycle_new - кол -во циклов после обнуления
 * counter - считает проверки без изменения to_die
** */

typedef  struct			s_live
{
	int					id_live;
	int					cyc;
	int					live_count;
	int					cyc_to_die;
	int					cyc_tmp;
	int					counter;
}						t_live;

/*
** Общая структура для игры
** n - общее кол - во игроков
** n_curr - число кареток в настоящий момент
 * nbr_cyc - если есть dump
** f - набор флажков для заполнения с флагом -n
** m_ch - основной хранитель чемпионов
** (хранит ссылки на m_2)
** m_2 - туда пишем чемпионов, в очередности поступления(без флагов)
** code - все игровое поле
** carr - список всех кареток
** live
** нет общего числа кареток больше
*/

typedef struct			s_cor
{
	int					n;
	int					n_curr;
	int 				nbr_cyc;
	int 				f[MAX_PLAYERS];
	t_champ				*m_ch[MAX_PLAYERS];
	t_champ				*m_2[MAX_PLAYERS];
	char				*code;
	int 				*colormap;
	struct s_carr		*carr;
	struct s_live		*live;
}						t_cor;

/*
 ****** parse_av ******
*/

t_cor	*parse_av(int ac, char **av);

/*
 * ***** champ ******
*/

t_champ	*write_name(int fd);
t_champ	*valid_champ(int i, char **av);
void	make_champ_n(int ac, char **av, int n, t_cor *cor);

/*
 * ****** arena ******
*/

void	arena(t_cor *cor);

/*
 * ***** go_cor ******
*/

void	go_cor(t_cor *cor);

/*
 * ***** carr_list ******
*/

t_carr	*new_curr(int id_par);
void	add_curr(t_carr **all_carr, t_carr *new);
int	len_curr(t_carr *list);
t_carr	*remove_head(t_cor *cor, t_carr *curr);
t_carr	*remove_elem(t_carr *curr, t_carr **prev);
t_carr	*carr_list(t_cor *cor);

/*
 * ***** do_op ******
*/

int		ft_cycles_to(char p);
void	do_op(t_cor *cor, t_carr	*tmp);

/*
 * ***** print_code ******
*/

void	print_dump_code(t_cor *cor);
void	exit_print(char *str);

/*
 * ***** read_byte ******
 * inttobyte - переводит инт в байт
 * base16_2_cor - из одного байта делает 8 бит
*/

unsigned char	read_byte_1(const char *src, int i);
short			read_byte_2(const char *src, int i);
unsigned int	read_byte_4(const char *src, int i);
unsigned char	*inttobyte(int a);
char			*base16_2_cor(t_cor *cor, t_carr *tmp);

/*
 * ***** ft_liba ******
 * */

void			free_cor(t_cor *cor);
char			*ft_strncpy_all(char *dest, const char *source, size_t n);
int				mem_size(int cur);
short			idx_mod(short t_ind);

/*
 * ***** ft_add ******
 * arg_4 - считает откуда считывать 4 байта, если возможные аргументы t_reg, t_dir(4 байта) или t_ind
 * arg_2 - считает откуда считывать 4 байта  t_dir(2 байта) или t_ind
 *
 * */
void		ft_add(t_cor *cor, t_carr *tmp);
void		ft_zjmp(t_cor *cor, t_carr *tmp);
int			arg_4(char *b2, t_carr *tmp, t_cor *cor, int *f_err);
short		arg_2(char *b2, t_carr *tmp, t_cor *cor,  int *f_err);

/*
** все операции, что с флагом l - реализованы с переменной l
** про операции в файлах с функциями
*/

void		ft_live(t_cor *cor, t_carr *tmp);
void		ft_ld(t_cor *cor, t_carr *tmp, int l);
void		ft_st(t_cor *cor, t_carr *tmp);
void		ft_sub(t_cor *cor, t_carr *tmp);
void		ft_and(t_cor *cor, t_carr *tmp);
void		ft_or(t_cor *cor, t_carr *tmp);
void		ft_xor(t_cor *cor, t_carr *tmp);
void		ft_ldi(t_cor *cor, t_carr *tmp, int l);
void		ft_sti(t_cor *cor, t_carr *tmp);
t_carr *	ft_fork(t_cor *cor, t_carr *tmp, int l);
void		ft_lld(t_cor *cor, t_carr *tmp);
void		ft_aff(t_cor *cor, t_carr *tmp);
void		copy_p(void *dst, const void *src, int d_s, int s_s);

#endif