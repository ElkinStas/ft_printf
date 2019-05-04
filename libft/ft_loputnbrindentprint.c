/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loputnbrindentprint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:42:00 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 17:40:26 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_checklongitudex(long long z, t_flist **base, long long checkmin)
{
	if (((*base)->spec == 1) && (checkmin = (unsigned short)z))
		checkmin = (unsigned short)checkmin;
	else if (((*base)->spec == 2) && (checkmin = (unsigned long)z))
		checkmin = (unsigned long)checkmin;
	else if ((*base)->spec == 4 && (checkmin = (unsigned long long)z))
		checkmin = (unsigned long long)checkmin;
	else if ((*base)->spec == 0 && (checkmin = (unsigned int)z))
		checkmin = (unsigned int)checkmin;
	else if ((*base)->spec == 3 && (checkmin = (unsigned char)z))
		checkmin = (unsigned char)checkmin;
	while ((checkmin) != 0)
	{
		(checkmin) = (checkmin) / 16;
		(*base)->longitude++;
	}
	(*base)->point = (*base)->point - (*base)->longitude;
}

void	ft_checklongitudeo(long long z, t_flist **base, long long checkmin)
{
	if (((*base)->spec == 1) && (checkmin = (short)z))
		checkmin = (short)checkmin;
	else if (((*base)->spec == 2) && (checkmin = (long)z))
		checkmin = (long)checkmin;
	else if ((*base)->spec == 4 && (checkmin = (long long)z))
		checkmin = (long long)checkmin;
	else if ((*base)->spec == 0 && (checkmin = (int)z))
		checkmin = (int)checkmin;
	else if ((*base)->spec == 3 && (checkmin = (unsigned char)z))
		checkmin = (unsigned char)checkmin;
	while ((checkmin) != 0)
	{
		(checkmin) = (checkmin) / 8;
		(*base)->longitude++;
	}
	(*base)->point = (*base)->point - (*base)->longitude;
}

void	ft_indentd2(t_flist **base, int check)
{
	int	i;

	i = (*base)->indent;
	if ((*base)->indent > 0)
	{
		if ((*base)->point2 != '.')
			i = i - check;
		while (i > 0)
		{
			if ((*base)->zero == 1 || (*base)->zero == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			(*base)->count++;
		}
	}
}

void	ft_loputnbrindentu(void *z, t_flist *base, int *check)
{
	unsigned long long	y;

	if (((base)->spec == 1) && (y = (unsigned short)z))
		y = (unsigned short)y;
	else if (((base)->spec == 2) && (y = (unsigned long)z))
		y = (unsigned long)y;
	else if ((base)->spec == 4 && (y = (unsigned long long)z))
		y = (unsigned long long)y;
	else if ((base)->spec == 0 && (y = (unsigned int)z))
		y = (unsigned int)y;
	else if ((base)->spec == 3 && (y = (char)z))
		y = (unsigned char)y;
	if (y >= 10)
		ft_loputnbrindentu((void*)(y / 10), base, check);
	(*check)++;
}

void	ft_loputnbrindentprint(t_flist *base, int check, int checkmin)
{
	int	i;

	i = base->indent;
	if ((base)->indent > 0 && base->space == '1' && checkmin >= 0)
		i--;
	if (check < i)
	{
		i = i - check;
		if (checkmin < 0 && base->zero == '0')
		{
			ft_putchar('-');
			base->count++;
		}
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
