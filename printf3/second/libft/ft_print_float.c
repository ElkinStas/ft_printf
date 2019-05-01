/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:41 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 15:34:33 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr2(long long n)
{
	unsigned long long	a;

	if (n < 0)
		a = -1 * n;
	else
		a = n;
	if (a >= 10)
		ft_putnbr2(a / 10);
	ft_putchar((char)(a % 10 + '0'));
}

int		ft_check_last_symb(long double fl, int len)
{
	long long			per;
	long long			sum;
	int					ar;
	int					b;

	b = 0;
	while (len)
	{
		fl = fl * 10;
		sum = (long long)fl;
		if (len == 1)
		{
			fl = fl * 10;
			per = (long long)fl;
			if (per % 10 > 4)
				b = 1;
		}
		ar = sum % 10 + b;
		if (ar == 10)
			return (1);
		len--;
	}
	return (0);
}

void	floatconvert(long double *z, t_flist **base)
{
	if ((*base)->spec == 2)
		(*z) = (double)(*z);
	else	if ((*base)->spec == 5)
		(*z) = (long double)(*z);
	else	if ((*base)->spec == 0)
		(*z) = (float)(*z);
}

int		ft_print_float3(int **count, long long per)
{
	int	c;

	c = 0;
	if ((**count) == 0)
	{
		ft_putnbr2(per + 1);
		if (per % 10 == 9)
			c = 1;
		ft_putchar('.');
		(**count)++;
	}
	else
	{
		ft_putnbr2(per);
		ft_putchar('.');
	}
	return (c);
}

int		ft_print_float(int *count, long long per, int *len, long double fl)
{
	int					c;
	int					ar;
	long long			sum;
	int					b;

	b = 0;
	c = ft_print_float3(&count, per);
	while (len && ((*count) > 0))
	{
		fl = fl * 10;
		sum = (long long)fl;
		if (*count == 1 && (*len) != 1)
			b = 1;
		ar = sum % 10 + b;
		if (ar == 10)
			ft_putchar('0');
		else
			ft_putchar(ar + '0');
		(*len)--;
		(*count)--;
	}
	return (c);
}
