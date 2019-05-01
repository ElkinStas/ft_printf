/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:18:49 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 17:42:51 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_plus1(char **p, t_flist *base)
{
	int	i;

	i = 0;
	(*p)++;
	while (**p == ' ')
	{
		i++;
		(*p)++;
	}
	base->sign2 = '+';
	while (i > 0)
	{
		(*p)--;
		i--;
	}
}

void	ft_minus2(t_flist **base)
{
	if ((*base)->signf > ((*base)->count - (*base)->longitude2))
	{
		(*base)->signf = (*base)->signf -\
			((*base)->count - (*base)->longitude2);
		while ((*base)->signf > 0)
		{
			ft_putchar(' ');
			(*base)->signf--;
			(*base)->count++;
		}
	}
}

void	ft_cage(t_flist *base)
{
	(base)->resh = 1;
}

void	ft_minus1(char **p, t_flist *base)
{
	int	i;
	int	q;

	q = 0;
	(*p)++;
	if ((**p) == '0')
		(*p)++;
	if ((*p)[q] == '#')
	{
		ft_cage(base);
		(*p)++;
	}
	while ((*p)[q] >= '0' && (*p)[q] <= '9')
		q++;
	i = ft_atoi(*p);
	while (q > 0)
	{
		(*p)++;
		q--;
	}
	base->sign = '-';
	base->signf = i;
}

void	ft_text(char **p, t_flist *base)
{
	int	i;
	int	q;

	i = 0;
	q = ft_strlen(*p);
	while (i < q && **p != '%' && **p != '\0')
	{
		ft_putchar(**p);
		(base->count)++;
		(base->longitude2)++;
		i++;
		(*p)++;
	}
}
