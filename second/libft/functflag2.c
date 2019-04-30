/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functflag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:42:37 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 16:52:09 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	functiondigitalu(va_list ap, t_flist *base)
{
	void				*z;
	int					check;
	unsigned long long	checkmin;

	checkmin = 0;
	check = 0;
	z = va_arg(ap, void*);
	ft_checklongitudeu(z, &base, &checkmin);
	ft_checkminu(z, &base, &checkmin);
	if (base->point > 0)
		base->indent = base->indent - base->point;
	//if (base->sign2 == '+')
	//	functionindent5(base, &check);
	if (base->point > 0)
		ft_zerodigital2(&base, checkmin);
	if (base->indent > 0)
	{
		ft_loputnbrindentu(z, base, &check);
		ft_loputnbrindentprintu(base, check);
	}
	ft_uputnbr(z, &base);
	if (base->sign == '-')
		ft_minus2(&base);
}

void	ft_loputnbr(void *z, t_flist **base)
{
	long long			y;
	unsigned long long	a;

	if (((*base)->spec == 1) && (y = (short)z))
		y = (short)y;
	else	if (((*base)->spec == 2) && (y = (long)z))
		y = (long)y;
	else	if ((*base)->spec == 4 && (y = (long long)z))
		y = (long long)y;
	else	if ((*base)->spec == 0 && (y = (int)z))
		y = (int)y;
	else	if ((*base)->spec == 3 && (y = (char)z))
		y = (char)y;
	a = y;
	if (y < 0)
	{
		a = -1 * y;
		ft_putchar('-');
		((*base)->count)++;
	}
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), base);
	ft_putchar((char)(a % 10 + '0'));
	((*base)->count)++;
}

void	functflag4(t_flist *base, int *l, int *biggi)
{
	if (*l == 0)
	{
		base->spec = 2;
		(*biggi)++;
		*l = 1;
	}
	else
		{
			base->spec = 4;
			(*biggi)++;
		}
}

void	functflag3(t_flist *base, int *h, int *biggi)
{
	if (*h == 0)
	{
			if (base->spec != 2 && base->spec != 4)
			{
				base->spec = 1;
				(*biggi)++;
			}
			else
			{
				(*biggi)++;
			}

		*h = 1;
	}
	else
		{
			if (base->spec != 2 && base->spec != 4)
			{
				base->spec = 3;
				(*biggi)++;
			}
			else
			{
				(*biggi)++;
			}
		}
}

void	functflag2(char **p, t_flist *base, int *biggi)
{
	int					i;
	int					h;
	int					l;

	i = 0;
	h = 0;
	l = 0;
	if  (!((**p) >= '0' && (**p) <= '9') && (**p) != ' ')
	{
		while ((*p)[i] && (*p)[i] != '#' && (*p)[i] != '%' && (*p)[i] != '.'
		&& (*p)[i] !='+')
		{
			if ((*p)[i] == 'h' )
			{
				functflag3(base, &h, &(*biggi));
			}
			else	if ((*p)[i] == 'l')
			{
				functflag4(base, &l, &(*biggi));
			}
			else	if ((*p)[i] == 'L')
			{
			 base->spec = 5;
			 (*biggi)++;
			}
			i++;
		}
	}
}
