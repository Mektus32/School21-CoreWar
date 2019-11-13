/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:02:02 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 18:56:09 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

void	init(t_diasm *diasm)
{
	diasm->name_cor = NULL;
	diasm->fd_cor = -1;
	diasm->fd_s = -1;
}

void	open_file_cor(t_diasm *diasm, char *name)
{
	char *tmp;

	if ((tmp = ft_strstr(name, ".cor")) && (name - tmp) != 0
			&& ft_strlen(tmp) == 4)
	{
		if (!(diasm->name_cor = ft_strdup(name)))
			sys_err("Error malloc.");
		if ((diasm->fd_cor = open(name, O_RDONLY)) == -1)
			sys_err("File not opened.\n");
	}
	else
		sys_err("Invalid file type.\nUse ./asm namefile.cor\n");
}

char	*dot_s(char *name)
{
	char	*dot_cor;
	size_t	len;

	len = ft_strlen(name);
	dot_cor = ft_strnew(len);
	ft_memccpy(dot_cor, name, '.', len);
	ft_strcat(dot_cor, "dis");
	return (dot_cor);
}

void	create_file_s(t_diasm *diasm)
{
	diasm->name_s = dot_s(diasm->name_cor);
	if (!(diasm->fd_s = open(diasm->name_s, O_WRONLY | O_TRUNC | O_CREAT,
					S_IREAD | S_IWRITE)))
		sys_err("Error create file.\n");
}

void	printf_bit_hex(unsigned char *arr)
{
	int				i;

	i = -1;
	while (++i != 4)
		ft_printf("%02x ", (unsigned char)arr[i]);
}
