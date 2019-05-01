/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerodigital2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:55:12 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 15:59:16 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_checkminx(long long z, t_flist **base, long long *checkmin)
{
	if (((*base)->spec == 1) && (*checkmin = (unsigned short)z))
		*checkmin = (unsigned short)*checkmin;
	else	if (((*base)->spec == 2) && (*checkmin = (unsigned long)z))
		*checkmin = (unsigned long)*checkmin;
	else	if ((*base)->spec == 4 && (*checkmin = (unsigned long long)z))
		*checkmin = (unsigned long long)*checkmin;
	else	if ((*base)->spec == 0 && (*checkmin = (unsigned int)z))
		*checkmin = (unsigned int)*checkmin;
	else	if ((*base)->spec == 3 && (*checkmin = (unsigned char)z))
		*checkmin = (unsigned char)*checkmin;
}

void	ft_zerodigital2(t_flist **base, long long checkmin)
{
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
	{
		ft_putstr("0x");
		(*base)->longitude = (*base)->longitude + 2;
	}
	while ((*base)->point > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}

void	ft_loputnbrindentprintp(t_flist *base, int check, int checkmin)
{
	int	i;

	i = base->indent;
	if (check < i)
	{
		i = i - check;
		if (checkmin < 0 && base->zero == '0')
		{
			ft_putchar('-');
			base->count++;
		}
		while (i > 0 && base->sign != '-')
		{
			if (base->zero == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			base->count++;
		}
	}
}

void	ft_pointerindent(t_flist *base, int check, int *flag)
{
	int	i;

	i = base->indent;
	if (check < i)
	{
		i = i - check;
		*flag = 1;
		if (base->zero == '0')
			ft_putstr("0x");
		while (i > 0 && base->sign != '-')
		{
			if (base->zero == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			base->count++;
		}
		if (base->zero != '0')
			ft_putstr("0x");
	}
}
