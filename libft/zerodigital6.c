/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerodigital6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:14:44 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 22:21:40 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_checklongitudepointerpr(t_flist **base, long long checkmin)
{
	checkmin = (unsigned long long)checkmin;
	while ((checkmin) != 0)
	{
		(checkmin) = (checkmin) / 16;
		(*base)->longitude++;
	}
	if ((*base)->sign2 == '+' && (*base)->sign == '-' &&\
		checkmin >= 0 && (*base)->space == '1')
	{
		if (((*base)->point > 0) && ((*base)->indent > 0))
			;
		else
		{
			ft_putchar(' ');
			(*base)->count++;
		}
	}
	(*base)->point = (*base)->point - (*base)->longitude;
}

void	ft_zerodigital5(t_flist **base, long long checkmin)
{
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1)
		(*base)->indent = (*base)->indent - 2;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point - 1;
	if ((*base)->resh == 1)
	{
		ft_putstr("0x");
		(*base)->resh = 0;
		(*base)->count = (*base)->count + 2;
	}
	while ((*base)->point-- > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
	}
}

void	ft_minus_p(t_flist **base)
{
	if ((*base)->signf > (*base)->longitude)
	{
		(*base)->signf = (*base)->signf - (*base)->longitude - 2;
		while ((*base)->signf > 0)
		{
			ft_putchar(' ');
			(*base)->signf--;
			(*base)->count++;
		}
	}
}

void	ft_loputnbr_p(long long z, t_flist *base, int *check)
{
	unsigned long long	y;

	y = (unsigned long long)z;
	y = (unsigned long long)y;
	if (y >= 16)
		ft_loputnbr_p((long long)(y / 16), base, check);
	(*check)++;
}

void	ft_countresh_p(unsigned long long z, t_flist *base,\
		int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0' && base->resh != 1)
		ft_putstr("0x");
	if (base->zero == '0' && base->resh == 1 && base->point < 0)
		ft_putstr("0x");
	if (base->indent > 0)
	{
		ft_loputnbr_p(z, base, &check);
		ft_loputnbrindentprintp(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0x");
	base->resh = 0;
}
