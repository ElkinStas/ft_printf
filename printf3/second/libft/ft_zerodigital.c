/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerodigital.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:56:01 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/10 19:02:59 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_indent(t_flist ***base, unsigned long long a)
{
	if (a == 0 && (**base)->point2 == '.' && (**base)->zero != '0')
	{
		if ((**base)->indent2 != '0')
		{
			ft_putchar(' ');
			((**base)->count)++;
		}
	}
	else if ((a != 0) || (**base)->point2 != '.')
	{
		ft_putchar((char)(a % 10 + '0'));
		((**base)->count)++;
	}
}

void	ft_check_minus_base(t_flist ***base, long long checkmin)
{
	if ((checkmin < 0 && (**base)->zero != '0') || ((**base)->zero == '0' \
				&& (**base)->indent == 0))
	{
		if ((**base)->minus != '-')
		{
			ft_putchar('-');
			((**base)->count)++;
		}
	}
}

void	ft_loputnbrmin(long long z, t_flist **base, long long checkmin)
{
	long long			y;
	unsigned long long	a;

	if (((*base)->spec == 1) && (y = (short)z))
		y = (short)y;
	else if (((*base)->spec == 2) && (y = (long)z))
		y = (long)y;
	else if ((*base)->spec == 4 && (y = (long long)z))
		y = (long long)y;
	else if ((*base)->spec == 0 && (y = (int)z))
		y = (int)y;
	else if ((*base)->spec == 3 && (y = (char)z))
		y = (char)y;
	a = y;
	if (y < 0)
	{
		a = -1 * y;
		ft_check_minus_base(&base, checkmin);
	}
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), base);
	ft_check_indent(&base, a);
}

void	ft_zero_digit_part2(t_flist ***base, int checkmin)
{
	if ((**base)->sign2 == '+' && checkmin > 0)
	{
		ft_putchar('+');
		(**base)->count++;
	}
	if (checkmin < 0)
	{
		ft_putchar('-');
		(**base)->minus = '-';
		(**base)->count++;
	}
	while ((**base)->point > 0)
	{
		ft_putchar('0');
		(**base)->count++;
		(**base)->point--;
	}
}

void	ft_zerodigital(t_flist **base, int checkmin)
{
	if ((*base)->sign2 == '+' && checkmin > 0)
		(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	ft_zero_digit_part2(&base, checkmin);
}
