/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:01:04 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/04 20:01:05 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*ft_strncpy_all(char *dest, const char *source, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_memcpy_all(void *dst, const void *src, size_t n)
{
	unsigned char		*str1;
	unsigned char	*str2;
	int					i;
	unsigned char	c;


	str1 = (unsigned char *)dst;
	str2 = src;
	i = 0;

	if (!src)
	{
		while (n-- > 0)
			str1[i++] = 0;
	}
	else
	{
		while (n-- > 0)
		{
			c = str2[i];
			str1[i] = str2[i];
			//str1[i] = src + i;
			i++;
		}
	}
	return (dst);
}

//void	*ft_memcpy_mem(void *dst, const void *src, size_t n)
//{
//	unsigned char		*str1;
//	const unsigned char	*str2;
//	int					i;
//
//	str1 = dst;
//	str2 = src;
//	i = 0;
//
//	if (!src)
//	{
//		while (n-- > 0)
//			str1[i++] = 0;
//	}
//	else
//	{
//		while (n-- > 0)
//		{
//			str1[i] = str2[i];
//			i++;
//		}
//	}
//	return (dst);
//}
void exit_print(char *str)
{
	printf("%s\n", str);
	exit(0);
}
/*
 * запись бинарника и его валидация
 */
t_champ *write_name(int fd)
{
	header_t *champ;
	t_champ *ch;
	unsigned char	c[4];
	size_t st;

	ch = (t_champ*)malloc(sizeof(t_champ));
	champ = (header_t*)malloc(sizeof(header_t));
	st = read(fd, &c, 4); // COREWAR_EXEC_MAGIC
	champ->magic = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
	st = read(fd, champ->prog_name, PROG_NAME_LENGTH);
	champ->prog_name[PROG_NAME_LENGTH + 1] = '\0';
	// теперь NULL ссчитываем
	st = read(fd, &c, 4);
	if (c[0] || c[1] || c[2] || c[3] || st != 4) // оригинал не проверяет на NULL
		exit_print("no NULL in name");
	// Bot size
	st = read(fd, &c, 4);
	champ->prog_size = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];

	printf("champ->magic = %x, champ->prog_name = %s\n, champ->prog_size = %d\n", champ->magic, champ->prog_name, champ->prog_size);


	if (champ->prog_size > CHAMP_MAX_SIZE)
	{
		exit_print("File has a code size that differ from what its header says");
	}
	else
	{
		st = read(fd, champ->comment, COMMENT_LENGTH);
		if (st != COMMENT_LENGTH)
			exit_print("error comment");
		champ->comment[COMMENT_LENGTH + 1] = '\0';

		printf("com = %s\n",champ->comment );

		st = read(fd, &c, 4);
		if (c[0] || c[1] || c[2] || c[3] || st != 4) // оригинал не проверяет на NULL
			exit_print("no NULL in comment");

		ch->code = ft_strnew(champ->prog_size);
		ch->code[champ->prog_size + 1] = '\0';
		ch->id = 0;
		ch->head_c = champ;
		st = read(fd, ch->code, champ->prog_size);
		if (st != champ->prog_size)
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

	printf("valid_champ: av[%d] = %s\n", i, av[i]);
	if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0' && ft_strlen(av[i]) != 4 )
	{

		printf("name = %s\n", av[i]);
		//fd = open( av[i], O_RDONLY);
		fd = open(av[i], O_RDONLY);
		champ = write_name(fd);
		//champ->id = i - 1;
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
		i = 0;
		while (cor->m_2[i])
			i++;
		cor->m_2[i] = valid_champ(++n, av);
	}
		//exit_print("not available n\n");
}


t_cor *parse_av(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	t_cor *cor;
	char *name;


	cor = (t_cor *)malloc(sizeof(t_cor));
	ft_bzero(cor, sizeof(t_cor));
	cor->n = 0;
	i = 1;
	while (i < ac)
	{
		if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0' && ft_strlen(av[i]) != 4)
			cor->n++;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if ((name = ft_strstr(av[i], "-n")) && name[2] == '\0')
		{
			j = ft_atoi(av[++i]);
			if (j && j <= cor->n)
			{
				if (cor->f[j - 1] == 0)
					cor->f[j - 1] = 1;
				else
					exit_print("number not unique");
			}
			else
				exit_print("number not valid"); // число больше кол - ва чемпионов или = 0
		}
		i++;
	}
	i = 1;
	j = 0;
	while (i < ac)
	{
		if ((name = ft_strstr("-dump", av[i])) && name[5] == '\0')
		{
			cor->nbr_cycles = 1;
			i++;
			// и я не поняла что делать
		}
			// дб и число, и игрок (+2 предполагаем что флаг
			// без числа - ошибка)
		else if (ft_strcmp("-n", av[i]) == 0 && (i + 2) < ac)
		{
			make_champ_n(ac, av, ++i, cor);
			i+=2; // перешагиваем чемпиолна и число
		}
		else if (ft_strstr(av[i], ".cor") && j < MAX_PLAYERS)
		{
			cor->m_2[j++] = valid_champ(i, av);// чемпиона в m_2 с индексом j
			i++;
		}
		else
			exit_print("ERROR\n");
	}
	// теперь нужно всех перенаправить обратно в m_ch
	i = 0;
	j = 0;
	if (cor->n <= MAX_PLAYERS)
	{
		while (i < cor->n)
		{
			// если есть куда переписать (сослаться) и что
			if (!cor->m_ch[i] && cor->m_2[j])
			{
				cor->m_ch[i] = cor->m_2[j];
				cor->m_ch[i]->id = i;
				j++;
			}
			else if (!cor->m_ch[i] && !cor->m_2[j])
				exit_print("number champ less then flag -n");
			i++;
		}
	}
	else
		exit_print("number players more than MAX_PLAYERS\n");

	return (cor);
}

char *base16_2(unsigned c)
{
	char *b2;
	int		i;

	i = 7;
	b2 = (char *)malloc(sizeof(char) * 9);
	b2[8] = '\0';
	while (i >= 0)
	{
		//printf("c16 = %d ", c%2);
		b2[i] = c % 2;
		c = c/2;
		i--;
	}
	printf("\n");
	return  (b2);

}

char *base16_2_cor(t_cor *cor, t_carr *tmp)
{
	unsigned char	*k;
	unsigned c;
	char *b2;
	int		i;

	i = 7;
	k = malloc(sizeof(char));
	ft_memcpy(k, cor->code + (tmp->cur + 1) % MEM_SIZE, 1);
	c = (unsigned)k;
	b2 = (char *)malloc(sizeof(char) * 9);
	b2[8] = '\0';
	while (i >= 0)
	{
		//printf("c16 = %d ", c%2);
		b2[i] = c % 2;
		c = c/2;
		i--;
	}
	printf("\n");
	free(k);
	return  (b2);

}
/*
 * Еще один нюанс: при чтении байтов нужно кастить их в зависимости от размера чтения:

1 байт - unsigned char
2 байта - short
4 байта - unsigned int
 * */
void	arena(t_cor *cor)
{

	int i;

	cor->code = (char *)malloc(sizeof(char) * MEM_SIZE);
	cor->live = (t_live *)malloc(sizeof(t_live));
	ft_memset(cor->code, 0, sizeof(cor->code) * MEM_SIZE);
	//cor->code[MEM_SIZE + 1] = '\0';
	cor->colormap = (int*)malloc(sizeof(int) * MEM_SIZE);
	i = 0;
	while (i < cor->n)
	{
		ft_strncpy_all(cor->code + i * (MEM_SIZE / cor->n), cor->m_ch[i]->code, cor->m_ch[i]->head_c->prog_size);
		i++;
	}
	//После того, как на арене были размещены исполняемые коды чемпионов, на начало каждого из них устанавливается каретка.
	// надо создать список для всех кареток - добавляем сверху сверху начинаем заполнять

	cor->carr = carr_list(cor);

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < cor->n)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				(cor->m_ch[i])->head_c->prog_size, (cor->m_ch[i])->head_c->prog_name,
				(cor->m_ch[i])->head_c->comment);
		i++;
	}
	go_cor(cor);
	ft_printf("Contestant %d, \"%s\", has won !", cor->live->id_live,(cor->m_ch[cor->live->id_live - 1])->head_c->prog_name);
}

