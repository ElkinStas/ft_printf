/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:59:23 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 16:09:08 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	fucnctcheck(char **p, t_flist *base)
{
	int					biggi;

	biggi = 0;
	functflag2(p, base,&biggi);
	if ((base->spec == 1 || base->spec == 5 || base->spec == 2)\
			&& (base->match = 1))
		(*p)= (*p) + biggi;
	if ((base->spec == 3 || base->spec == 4) && (base->match = 1))
		(*p)= (*p) + biggi;
}

void	ft_checkstr(char *sval, int *check)
{
	*check = 0;
	while (*sval)
	{
		(*check)++;
		sval++;
	}
}

void	ft_printtext(char *sval, t_flist *base, int check)
{
	ft_checkstr(sval, &check);
	if (base->point > 0 && check != 0)
	{
		base->indent = base->indent - base->point;
		if (check != 0)
			check = base->point;
	}
	if (base->indent > 0)
		ft_indentd2(&base, check);
	while (check > 0)
	{
		ft_putchar(*sval);
		sval++;
		check--;
		(base->count)++;
	}
	if (base->sign == '-')
		ft_minus2(&base);
}

void	functionstring(va_list ap, t_flist *base)
{
	char	*sval;
	int		check;

	check = 0;
	sval = va_arg(ap, char *);
	if (sval == NULL)
	{
		ft_putstr("(null)");
		(base->count) = (base->count) + 6;
	}
	else
		ft_printtext(sval, base, check);
}

void	ft_indent4(t_flist **base)
{
	if ((*base)->indent2 != '0' && (*base)->resh != 1)
	{
		ft_putchar(' ');
		((*base)->count)++;
	}
	else if ((*base)->resh == 1)
	{
		ft_putchar('0');
		((*base)->count)++;
	}
}
