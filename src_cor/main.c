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

void free_cor(t_cor *cor)
{
	int i;

	i = 0;
	free(cor->code);
	free(cor->colormap);
	free(cor->live);
	while(cor->carr)
	{
		remove_curr_if(cor, cor->carr->num);

	}
	while (i < cor->n)
	{
		free(cor->m_2[i]->code);
		//free(cor->m_2[i]->head_c);
		free(cor->m_2[i]);
	//	free(cor->m_ch[i]);
		//free(cor->m_2[i]);
//		if (cor->m_2[i]->code)
//		{
//			free(cor->m_2[i]->code);
//			free(cor->m_2[i]->head_c);
//			free(cor->m_2[i]);
//		}

		i++;
	}
	free(cor);

}

unsigned char read_byte_1(const char *src, int i)
{
	unsigned char	c_1;
	c_1 = src[i % MEM_SIZE];
	return(c_1);
}


short read_byte_2(const char *src, int i)
{
	short			c_2;

	c_2 = src[i % MEM_SIZE];
	c_2 = c_2 << 8;
	c_2 = c_2 | src[(i+1) % MEM_SIZE];
	return(c_2);
}

unsigned int read_byte_4(const char *src, int i)
{
	unsigned int			c_4;

	c_4 = 0;
	c_4 = (c_4 << 8);
	c_4 = c_4 | (src[(i) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (src[(i + 1) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (src[(i + 2) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (src[(i + 3) % MEM_SIZE]);
//	c_4 = (c_4 << 8) | (src[(i + 2) % MEM_SIZE]);
//	c_4 = (c_4 << 8) | (src[(i + 1) % MEM_SIZE]);
//	c_4 = (c_4 << 8) | (src[(i) % MEM_SIZE]);
	return ((unsigned int)c_4);
}
//возможно три случая
// 1 - получить номер регистра (1 байт)
// 2 - получтить ссылку (2 байт)
// 3 - получить 4 байта
//
//void *read_byte(const char *src, int i, int c)
//{
//	unsigned char	c_1;
//	short			c_2;
//	unsigned int	c_4;
//
//	if (c == 1)
//	{
//		c_1 = src[i % MEM_SIZE];
//		return(c_1);
//	}
//	else if (c == 2)
//	{
//		c_2 = src[(i + 1) % MEM_SIZE];
//		c_2 = c_2 << 8;
//		c_2 = c_2 | src[(i) % MEM_SIZE];
//		return ((short)c_2);
//	}
//	else if (c == 4)
//	{
//		c_4 = 0;
//		c_4 = c_4 << 8 | (src[(i + 3) % MEM_SIZE]);
//		c_4 = c_4 << 8 | (src[(i + 2) % MEM_SIZE]);
//		c_4 = c_4 << 8 | (src[(i + 1) % MEM_SIZE]);
//		c_4 = c_4 << 8 | (src[(i) % MEM_SIZE]);
//
//		return ((unsigned int)c_4);
//	}
//	else
//		return (0);
//}


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



/*
 * копирование в зависимости индекса от MEM_SIZE,
 * округлять нужна оба
 * */
//void	*ft_memcpy_all(void *dst, const void *src, size_t n, int start_s, int start_d)
//{
//	unsigned char		*str1;
//	unsigned char	*str2;
//	int					i;
//
//
//	str1 = (unsigned char *)dst;
//	str2 = src;
//	i = 0;
//
//	if (!src)
//	{
//		while (n-- > 0)
//		{
//			str1[(start_d + i) % MEM_SIZE] = 0;
//			i++;
//		}
//	}
//	else
//	{
//		while (n-- > 0)
//		{
//			//c = str2[(i + start_s) % MEM_SIZE];
//			str1[(i + start_d) % MEM_SIZE] = str2[(i + start_s) % MEM_SIZE];
//			//str1[i] = src + i;
//			i++;
//		}
//	}
//	dst = str1;
//	return (dst);
//}

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

	t_champ *ch;
	unsigned char	c[4];
	size_t st;

	ch = (t_champ*)malloc(sizeof(t_champ));
	st = read(fd, &c, 4); // COREWAR_EXEC_MAGIC
	ch->magic = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
	st = read(fd, (ch->prog_name), PROG_NAME_LENGTH);
	ch->prog_name[PROG_NAME_LENGTH + 1] = '\0';
	// теперь NULL ссчитываем
	st = read(fd, &c, 4);
	if (c[0] || c[1] || c[2] || c[3] || st != 4) // оригинал не проверяет на NULL
		exit_print("no NULL in name");
	// Bot size
	st = read(fd, &c, 4);
	ch->prog_size = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];

	//printf("champ->magic = %x, champ->prog_name = %s\n, champ->prog_size = %d\n", champ->magic, champ->prog_name, champ->prog_size);


	if (ch->prog_size > CHAMP_MAX_SIZE)
	{
		exit_print("File has a code size that differ from what its header says");
	}
	else
	{
		st = read(fd, &(ch->comment), COMMENT_LENGTH);
		if (st != COMMENT_LENGTH)
			exit_print("error comment");
		ch->comment[COMMENT_LENGTH + 1] = '\0';

		//	printf("com = %s\n",champ->comment );

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

	//printf("valid_champ: av[%d] = %s\n", i, av[i]);
	if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0' && ft_strlen(av[i]) != 4 )
	{

		//printf("name = %s\n", av[i]);
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
		//-n number
		//sets the number of the next player. If non-existent, the player will have the next
		//available number in the order of the parameters. The last player will have the first
		//process in the order of execution
		i = 0;
		while (cor->m_2[i])
			i++;
		cor->m_2[i] = valid_champ(++n, av);
	}
}


t_cor *parse_av(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	t_cor *cor;
	char *name;


	if (!(cor = (t_cor *)malloc(sizeof(t_cor))))
		exit_print("malloc error");
	cor->nbr_cycles = -1;
	ft_bzero(cor, sizeof(t_cor));
	//cor->n = 0;
	i = 1;
	while (i < ac)
	{
		if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0' && ft_strlen(av[i]) != 4)
			cor->n++;
		i++;
	}
	if (cor->n > MAX_PLAYERS)
		exit_print("number players more than MAX_PLAYERS\n");
	i = 1;
//	while (i < ac)
//	{
//		if (ft_strcmp("-n", av[i])))
//		{
//			j = ft_atoi(av[++i]);
//			if (j && j <= cor->n)
//			{
//				if (cor->f[j - 1] == 0)
//					cor->f[j - 1] = 1;
//				else
//					exit_print("number not unique");
//			}
//			else
//				exit_print("number not valid"); // число больше кол - ва чемпионов или = 0
//		}
//		i++;
//	}
	i = 1;
	j = 0;
	while (i < ac)
	{

		if (!(ft_strcmp("-dump", av[i])))
		{
			if (i == (ac - 1))
				exit_print("Can't read source file -dump");
			cor->nbr_cycles = 0;
			cor->nbr_cycles = ft_atoi(av[i + 1]);


			i+=2;
		}
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
		b2[i] = c % 2;
		c = c/2;
		i--;
	}
	return  (b2);

}

char *base16_2_cor(t_cor *cor, t_carr *tmp)
{
	unsigned char	*k;

	k = malloc(sizeof(char));
	ft_memcpy(k, cor->code + (tmp->cur + 1) % MEM_SIZE, 1);
	free(k);
	return  (base16_2(k[0]));

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
	char *code_i;

	cor->code = (char *)malloc(sizeof(char) * MEM_SIZE);
	cor->live = (t_live *)malloc(sizeof(t_live));

	ft_memset(cor->code, 0, sizeof(char) * MEM_SIZE);
	//cor->code[MEM_SIZE + 1] = '\0';

	cor->colormap = (int*)malloc(sizeof(int) * MEM_SIZE);
	i = 0;
	while (i < cor->n)
	{
		code_i = cor->code + i * (MEM_SIZE / cor->n);
		ft_strncpy_all((code_i), cor->m_ch[i]->code, cor->m_ch[i]->prog_size);
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
				  (cor->m_ch[i])->prog_size, (cor->m_ch[i])->prog_name,
				  (cor->m_ch[i])->comment);
		i++;
	}
//	ft_printf("=============\n");
//	print_dump_code(cor);
//	ft_printf("=============\n");
	go_cor(cor);
	ft_printf("Contestant %d, \"%s\", has won !", cor->live->id_live, (cor->m_ch[cor->live->id_live - 1])->prog_name);
	free_cor(cor);

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
//../vm_champs/champs/championships/2018/bcozic/sencha.cor
//at-r2% ./asm champs/championships/2018/sboulet/NoIdea.s
//Writing output program to champs/championships/2018/sboulet/NoIdea.cor
//at-r2% ./corewar champs/championships/2018/sboulet/Hidden.cor champs/championships/2018/sboulet/NoIdea.cor champs/championships/2018/bcozic/sencha.cor
//Introducing contestants...
//./corewar champs/championships/2018/sboulet/Hidden.cor champs/championships/2018/sboulet/NoIdea.cor champs/championships/2018/bcozic/sencha.cor


//./corewar -dump 15 ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/sboulet/Hidden.cor ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/sboulet/NoIdea.cor ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/bcozic/sencha.cor
//./corewar  ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/sboulet/Hidden.cor ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/sboulet/NoIdea.cor ~/Desktop/corwar_1/arina/vm_champs/champs/championships/2018/bcozic/sencha.cor
//./cor_1 vm_champs/champs/championships/2018/sboulet/Hidden.cor vm_champs/champs/championships/2018/sboulet/NoIdea.cor vm_champs/champs/championships/2018/bcozic/sencha.cor