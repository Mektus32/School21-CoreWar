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





t_cor *parse_av(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	t_cor *cor;
	char *name;


	if (!(cor = (t_cor *)ft_memalloc(sizeof(t_cor))))
		exit_print("malloc error");
	cor->nbr_cycles = -1;
	//ft_bzero(cor, sizeof(t_cor));
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



int main(int ac, char **av)
{
	t_cor *cor;

	if (ac > 1)
	{
		cor = parse_av(ac, av);
		arena(cor);
	}
	else
		exit_print("no file");
	return (0);
}
