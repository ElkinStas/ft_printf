/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:36:25 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 15:38:57 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	functionfloat(va_list ap, t_flist *base)
{
	long long	checkmin;
	int			i;
	long double	f;
	int			cop;
	int			count;

	count = 0;
	i = 0;
	f = 0.0;
	if (base->spec == 0)
		f = va_arg(ap, double);
	else if (base->spec == 2)
		f = va_arg(ap, double);
	else if (base->spec == 5)
		f = va_arg(ap, long double);
	floatconvert(&f, &base);
	i = ft_single_part(f);
	cop = (int)f;
	ft_checkmin(cop, &base, &checkmin);
	count = ft_count_sympoint(f, base);
	i = i + ft_print_accuracy(f, count);
	if (i == 0)
		i = 1;
	base->count = base->count + i + count + 1;
}
