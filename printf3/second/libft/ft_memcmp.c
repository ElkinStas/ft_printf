/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:15:42 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/12 14:31:48 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*a != *b)
		{
			return (*a - *b);
		}
		if (n)
		{
			a++;
			b++;
		}
	}
	return (*a - *b);
}
