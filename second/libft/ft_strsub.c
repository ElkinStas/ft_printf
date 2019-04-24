/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:34:47 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/17 18:23:43 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	if (s == NULL)
		return (str);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[i] = s[i + start];
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
