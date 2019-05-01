/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:07:02 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/20 20:02:59 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ququ(int n)
{
	if (n == 1)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long		k;
	int				n;

	i = 0;
	k = 0;
	n = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	if (k < 0)
		return (ft_ququ(n));
	return (k * n);
}
