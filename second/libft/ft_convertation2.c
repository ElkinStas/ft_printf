/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:24:37 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/24 15:58:13 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puteight(long long z, t_flist **base)
{
	unsigned long long	y;
	unsigned long long	a;

	if (((*base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else if (((*base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else if ((*base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else if ((*base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else if ((*base)->spec == 3 && (y = (char)z))
		y = (unsigned char)y;
	a = y;
	if (a >= 8)
		ft_puteight((a / 8), base);
	if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
		ft_indent4(base);
	else if ((y != 0) || (*base)->point2 != '.')
	{
		ft_putchar((char)(a % 8 + '0'));
		((*base)->count)++;
	}
}

void	ft_loputnbrindentuo(long long z, t_flist *base, int *check)
{
	unsigned long long	y;

	if (((base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else if (((base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else if ((base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else if ((base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else if ((base)->spec == 3 && (y = (char)z))
		y = (unsigned char)y;
	if (y >= 8)
		ft_loputnbrindentuo((long long)(y / 8), base, check);
	(*check)++;
}

void	ft_count_resh3(long long z, t_flist *base,\
		int check, long long checkmin)
{
	base->count++;
	check = 1;
	if (base->zero == '0')
		ft_putstr("0");
	if (base->indent > 0)
	{
		ft_loputnbrindentuo(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0");
	base->resh = 0;
}

void	functioneight(va_list ap, t_flist *base)
{
	long long	z;
	int			check;
	long long	checkmin;

	check = 0;
	z = va_arg(ap, long long int);
	ft_checkmin(z, &base, &checkmin);
	ft_checklongitudeo(z, &base, checkmin);
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerodigital2(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		ft_count_resh3(z, base, check, checkmin);
	else if (base->indent > 0)
	{
		ft_loputnbrindentuo(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->resh == 1 && checkmin != 0 && (base->count++))
		ft_putstr("0");
	ft_puteight(z, &base);
	ft_minus2(&base);
}

void	ft_convertation2(long long y)
{
	if (y == 10)
		ft_putchar('A');
	else if (y == 11)
		ft_putchar('B');
	else if (y == 12)
		ft_putchar('C');
	else if (y == 13)
		ft_putchar('D');
	else if (y == 14)
		ft_putchar('E');
	else if (y == 15)
		ft_putchar('F');
	else
		ft_putchar((char)(y % 16 + '0'));
}
