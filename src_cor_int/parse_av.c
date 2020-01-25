/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:58:09 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/12 17:01:46 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** чемпиона с флагом сразу запичываем на позицию
** без флага добавляем в m_2,потом записываем на свободное мечсто и удаляем
** copy_champ - копирует все данные чемпиона
** change_pos - заполняет пропущенные позиции в m_ch
** take_cor - заполняет два массива с флагом и без
*/

static t_champ	*copy_champ(t_champ *ch_2)
{
	t_champ	*new;
	int		i;

	if (!(new = (t_champ*)ft_memalloc(sizeof(t_champ))))
	    exit_print("Error allocate memory");
	new->code = ft_strnew(ch_2->prog_size);
	ft_strncpy_all(new->code, ch_2->code, ch_2->prog_size);
	free(ch_2->code);
	new->id = ch_2->id;
	new->prog_size = ch_2->prog_size;
	new->magic = ch_2->magic;
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		new->prog_name[i] = ch_2->prog_name[i];
		i++;
	}
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		new->comment[i] = ch_2->comment[i];
		i++;
	}
	return (new);
}

static void		change_pos(t_cor *cor)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cor->n)
	{
		if (!cor->m_ch[i] && cor->m_2[j])
		{
			cor->m_ch[i] = copy_champ(cor->m_2[j]);
			free(cor->m_2[j]);
			cor->m_ch[i]->id = i;
			j++;
		}
		else if (!cor->m_ch[i] && !cor->m_2[j])
			exit_print("number champ less then flag -n");
		i++;
	}
}

/*
** 		{
**			ft_putstr_fd("Can't read source file ", 2);
**			exit_print(av[i]);
**		}
*/

static void		dump_arg(int *i, t_cor *cor, int ac, char **av)
{
	if (*i == (ac - 1))
		exit_print("Can't read source file -dump");
	cor->nbr_cyc = 0;
	cor->nbr_cyc = ft_atoi(av[*i + 1]);
	*i += 2;
}

static void		take_cor(int ac, char **av, t_cor *cor)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!(ft_strcmp("-dump", av[i])))
			dump_arg(&i, cor, ac, av);
		else if (ft_strcmp("-n", av[i]) == 0 && (i + 2) < ac)
		{
			make_champ_n(ac, av, ++i, cor);
			i += 2;
		}
		else if (ft_strstr(av[i], ".cor") && j < MAX_PLAYERS)
			cor->m_2[j++] = valid_champ(i++, av);
		else if (ft_strcmp("-v", av[i]) == 0)
		{
			cor->visual.vis = 1;
			i++;
		}
		else
			exit_print("Can't read source file");
	}
}

t_cor			*parse_av(int ac, char **av)
{
	int		i;
	t_cor	*cor;
	char	*name;

	if (!(cor = (t_cor *)ft_memalloc(sizeof(t_cor))))
		exit_print("malloc error");
	cor->nbr_cyc = -1;
	i = 1;
	while (i < ac)
	{
		if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0'
				&& ft_strlen(av[i]) != 4)
			cor->n++;
		i++;
	}
	if (cor->n > MAX_PLAYERS)
		exit_print("number players more than MAX_PLAYERS");
	else if (cor->n == 0)
	    exit_print("number players less one");
	take_cor(ac, av, cor);
	change_pos(cor);
	return (cor);
}
