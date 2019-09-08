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


typedef struct		s_cor
{
	int				n;	//кол - во чемпионов
	int 			nbr_cycles;
	int 			f[MAX_PLAYERS]; //
	t_champ			*m_ch[MAX_PLAYERS];
	t_champ			*m_2[MAX_PLAYERS]; // нужен только для запись чемпионов без флагов
}					t_cor;

//typedef  struct		s_live
//{
//	int				id_live; // игрок, о котором в последний раз сказали, что он жив
//	int				;//количество прошедших с начала игры циклов
//	int				; //количество выполненных операций live за последний период, длинной в cycles_to_die
//	int				cycles_to_die; //cycles_to_die — длительность периода до проверки
//	int				;//количество проведенных проверок
//
//}					t_live;

//typedef struct 		s_carr
//{
//	int				cur; //текущее положение
//	int				carry;//Carry - нужен в функции zjmp, который исполняется в том случае, что у каретки->carry = 1.
//	int				id_par;//номер игрока который его породил
//	int				register[REG_NUMBER];//16 регистров (массив unsigned int register[16])
//	int				live;// 1 или 0 жива или нет
//	int				prog;//команду которую он исполняет
//	int				cycles_to;//количество циклов, сколько ему осталось ждать до исполнения команды.
//
//
//}					t_carr;

t_champ *write_name(int fd);
t_champ *valid_champ(int i, char **av);
void make_champ_n(int ac, char **av, int n, t_cor *cor);
t_cor *parse_av(int ac, char **av);