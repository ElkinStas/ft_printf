/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:10:57 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/04/10 19:55:36 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_func_check_signs(char *p, t_flist *base)
{
	char	*ptr;

	ptr = p;
	if (*ptr == '-' && (base->match = 1))
		ft_minus1(&ptr, base);
	if (*ptr == '+' && (base->match = 1))
		ft_plus1(&ptr, base);
	if (*ptr == '#' && (base->match = 1))
		ft_cage(base);
	if (*ptr == ' ' && (base->match = 1))
		ft_space(base);
	if (*p >= '0' && *p <= '9' && base->point2 == '.')
		base->match = 1;
	if (*ptr >= '0' && *ptr <= '9' && base->point2 != '.' && (base->match = 1))
		ft_indent(&ptr, base);
	if (*ptr == '.' && (base->match = 1))
		ft_point(&ptr, base);
	return (ptr);
}

void	ft_func_check_symb1(va_list ap, char *p, t_flist *base)
{
	if ((*p == 'c') && (base->match = 1))
	{
		functionchar(ap, base);
		base->work = 1;
	}
	if (*p == 'p' && (base->match = 1))
	{
		functionpointer(ap, base);
		base->work = 1;
	}
	if (*p == 'f' && (base->match = 1))
	{
		functionfloat(ap, base);
		base->work = 1;
	}
	if (*p == 'u' && (base->match = 1))
	{
		functiondigitalu(ap, base);
		base->work = 1;
	}
	if (*p == '%' && (base->match = 1))
	{
		functionper(base);
		base->work = 1;
	}
}

void	ft_func_check_symb2(va_list ap, char *p, t_flist *base)
{
	if (*p == 's' && (base->match = 1))
	{
		functionstring(ap, base);
		base->work = 1;
	}
	if ((*p == 'd' || *p == 'i') && (base->match = 1))
	{
		functiondigital(ap, base);
		base->work = 1;
	}
	if (*p == 'o' && (base->match = 1))
	{
		functioneight(ap, base);
		base->work = 1;
	}
	if (*p == 'x' && (base->match = 1))
	{
		functionsix(ap, base);
		base->work = 1;
	}
	if (*p == 'X' && (base->match = 1))
	{
		functionsixbig(ap, base);
		base->work = 1;
	}
}

int		ft_search_flags(va_list ap, char *p, t_flist base)
{
	while (*p != '\0')
	{
		base.work = 0;
		if (*p != '%')
			ft_text(&p, &base);
		if (*p != '\0')
			p++;
		while (*p != '\0' && base.work == 0)
		{
			base.match = 0;
			fucnctcheck(&p, &base);
			p = ft_func_check_signs(p, &base);
			ft_func_check_symb1(ap, p, &base);
			ft_func_check_symb2(ap, p, &base);
			if (*p != '\0' && base.match != 0)
				p++;
			else
			{
				break ;
			}
		}
	}
	return (base.count);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	*p;
	t_flist	base;

	ft_create_base(&base);
	va_start(ap, format);
	p = (char *)format;
	base.count = ft_search_flags(ap, p, base);
	va_end(ap);
	return (base.count);
}
