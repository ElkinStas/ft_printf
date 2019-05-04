/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:36 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/13 14:53:04 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	size;

	i = 0;
	n = 0;
	size = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (needle[size])
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i] && (size + i) <= len)
	{
		while (needle[n] == haystack[i + n])
		{
			if (n == size - 1)
				return ((char *)haystack + i);
			n++;
		}
		n = 0;
		i++;
	}
	return (NULL);
}
