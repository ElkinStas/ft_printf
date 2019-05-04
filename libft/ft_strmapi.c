/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:03:38 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/10 19:21:45 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			a[i] = (*f)(i, s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
