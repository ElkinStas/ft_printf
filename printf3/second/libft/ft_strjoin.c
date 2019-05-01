/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:13:16 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/27 19:31:13 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check1(char *s1)
{
	size_t	j;
	char	*str;
	char	*g;

	j = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(*str) * j + 1)))
		return (NULL);
	g = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	*str = '\0';
	return (g);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	char	*str;
	char	*g;

	if (s1 && !s2)
		return (ft_check1((char*)s1));
	else if (!s1 && s2)
		return (ft_check1((char *)s2));
	else if (s1 && s2)
	{
		j = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char*)malloc(sizeof(*str) * j + 1)))
			return (NULL);
		g = str;
		while (*s1 != '\0')
			*str++ = *s1++;
		while (*s2 != '\0')
			*str++ = *s2++;
		*str = '\0';
		return (g);
	}
	return (NULL);
}
