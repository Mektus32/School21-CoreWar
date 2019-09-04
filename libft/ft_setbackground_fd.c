/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbackground_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:30:15 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/14 13:33:38 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setbackground_fd(int backg, int fd)
{
	if (backg < 0 || backg > 7)
		return ;
	ft_putstr_fd("\033[4", fd);
	ft_putchar_fd('0' + (char)backg, fd);
	ft_putchar_fd('m', fd);
}
