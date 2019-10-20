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

//#define IFR16(x)	(unsigned int)(x[0] << 24 | x[1] << 16 | x[2] << 8 | x[3])
//#define IFR8(x)		(short)(x[0] << 8 | x[1])

#define IFR16(bytes)	(unsigned int)(((bytes[3] & 0xFF) << 24) + ((bytes[2] & 0xFF) << 16) + ((bytes[1] & 0xFF) << 8) + (bytes[0] & 0xFF))
//#define IFR8(bytes)		(short)(((bytes[1] & 0xFF) << 8) + (bytes[0] & 0xFF))

#define IFR16(bytes)	(unsigned int)(((bytes[0]) << 24) + ((bytes[1]) << 16) + ((bytes[2]) << 8) + (bytes[3]))
#define IFR8(bytes)		(short)(((bytes[0]) << 8) + (bytes[1]))
#define VAL_REG(reg) (reg > 0 && reg <= REG_NUMBER) ? 1 : 0
/*
 * при копировании мне нужно
 * 1. что
 * 2. с какой позиции
 * 3. куда | и я хз как наверняка это сделать
 * 4. с какой позиции
 * 5. сколько символов
 * */
typedef struct		s_copy
{
	const void *src;
	int 		i_s;
	int 		i_d;
	size_t		n;

}					t_copy;

/*
 * чемпион
 * */

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
	int					live;
	char				prog;
	int					cycles_to;
	int					i;
	struct s_carr		*next;
}						t_carr;
/*
** все о текузем положении и live:
** id_live - игрок, о котором в последний раз сказали, что он жив (ПОБЕДИТЕЛЬ)
** ИНФОРМАЦИЮ О НЁМ МЫ ПОЛУЧАЕМ ТОЛЬКО В оп_LIVE ????
** cycles - количество прошедших с начала игры циклов
** live_count - количество выполненных операций live за последний период, длинной в cycles_to_die
** обнуляется каждую проверку?
** cycles_to_die - длительность периода до проверки
** изменяется в 2ух случаях
** check_count - количество проведенных проверок
** */

typedef  struct			s_live
{
	int					id_live;
	int					cycles;
	int					live_count;
	int					cycles_to_die;
	int					check_count;
}						t_live;

/*
** Общая структура для игры
** n - общее кол - во игроков
** n_curr - число кареток в настоящий момент
 * nbr_cycles - если есть dump
** f - набор флажков для заполнения с флагом -n
** m_ch - основной хранитель чемпионов
** (хранит ссылки на m_2)
** m_2 - туда пишем чемпионов, в очередности поступления(без флагов)
** code - все игровое поле
** carr - список всех кареток
** live
** */

typedef struct			s_cor
{
	int					n;
	int					n_curr;
	int 				nbr_cycles;
	int 				f[MAX_PLAYERS];
	t_champ				*m_ch[MAX_PLAYERS];
	t_champ				*m_2[MAX_PLAYERS];
	char				*code;
	int 				*colormap;
	struct s_carr		*carr;
	struct s_live		*live;
}						t_cor;

void *read_byte(const char *src, int i, int c);

void		exit_print(char *str);
void		print_dump_code(t_cor *cor);

void		*ft_memcpy_all(void *dst, const void *src, size_t n, int start, int start_d);

//void	*ft_memcpy_all(void *dst, const void *src, size_t n);
char	*ft_strncpy_all(char *dest, const char *source, size_t n);

t_champ *write_name(int fd);
t_champ *valid_champ(int i, char **av);
void make_champ_n(int ac, char **av, int n, t_cor *cor);
t_cor *parse_av(int ac, char **av);
void	arena(t_cor *cor);
char *base16_2_cor(t_cor *cor, t_carr *tmp);

char *base16_2(unsigned c);


t_carr *new_curr(int id_par);
void add_curr(t_carr **all_carr, t_carr *new);
void remove_curr_if(t_cor *cor, int num);
t_carr *carr_list(t_cor *cor);
int	ft_cycles_to(char p);

void go_cor(t_cor *cor);
//там может нужен unsigned
unsigned char *inttobyte(int a);

/*
* когда заходим в функцию - знаем что она валидна
 * поэтому codage забираем из +1
 * i на старте, где он есть стартуем с позиции 2
 * далее по очереди проверяем аргументы
 * если функция не выполнится, она все = перейдет на то кол-во байтов,
 * котороу указано в codage
 */

/*
 * 	запоминаем номер цикла в котором проводилась опирация live
 * Если указанный в качестве аргумента операции live
*	номер совпадает с номером игрока, то она засчитывает,
*	что это игрок жив. Например, если значение аргумента равно -2,
 *	значит игрок с номером 2 жив.
 *
 */



/*
 * Эта операция записывает значение из регистра, который был передан
 * как первый параметр. А вот куда данная операция его записывает,
 * зависит от типа второго аргумента:
 *
 * // нужно ли удалять из рег первого значение?
 */

/*
 * все операции, что с флагом l - реализованы с переменной l
 * про операции в файлах с функциями
 * */
void    ft_live(t_cor *cor, t_carr *tmp);
void    ft_ld(t_cor *cor, t_carr *tmp, int l);
void    ft_st(t_cor *cor, t_carr *tmp);
void    ft_add(t_cor *cor, t_carr *tmp);
void    ft_sub(t_cor *cor, t_carr *tmp);
void    ft_and(t_cor *cor, t_carr *tmp);
void    ft_or(t_cor *cor, t_carr *tmp);
void    ft_xor(t_cor *cor, t_carr *tmp);
void    ft_zjmp(t_cor *cor, t_carr *tmp);
void    ft_ldi(t_cor *cor, t_carr *tmp, int l);
void    ft_sti(t_cor *cor, t_carr *tmp);
t_carr *   ft_fork(t_cor *cor, t_carr *tmp, int l);
void    ft_aff(t_cor *cor, t_carr *tmp);

unsigned char read_byte_1(const char *src, int i);
short read_byte_2(const char *src, int i);
unsigned int read_byte_4(const char *src, int i);

void copy_p(void *dst, const void *src, int d_s, int s_s);
int arg_1(char *b2, t_carr *tmp, t_cor *cor, int *f_err);
int arg_2(char *b2, t_carr *tmp, t_cor *cor,  int *f_err);
void do_op(t_cor *cor, t_carr	*tmp);
void free_cor(t_cor *cor);
#endif