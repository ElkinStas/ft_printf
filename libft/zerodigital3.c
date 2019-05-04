/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerodigital3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:05:52 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 17:07:57 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convertationpointer(unsigned long long y)
{
	if (y == 10)
		ft_putchar('a');
	else	if (y == 11)
		ft_putchar('b');
	else	if (y == 12)
		ft_putchar('c');
	else	if (y == 13)
		ft_putchar('d');
	else	if (y == 14)
		ft_putchar('e');
	else	if (y == 15)
		ft_putchar('f');
	else
		ft_putchar((char)(y % 16 + '0'));
}

void	ft_check_indent5(t_flist **base, unsigned long long y)
{
	if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
	{
		if ((y == 0 && (*base)->point2 == '.' && (*base)->point != 0))
		{
			ft_putchar('0');
			((*base)->count)++;
		}
	}
	else	if ((y != 0) || (*base)->point2 != '.'
			|| (y == 0 && (*base)->point2 == '.'))
	{
		ft_convertationpointer((unsigned long long)y);
		((*base)->count)++;
	}
}

void	ft_put_pointer(unsigned long long z, t_flist **base)
{
	unsigned long long	y;

	y = (unsigned long long)z;
	if (y >= 16)
		ft_put_pointer((y / 16), base);
	y = y % 16;
	ft_check_indent5(base, y);
}

void	ft_pointer(va_list ap, t_flist *base)
{
	void		*z;
	int			check;
	long long	checkmin;
	int			flag;

	check = 0;
	flag = 0;
	z = va_arg(ap, void*);
	ft_checkminpointer((long long)z, &checkmin);
	ft_checklongitudepointerpr(&base, checkmin);
	base->resh = 1;
	if (z == 0 && base->indent > 0)
		base->indent = base->indent - 2;
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerodigital5(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		ft_countresh_p((unsigned long long)z, base, check, checkmin);
	else	if (base->indent > 0)
		ft_starpo((long long)z, base, check, checkmin);
	if ((base->resh == 1) && (base->count = base->count + 2))
		ft_putstr("0x");
	ft_put_pointer((unsigned long long)z, &base);
	ft_minus_p(&base);
}

void	ft_checkmino(long long z, t_flist **base, long long *checkmin)
{
	if (((*base)->spec == 1) && (*checkmin = (short)z))
		*checkmin = (short)*checkmin;
	else	if (((*base)->spec == 2) && (*checkmin = (long)z))
		*checkmin = (long)*checkmin;
	else	if ((*base)->spec == 4 && (*checkmin = (long long)z))
		*checkmin = (long long)*checkmin;
	else	if ((*base)->spec == 0 && (*checkmin = (int)z))
		*checkmin = (int)*checkmin;
	else	if ((*base)->spec == 3 && (*checkmin = (unsigned char)z))
		*checkmin = (unsigned char)*checkmin;
}
