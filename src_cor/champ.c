/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:54:02 by qgilbert          #+#    #+#             */
/*   Updated: 2020/02/22 13:06:10 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** запись бинарника и его валидация
** тут создается чемпион
** и место под его код
** 4 б - COREWAR_EXEC_MAGIC
** PROG_NAME_LENGTH -
** 4 б - NULL;
** 4 б prog size
*/

unsigned char	*ft_strnew_uc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	ptr = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1));
	if (ptr)
		return ((unsigned char*)ft_memset(ptr, '\0', size + 1));
	else
		return (NULL);
}

t_champ *write_name(int fd, char *file_name)
{
	t_champ			*ch;
	unsigned char	c[4];
	size_t			st;
	size_t			len_code;


	ch = (t_champ *)ft_memalloc(sizeof(t_champ));
	st = read(fd, &c, 4);
	ch->magic = TO_INT(c);
	if (ch->magic != COREWAR_EXEC_MAGIC)
		return (NULL);
	st = read(fd, (ch->prog_name), PROG_NAME_LENGTH);
	if ((st = read(fd, &c, 4)) != 4 || c[0] || c[1] || c[2] || c[3] || st != 4)
		return (NULL);
	 if ((read(fd, &c, 4)) != 4 || (ch->prog_size = TO_INT(c)) > CHAMP_MAX_SIZE)
	 	exit_print("File has a code size that differ"
	 "from what its header says\n");
	if ((st = read(fd, &(ch->comment), COMMENT_LENGTH)) != COMMENT_LENGTH)
		exit_print("error comment\n");
	if ((st = read(fd, &c, 4)) != 4 || c[0] || c[1] || c[2] || c[3])
		exit_print("no NULL in comment\n");
	ch->code = (unsigned char *)ft_strnew_uc(ch->prog_size);
	ch->id = 0;
	st = read(fd, (ch->code), ch->prog_size);
	len_code = st;
	if (st != ch->prog_size)
		exit_print("code error\n");
	 //ft_printf("!!!!!!!!!!!!!!!!!!!!!!!write_name\n");
	while (read(fd, &c, 1))
		{len_code +=1;
			//ft_printf("readeee");
		}
	//st = read(fd, &c, 1);
    ch->file_name = ft_strdup(file_name);
	if (len_code > CHAMP_MAX_SIZE)
		{
			ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n",ch->file_name, len_code - 4, CHAMP_MAX_SIZE); //ch->prog_size
			exit_print("Error: File has too large");
		}
	 if (st != 0)
	 exit_print("File has a code size that differ from what its header says\n");

//ft_printf("st = %d, c[0] = %s", st, c[0]);
//		exit_print("File has a code size that differ");

	return (ch);
}

/*
** i - номер текущего параметра
** если параметр файл cor пытаемся записать чемпиона
*/

t_champ	*valid_champ(int i, char **av)
{
	char	*name;
	t_champ	*champ;
	int		fd;

	champ = NULL;
	if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0'
			&& ft_strlen(av[i]) != 4)
	{
		if ((fd = open(av[i], O_RDONLY)) > 2)
		{
			champ = write_name(fd, av[i]);
		}
		if (champ)
			return (champ);
		else
			exit_print("not valid champ file\n");
	}
	else
		exit_print("not valid champ name\n");
	return (NULL);
}

/*
** сохраняет чемпиона с флагом -n в m_ch[i - 1], если там не занято
** если занято в cor->m_2[i] (пока i занято шагаем дальше)
** -n number
** sets the number of the next player. If non-existent,
** the player will have the next
** available number in the order of the parameters. The last player
** will have the first
** process in the order of execution
** если флаг n - сразу запишем валиднгого игрока
** n - текущий параметр
** i - номер чеммпиона, после флага n (Оно должно быть больше или равно 1,
** но не превышать общее количество игроков, которые принимают участие в битве).
*/

void	make_champ_n(int ac, char **av, int n, t_cor *cor)
{
	int	i;

	ac = 0;
	i = ft_atoi(av[n]);
	if (i && i <= cor->n)
	{
		if (!(cor->m_ch[i - 1]))
		{
			cor->m_ch[i - 1] = valid_champ(++n, av);
			cor->m_ch[i - 1]->id = i - 1;
		}
		else
			exit_print("not available n\n");
	}
	else
	{
		i = 0;
		while (cor->m_2[i])
			i++;
		cor->m_2[i] = valid_champ(++n, av);
	}
}
