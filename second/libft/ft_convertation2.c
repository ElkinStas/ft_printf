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

void	ft_puteight(long long z, t_flist **base, int checkmin)
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
		ft_puteight((a / 8), base, checkmin);
	if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
		ft_indent4(base);
	else if (((y != 0) || (*base)->point2 != '.') && checkmin != 0)
	{
		ft_putchar((char)(a % 8 + '0'));
		((*base)->count)++;
	}
	else if ((y != 0) || (*base)->point2 != '.'
			|| (y == 0 && (*base)->point2 == '.'))
			{
				ft_putchar('0');
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

	check = 2;
	if (base->zero == '0' && base->resh != 1)
		{
			ft_putstr("0");
			base->count ++;
			}
	if (base->zero == '0' && base->resh == 1 && base->point < 0)
		{
			ft_putstr("0");
			base->count ++;
		}
	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		{
			ft_putstr("0");
			base->count ++;
		}
	base->resh = 0;
}

void	functioneight(va_list ap, t_flist *base)
{
	long long	z;
	int			check;
	long long	checkmin;

	check = 0;
	z = va_arg(ap, long long);
	ft_checkmino(z, &base, &checkmin);
	ft_checklongitudeo(z, &base, checkmin);
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerooct(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		ft_count_resh3(z, base, check, checkmin);
	else if (base->indent > 0)
	{
		ft_loputnbrindentuo(z, base, &check);
		ft_loputnbrindentprintp(base, check, checkmin);
	}
	if (base->resh == 1 && checkmin != 0 && (base->count++))
		ft_putstr("0");
	ft_puteight(z, &base, checkmin);
	ft_minus2(&base);
	base ->resh = 0;

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
