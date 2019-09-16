/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/



#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
** 1219
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3


#include <string.h>

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;


typedef struct		s_champ
{
	header_t			*head_c;
	unsigned int		id;
	char				*code;
}					t_champ;

typedef struct 		s_carr;
typedef  struct		s_live;

typedef struct		s_cor
{
	int				n;	//кол - во чемпионов
	int				n_curr;
	int 			nbr_cycles;
	int 			f[MAX_PLAYERS]; //
	t_champ			*m_ch[MAX_PLAYERS];
	t_champ			*m_2[MAX_PLAYERS]; // нужен только для запись чемпионов без флагов
	char			*code;
	int 			*colormap;
	struct s_carr	*carr;
	struct s_live	*live;
}					t_cor;

typedef  struct		s_live
{
	int				id_live; // игрок, о котором в последний раз сказали, что он жив
	int				cycles;//количество прошедших с начала игры циклов
	int				live_count; //количество выполненных операций live за последний период, длинной в cycles_to_die
	int				cycles_to_die; // длительность периода до проверки
	int				check_count;//количество проведенных проверок

}					t_live;
//
typedef struct 		s_carr
{
	int				num;//уникальный номер каретки
	int				cur; //текущее положение
	int				cycles_live;
	int				carry;//Carry - нужен в функции zjmp, который исполняется в том случае, что у каретки->carry = 1.
	int				id_par;//номер игрока который его породил
	int				reg[REG_NUMBER];//16 регистров (массив unsigned int register[16])
	int				live;// 1 или 0 жива или нет
	char			prog;//команду которую он исполняет
	int				cycles_to;//количество циклов, сколько ему осталось ждать до исполнения команды.
	struct s_carr			*next;
}					t_carr;

void	*ft_memcpy_all(void *dst, const void *src, size_t n);
char	*ft_strncpy_all(char *dest, const char *source, size_t n);

t_champ *write_name(int fd);
t_champ *valid_champ(int i, char **av);
void make_champ_n(int ac, char **av, int n, t_cor *cor);
t_cor *parse_av(int ac, char **av);
void	arena(t_cor *cor);
char *base16_2(unsigned c);


t_carr *new_curr(int id_par);
void add_curr(t_carr **all_carr, t_carr *new);
void remove_curr_if(t_carr **all_carr, int num);
t_carr *carr_list(t_cor *cor);
int	ft_cycles_to(char p);

void go_cor(t_cor *cor);

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
void    ft_fork(t_cor *cor, t_carr *tmp, int l);
//void    ft_lld(t_cor *cor, t_carr *tmp);
//void    ft_lldi(t_cor *cor, t_carr *tmp);
//void    ft_lfork(t_cor *cor, t_carr *tmp);
void    ft_aff(t_cor *cor, t_carr *tmp);