int main(int ac, char **av)
{
	t_cor *cor;

	if (ac >= 1)
	{
		cor = parse_av(ac, av);
		arena(cor);
	}
	else
		ft_printf("no file");
	return (0);
//	int	fd;
//	int	i;
//	char *name;
//
//
//	if (ac >= 2 || ac == 1)
//	{
//		i = 1;
//		while (i <= ac)
//		{
//			if (ac == 1)
//				name = "../vm_champs/champs/Gagnant.cor";
//			else
//				name = av[i];
//			//ft_printf("name = %s\n", name);
//			if ((fd = open(name, O_RDONLY)) > 0)
//				write_name(fd);
//			else
//			{
//				ft_printf("file %s", av[i]);
//			}
//			i++;
//		}
//	}
//	else
//		ft_printf("no file");
//	return (0);
}


//at-h6% ./corewar champs/championships/2018/bcozic/sencha.cor champs/championships/2018/bcozic/pai_mu_tan.cor
//		Introducing contestants...
//* Player 1, weighing 198 bytes, "Sencha" ("Tea Time") !
//* Player 2, weighing 329 bytes, "Pai Mu Tan" ("Tea Time") !
//Contestant 1, "Sencha", has won !
//at-h6% ./corewar champs/championships/2018/bcozic/sencha.cor champs/championships/2018/bcozic/pai_mu_tan.cor