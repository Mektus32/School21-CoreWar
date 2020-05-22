/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:03:28 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 21:01:11 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	close_files(t_assm *assm)
{
	ft_printf("Writing output program to %s\n", assm->name_cor);
	ft_strdel(&assm->name_cor);
	close(assm->fd_cor);
	close(assm->fd_s);
}

int		check_name(char *name)
{
	int	i;
	int	bl;

	i = -1;
	bl = 0;
	while (name[++i])
		if (name[i] == '.')
			bl++;
	if (bl != 1)
		return (1);
	if (name[i - 1] == 's' && name[i - 2] == '.')
		return (0);
	return (1);
}

char	*dot_cor(char *name)
{
	char	*dot_cor;
	size_t	len;

	len = ft_strlen(name);
	dot_cor = ft_strnew(len + 2);
	ft_memcpy(dot_cor, name, len - 1);
	ft_strcat(dot_cor, "cor");
	return (dot_cor);
}

void	open_file_s(t_assm *assm, char *name)
{
	char *tmp;

	if (!((tmp = ft_strstr(name, ".s")) && (name - tmp) != 0
		&& ft_strlen(tmp) == 2))
		sys_error(assm, "Error file name.\n");
	if ((assm->fd_s = open(name, O_RDONLY)) < 0)
		sys_error(assm, "File not opened.\n");
}

void	create_file_cor(t_assm *assm, char *name)
{
	assm->name_cor = dot_cor(name);
	if ((assm->fd_cor = open(assm->name_cor,
			O_WRONLY | O_TRUNC | O_CREAT)) == -1)
		sys_error(assm, "Error create file.\n");
}
