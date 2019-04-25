/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countresh2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:19:40 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/24 17:17:41 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convertation(long long y)
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

void	ft_check_indent4(t_flist **base, unsigned long long y)
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
		ft_convertation((unsigned long long)y);
		((*base)->count)++;
	}
}

void	ft_putsix(long long z, t_flist **base)
{
	unsigned long long	y;

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
		ft_putsix((long long)(y / 16), base);
	y = y % 16;
	ft_check_indent4(base, y);
}

void	ft_loputnbrindentux(long long z, t_flist *base, int *check)
{
	unsigned long long	y;

	if (((base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else	if (((base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else	if ((base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else	if ((base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else	if ((base)->spec == 3 && (y = (char)z))
		y = (unsigned char)y;
	if (y >= 16)
		ft_loputnbrindentux((long long)(y / 16), base, check);
	(*check)++;
}

void	countresh2(long long z, t_flist *base, int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0')
		ft_putstr("0x");
	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0x");
	base->resh = 0;
}
