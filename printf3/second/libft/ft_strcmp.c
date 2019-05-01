/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:24:21 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/11 14:34:54 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	while (a[i] == b[i])
	{
		if (a[i] == '\0' && b[i] == '\0')
		{
			return (a[i] - b[i]);
		}
		i++;
	}
	return (a[i] - b[i]);
}
