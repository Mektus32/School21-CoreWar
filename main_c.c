//#include "op.h"
//
////typedef struct		s_champ
////{
////  unsigned int		id;
////  char				name[PROG_NAME_LENGTH + 1];
////  unsigned int		prog_size;
////  char				comment[COMMENT_LENGTH + 1];
////  char				code[MEM_SIZE + 1]; // не уверенна
////}					t_champ;
//
//
////typedef struct		s_cor
////{
////	t_champ			m_ch[MAX_PLAYERS];
////	t_champ			m_2[MAX_PLAYERS];
////}					t_cor;
//
//t_champ *valid_champ(int i, char **av)
//{
//	char *name;
//	t_champ *champ;
//
//	champ = (t_champ*)malloc(sizeof(t_champ));
//	if (name = ft_strstr(av[i], ".cor") && name[4] == '\0' && name != av[i])
//	{
//		champ.id = i;
//
//
//		return (champ);
//	}
//	else
//		exit_print("not valid champ name\n");
//	return (NULL);
//}
//
//// если флаг n - сразу запишем валиднгого игрока
//void make_champ_n(int ac, char **av)
//{
//
//	i = ft_atoi(av[i]);
//	if (i < MAX_PLAYERS)
//	{
//
//		if (cor.m_ch[i].id == 0) // если было пусто до этого
//		{
//			cor.m_ch[i] = valid_champ(++i, av);
//			cor.m_ch[i].i = i - 1;
//
//		}
//		else
//			exit_print("not available n\n");
//	}
//	else
//		exit_print("not available n\n");
//}
//
//void parse_av(int ac, char **av)
//{
//	int i;
//	int f[];
//
//	i = 1;
//	int j;
//	j = 0;
//	while (i <= ac)
//	{
//		if (ft_strcmp("-dump", av[i]) == 0)
//		{
//			i++;
//			// и я не поняла что делать
//		}
//		// дб и число, и игрок (+2 предполагаем что флаг
//		// без числа - ошибка)
//		else if (ft_strcmp("-n", av[i]) == 0 && (i + 2) < ac)
//		{
//			make_champ_n(ac, av, ++i);
//		}
//		else if (ft_strstr(av[i], ".cor") && j < MAX_PLAYERS)
//			cor.m_2[j] = valid_champ(++j, av);// чемпиона в m_2 с индексом j
//		else
//			exit_print("ERROR\n");
//	}
//	// теперь нужно всех перенаправить обратно в m_ch
//	i = 0;
//	j = 0;
//	while (i < MAX_PLAYERS)
//	{
//		// если есть куда переписать (сослаться)
//		if (cor.m_ch[i].id == 0)
//		{
//			while (j < MAX_PLAYERS)
//			//ищем что
//			{
//				if (cor.m_2[j] != 0)
//				{
//					cor.m_ch[i] = cor.m_2[j];
//					cor.m_ch[i].id = i;
//					break ;
//				}
//				j++;
//			}
//		}
//		i++;
//	}
//}
//
//int main(int ac, char **av)
//{
//	if (ac >= 1)
//		parse_av(ac, av);
//	else
//		ft_printf("no file");
//	return (0);
//}