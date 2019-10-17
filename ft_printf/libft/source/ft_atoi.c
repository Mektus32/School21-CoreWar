/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:52:52 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 14:52:54 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_max_long_int(long int res, int minus, char c)
{
	if ((res > 922337203685477580 || (res == 922337203685477580 &&
			((c - '0') > 7))) && (minus == 1))
		return (1);
	else if ((res > 922337203685477580 || (res == 922337203685477580 &&
			((c - '0') > 8))) && (minus == -1))
		return (2);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long int	res;
	int					minus;

	minus = 1;
	res = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		minus = -1;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1] >= '0' &&
		str[i + 1] <= '9'))
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (ft_max_long_int(res, minus, str[i]) == 1)
			return (-1);
		else if (ft_max_long_int(res, minus, str[i]) == 2)
			return (0);
		res = str[i++] - '0' + res * 10;
	}
	return (minus * res);
}
