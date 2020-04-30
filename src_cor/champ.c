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

static void		write_name_two(int fd, char *file_name, t_champ *champ)
{
	size_t			len_code;
	unsigned char	c;

	len_code = read(fd, (champ->code), champ->prog_size);
	if (len_code != champ->prog_size)
		exit_print("code error\n");
	while (read(fd, &c, 1))
		++len_code;
	champ->file_name = ft_strdup(file_name);
	if (len_code > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n",
			champ->file_name, len_code - 4, CHAMP_MAX_SIZE);
		exit_print("Error: File has too large");
	}
	if (len_code > champ->prog_size)
		exit_print("Error: File has a code size that differ from what its "
	"header says\n");
}

void			write_name(int fd, char *file_name, t_champ *champ)
{
	unsigned char	c[4];
	size_t			st;

	read(fd, &c, 4);
	champ->magic = TO_INT(c);
	if (champ->magic != COREWAR_EXEC_MAGIC)
		exit_print("Error: wrong exec_magic\n");
	read(fd, (champ->prog_name), PROG_NAME_LENGTH);
	if (read(fd, &c, 4) != 4 || c[0] || c[1] || c[2] || c[3])
		exit_print("Error: wrong name\n");
	if (read(fd, &c, 4) != 4 ||
		(champ->prog_size = TO_INT(c)) > CHAMP_MAX_SIZE)
		exit_print("File has a code size that differ"
	"from what its header says\n");
	if ((st = read(fd, &(champ->comment), COMMENT_LENGTH)) != COMMENT_LENGTH)
		exit_print("error comment\n");
	if ((st = read(fd, &c, 4)) != 4 || c[0] || c[1] || c[2] || c[3])
		exit_print("no NULL in comment\n");
	champ->code = (unsigned char *)ft_strnew_uc(champ->prog_size);
	write_name_two(fd, file_name, champ);
}

/*
** i - номер текущего параметра
** если параметр файл cor пытаемся записать чемпиона
*/

void			valid_champ(int i, char **av, t_champ *champ)
{
	char	*name;
	int		fd;

	if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0'
			&& ft_strlen(av[i]) != 4)
	{
		if ((fd = open(av[i], O_RDONLY)) > 2)
		{
			write_name(fd, av[i], champ);
		}
		if (champ->file_name)
			return ;
		else
			exit_print("not valid champ file\n");
	}
	else
		exit_print("not valid champ name\n");
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

void make_champ_n(char **av, int n, t_cor *cor)
{
	int	i;

	i = ft_atoi(av[n]);
	if (i && i <= cor->n)
	{
		if (!(cor->m_ch[i - 1]).code)
		{
			valid_champ(++n, av, &(cor->m_ch[i - 1]));
			cor->m_ch[i - 1].id = i - 1;
		}
		else
			exit_print("not available n\n");
	}
	else
	{
		i = 0;
		while (cor->m_2[i].code)
			i++;
		valid_champ(++n, av, &(cor->m_2[i]));
	}
}
