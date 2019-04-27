/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsixbig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:39:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/24 17:44:48 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	functionsix(va_list ap, t_flist *base)
{
	long long	z;
	int			check;
	long long	checkmin;


	check = 0;
	z = va_arg(ap, long);
	ft_checkminx(z, &base, &checkmin);
	ft_checklongitudex(z, &base, checkmin);
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerodigital2(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		countresh2(z, base, check, checkmin);
	else	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if ((base->resh == 1 && checkmin != 0) && (base->count = base->count + 2))
		ft_putstr("0x");
	ft_putsix(z, &base);
	ft_minus2(&base);
}

void	ft_check_indent3(t_flist **base, unsigned long long y)
{
	if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
	{
		if ((*base)->indent2 != '0')
		{
			ft_putchar(' ');
			((*base)->count)++;
		}
		else if ((y == 0 && (*base)->point2 == '.' && (*base)->point != 0))
			{
				ft_putchar('0');
				((*base)->count)++;
			}
	}
	else	if ((y != 0) || (*base)->point2 != '.'
			|| (y == 0 && (*base)->point2 == '.'))
	{
		ft_convertation2((unsigned long long)y);
		((*base)->count)++;
	}
}

void	ft_putsixbig(long long z, t_flist **base)
{
	unsigned long long y;

	if (((*base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else	if (((*base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else	if ((*base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else	if ((*base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else	if ((*base)->spec == 3 && (y = (char)z))
		y = (unsigned char)y;
	if (y >= 16)
		ft_putsixbig((long long)(y / 16), base);
	y = y % 16;
	ft_check_indent3(base, y);
}

void	countresh(long long z, t_flist *base, int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0')
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

void	functionsixbig(va_list ap, t_flist *base)
{
	long long		z;
	int				check;
	long long		checkmin;

	check = 0;
	z = va_arg(ap, long);
	ft_checkminx(z, &base, &checkmin);
	ft_checklongitudex(z, &base, checkmin);
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerodigitalbig(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		countreshbig(z, base, check, checkmin);
	else	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->resh == 1 && checkmin != 0 && (base->count = base->count + 2))
		ft_putstr("0X");
	ft_putsixbig(z, &base);
	ft_minus2(&base);
}
