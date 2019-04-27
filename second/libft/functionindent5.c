/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionindent5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:58:15 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 19:11:01 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_uputnbr(void *z, t_flist **base)
{
	unsigned long long	y;
	unsigned long long	a;

	if (((*base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else	if (((*base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else	if ((*base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else	if ((*base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else	if ((*base)->spec == 3 && (y = (unsigned char)z))
		y = (unsigned char)y;
	a = y;
	if (a >= 10)
		ft_uputnbr((void*)(a / 10), base);

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

	ft_putchar((char)(a % 10 + '0'));
		((*base)->count)++;
	}



}

void	ft_checklongitudeu(void *z, t_flist **base, \
		unsigned long long *checkmin)
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
	while ((*checkmin) != 0)
	{
		(*checkmin) = (*checkmin) / 10;
		(*base)->longitude++;
	}
	(*base)->point = (*base)->point - (*base)->longitude;
}

void	ft_checkminu(void *z, t_flist **base, unsigned long long *checkmin)
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

void	ft_loputnbrindentprintu(t_flist *base, int check)
{
	int					i;

	i = base->indent;
	if (check < i)
	{
		i = i - check;
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

void	functionindent5(t_flist *base, int *check)
{
	if (base->zero == '0')
	{
		ft_putchar('+');
		(base)->count++;
	}
	check++;
}
