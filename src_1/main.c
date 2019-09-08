/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:41:11 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/02 19:41:12 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_exit(char *line)
{
	ft_printf("%s\n", line);
	ft_printf("ERROR\n");
	exit(0);
	return (0);
}

void print_name(char *name)
{
	int i;
	i = 1;
	int f;

	f = 1;

	while (i < PROG_NAME_LENGTH - 1)
	{
		if (f && name[i] && name[i] != '"')
			{
				//printf("%c", name[i]);
				printf("%x", name[i]);
			}
		else if (name[i] == '"')
			{
				f = 0;
				i++;
			}
		else
			printf("0");
		if ((8 + i) % 32 == 0)
			printf("\n");
		else if (i % 4 == 0)
			printf(" ");
		i++;

	}
	printf("\n\n");
}

void check_asm(int fd)
{
	char *line;
	char *line_2;
	char *line_3;

	while (get_next_line(fd, &line) == 1)
	{
		//ft_printf("line = %s\n", line);
		if (ft_strstr(line, NAME_CMD_STRING))
			{

				ft_printf(".name tut = %s\n", line);
				if ((line_2 = ft_strchr(line, '"')))
				{
					if ((line_3 = ft_strchr(line_2 + 1, '"')))
						print_name(line_2);
				}
				
			}
		else if (ft_strstr(line, COMMENT_CMD_STRING))
		{
			ft_printf("LINE _com = %s\n", line);

		}
		free(line);
	}
	//return (0);
}

int main(int ac, char **av)
{
	int	fd;
	int i;

	if (ac >= 2)
	{
		i = 1;
		// если больше одного файла нв вход asm - ошибка?
		while (i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) > 0)
				check_asm(fd);
			else
			{
				ft_printf("file %s", av[i]);
				ft_exit("can't read ");
			}
			i++;
		}
	}
	else
		ft_exit("no file or ");
	return (0);
}


