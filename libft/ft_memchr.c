/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:22:11 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/11 14:22:53 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char*)s;
	while (n--)
	{
		if (*d == (unsigned char)c)
		{
			return (d);
		}
		if (n)
		{
			d++;
		}
	}
	return (NULL);
}
