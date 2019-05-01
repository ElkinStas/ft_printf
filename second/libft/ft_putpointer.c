/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:44:55 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/01 17:41:21 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_sign(t_flist **base, long long checkmin, int *check)
{
	if ((*base)->point > 0)
		(*base)->indent = (*base)->indent - (*base)->point;
	if ((*base)->sign2 == '+' && checkmin >= 0)
	{
		if ((*base)->zero == '0' && (*base)->point2 == '0')
		{
			ft_putchar('+');
			(*base)->count++;
		}
		(*check)++;
	}
	if ((*base)->sign2 != '+' && checkmin >= 0 && (*base)->space == '1')
	{
		if (((*base)->point > 0) && ((*base)->indent > 0))
			;
		else
		{
			ft_putchar(' ');
			(*base)->count++;
		}
	}
}

void	functiondigital(va_list ap, t_flist *base)
{
	long long		z;
	int				check;
	long long		checkmin;

	check = 0;
	checkmin = 0;
	z = va_arg(ap, long long);
	ft_checklongitude(z, &base, &checkmin);
	ft_checkmin(z, &base, &checkmin);
	ft_check_sign(&base, checkmin, &check);
	if (base->point > 0)
		ft_zerodigital(&base, checkmin);
	if (base->indent > 0)
	{
		ft_loputnbrindent(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->sign2 == '+' && checkmin >= 0 && base->zero != '0')
	{
		ft_putchar('+');
		(base)->count++;
	}
	ft_loputnbrmin(z, &base, checkmin);
	if (base->sign == '-')
		ft_minus2(&base);
}

void	functionper(t_flist *base)
{
	if (base->indent > 0)
		ft_indentdchar(&base);
	ft_putchar('%');
	base->longitude++;
	base->count++;
	ft_minus2(&base);
}

void	ft_starpo(long long z, t_flist *base, int check, long long checkmin)
{
	ft_loputnbr_p((long long)z, base, &check);
	ft_loputnbrindentprintp(base, check, checkmin);
}
