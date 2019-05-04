/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:49:03 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/11 14:31:30 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*d;
	unsigned char	*ndl;

	s1 = (unsigned char *)haystack;
	s2 = (unsigned char *)needle;
	if (s1 == s2 || *s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		d = s1;
		ndl = s2;
		while (*s1 == *s2)
		{
			if (s2[1] == '\0')
				return ((char*)d);
			s1++;
			s2++;
		}
		s2 = ndl;
		s1 = d;
		s1++;
	}
	return (NULL);
}
