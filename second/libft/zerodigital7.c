/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerodigital7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:19:39 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 20:10:33 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_zerodigital3(t_flist **base, long long checkmin, int *flag)
{
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	*flag = 1;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	if ((*base)->indent > 0 && (*base)->sign != '-')
		ft_putstr("0x");
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point - 1;
	while ((*base)->point > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}

void	countreshbig(long long z, t_flist *base, int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0' && base->resh != 1)
		ft_putstr("0X");
	if (base->zero == '0' && base->resh == 1 && base->point < 0)
		ft_putstr("0X");
	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0X");
	base->resh = 0;
}

void	ft_zerodigitalbig(t_flist **base, long long checkmin)
{
	if ((*base)->sign2 == '+' && checkmin > 0 && (*base)->resh != 1)
		(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1 && (*base)->longitude >= (*base)->point)
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
	if ((*base)->resh == 1 && checkmin != 0)
		ft_putstr("0X");
	while ((*base)->point > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}

void	ft_zerooct(t_flist **base, long long checkmin)
{
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1 && (*base)->longitude >= (*base)->point)
		(*base)->indent = (*base)->indent - 2;
	while ((*base)->indent > 0 && (*base)->sign != '-' && checkmin >= 0)
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point - 1;
	if ((*base)->resh == 1 && checkmin != 0 && (*base)->indent >= 0)
	{
		ft_putstr("0");
		(*base)->count++;
		(*base)->longitude++;
	}
	while ((*base)->point > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->longitude++;
		(*base)->point--;
	}
}

void	ft_checkminpointer(long long z, long long *checkmin)
{
	*checkmin = (unsigned long long)z;
	*checkmin = (unsigned long long)*checkmin;
}
