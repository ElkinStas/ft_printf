/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:18:51 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/18 14:24:06 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int s)
{
	size_t			r;

	r = 0;
	while (s >= 10)
	{
		s = s / 10;
		r++;
	}
	return (r);
}

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	p;
	size_t			a;

	p = n;
	a = 0;
	if (n < 0)
	{
		p = (-1) * n;
		a++;
	}
	a = a + ft_count(p);
	if (!(s = malloc(sizeof(char) * (a + 2))))
		return (NULL);
	s[++a] = '\0';
	if (n < 0)
		s[0] = '-';
	while (p >= 10)
	{
		s[--a] = p % 10 + '0';
		p = p / 10;
	}
	s[--a] = p % 10 + '0';
	return (s);
}
