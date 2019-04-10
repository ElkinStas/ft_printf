/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:05:13 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/14 13:08:11 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen((char*)s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	if (!(str = ((char*)malloc(sizeof(char) * (size - i + 1)))))
		return (NULL);
	while (s[size] == '\n' || s[size] == '\t' || s[size] == ' ')
		size--;
	while (i <= size)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
