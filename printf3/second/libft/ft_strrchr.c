/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:18:46 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/14 13:09:30 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	y;

	ret = 0;
	y = ft_strlen(s);
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (((unsigned char*)s)[y] != (unsigned char)c)
	{
		y--;
	}
	return ((char*)s + y);
}
