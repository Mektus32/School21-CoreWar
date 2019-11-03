#include "corewar.h"

/*
** запись бинарника и его валидация
** тут создается чемпион
 * и место под его код
 * 4 б - COREWAR_EXEC_MAGIC
 * PROG_NAME_LENGTH -
 * 4 б - NULL;
 * 4 б prog size
 *
*/
t_champ *write_name(int fd)
{

	t_champ *ch;
	unsigned char	c[4];
	size_t st;

	ch = (t_champ *)ft_memalloc(sizeof(t_champ));
	st = read(fd, &c, 4);
	ch->magic = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
	if (ch->magic != COREWAR_EXEC_MAGIC)
		exit_print("no COREWAR_EXEC_MAGIC");
	st = read(fd, (ch->prog_name), PROG_NAME_LENGTH);
	st = read(fd, &c, 4);
	if (c[0] || c[1] || c[2] || c[3] || st != 4)
		exit_print("no NULL in name");
	st = read(fd, &c, 4);
	ch->prog_size = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
	if (ch->prog_size > CHAMP_MAX_SIZE)
		exit_print("File has a code size that differ from what its header says");
	else
	{
		st = read(fd, &(ch->comment), COMMENT_LENGTH);
		if (st != COMMENT_LENGTH)
			exit_print("error comment");
		st = read(fd, &c, 4);
		if (c[0] || c[1] || c[2] || c[3] || st != 4) // оригинал не проверяет на NULL
			exit_print("no NULL in comment");

		ch->code = ft_strnew(ch->prog_size);
		ch->id = 0;
		st = read(fd, (ch->code), ch->prog_size);
		if (st != ch->prog_size)
			exit_print("code error");
	}
	return (ch);
}


t_champ *valid_champ(int i, char **av)
{
	// i - номер текущего параметра
	char *name;
	t_champ *champ;
	int fd;

	if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0' && ft_strlen(av[i]) != 4 )
	{

		fd = open(av[i], O_RDONLY);
		champ = write_name(fd);
		return (champ);
	}
	else
		exit_print("not valid champ name\n");
	return (NULL);
}

// если флаг n - сразу запишем валиднгого игрока
// n - текущий параметр
// i - номер чеммпиона, после флага n
void make_champ_n(int ac, char **av, int n, t_cor *cor)
{
	int i;

	i = ft_atoi(av[n]);
	if (i && i <=  cor->n)// Оно должно быть больше или равно 1,
		// но не превышать общее количество игроков, которые принимают участие в битве.
	{
		if (!(cor->m_ch[i - 1])) // если было пусто до этого
		{
			cor->m_ch[i - 1] = valid_champ(++n, av);
			cor->m_ch[i - 1]->id = i - 1;
		}
		else
			exit_print("not available n\n");
	}
	else
	{
		//-n number
		//sets the number of the next player. If non-existent, the player will have the next
		//available number in the order of the parameters. The last player will have the first
		//process in the order of execution
		i = 0;
		while (cor->m_2[i]) // пока заняты - пропускаем
			i++;
		cor->m_2[i] = valid_champ(++n, av);
	}
}
