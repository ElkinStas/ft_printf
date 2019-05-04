/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:36:25 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/05/01 22:40:54 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_loputnbrindent_float(t_flist *base, int check, int checkmin)
{
	int	i;

	i = base->indent;
	if ((base)->indent > 0 && base->space == '1' && checkmin >= 0)
		i--;
	if (check < i)
	{
		i = i - base->longitude - check;
		if (checkmin < 0 && base->zero == '0')
		{
			ft_putchar('-');
			base->count++;
		}
		while (i > 0 && base->sign != '-')
		{
			if ((base->zero == '0' && (base->sign2 == '0')) || base->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			base->count++;
		}
	}
}

void	float_convertation(va_list ap, t_flist *base, long double *f)
{
	if (base->spec == 0)
		*f = va_arg(ap, double);
	else if (base->spec == 2)
		*f = va_arg(ap, double);
	else if (base->spec == 5)
		*f = va_arg(ap, long double);
}

void	functionfloat(va_list ap, t_flist *base)
{
	int			i;
	long double	f;
	int			cop;
	int			count;
	int			check;

	check = 0;
	f = 0.0;
	float_convertation(ap, base, &f);
	floatconvert(&f, &base, &cop);
	i = ft_single_part(f);
	count = ft_count_sympoint(f, base);
	base->longitude = i + count + 1;
	base->point = base->point - base->longitude;
	ft_check_sign(&base, cop, &check);
	if (base->indent > 0)
		ft_loputnbrindent_float(base, check, cop);
	if (base->sign2 == '+' && cop >= 0 && base->zero != '0' && (base)->count++)
		ft_putchar('+');
	i = i + ft_print_accuracy(f, count);
	if (i == 0)
		i = 1;
	base->count = base->count + i + count + 1;
	if (base->sign == '-')
		ft_minus2(&base);
}
