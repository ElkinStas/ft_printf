/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:31:58 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/17 18:17:54 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(a = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			a[i] = (*f)(s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
