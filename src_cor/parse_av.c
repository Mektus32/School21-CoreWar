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

static void		change_pos(t_cor *cor)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cor->n)
	{
		if (!cor->m_ch[i].code && cor->m_2[j].code)
		{
			cor->m_ch[i] = cor->m_2[j];
			cor->m_ch[i].id = i;
			j++;
		}
		else if (!cor->m_ch[i].code && !cor->m_2[j].code)
			exit_print(cor, "number champ less then flag -n\n");
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
	int		y;

	y = 0;
	if (*i == (ac - 1))
		exit_print(cor, "Can't read source file -dump\n");
	cor->nbr_cyc = 0;
	cor->nbr_cyc = ft_atoi(av[*i + 1]);
	if (cor->nbr_cyc < 0)
		exit_print(cor, "dump must be positive integer or 0\n");
	*i += 2;
}

static void		take_cor_2(int ac, char **av, t_cor *cor, int *i)
{
	static int	j;

	if (!(ft_strcmp("-dump", av[*i])))
		dump_arg(i, cor, ac, av);
	else if (ft_strcmp("-a", av[*i]) == 0)
		set_aff(cor, i);
	else if (ft_strcmp("-n", av[*i]) == 0 && (*i + 2) < ac)
	{
		make_champ_n(av, ++(*i), cor);
		*i += 2;
	}
	else if (ft_strstr(av[*i], ".cor") && j < MAX_PLAYERS)
		valid_champ((*i)++, av, &(cor->m_2[j++]), cor);
	else if (ft_strcmp("-v", av[*i]) == 0 && (*i + 1) < ac
			&& ft_isdigit(av[*i + 1][0]))
		take_flag_v(cor, ft_atoi(av[*i + 1]), i);
	else if (ft_strcmp("-viz", av[*i]) == 0 && ((*i) + 1) < ac)
	{
		cor->visual.vis = 1;
		(*i)++;
	}
	else
		exit_print(cor, "Can't read source file\n");
}

static void		take_cor(int ac, char **av, t_cor *cor)
{
	int i;

	i = 1;
	while (i < ac)
		take_cor_2(ac, av, cor, &i);
}

void			*parse_av(int ac, char **av, t_cor *cor)
{
	int		i;
	char	*name;

	cor->nbr_cyc = -1;
	i = 0;
	while (++i < ac)
		if ((name = ft_strstr(av[i], ".cor")) && name[4] == '\0'
				&& ft_strlen(av[i]) != 4)
			cor->n++;
	if (cor->n > MAX_PLAYERS)
		exit_print(cor, "number players more than MAX_PLAYERS\n");
	take_cor(ac, av, cor);
	change_pos(cor);
	return (cor);
}
