/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:43:29 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/14 17:22:58 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;
	int q;

	i = 0;
	q = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) > ft_strlen(s2) || ft_strlen(s1) < ft_strlen(s2))
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	while (s1[i] != '\0' && s2[q] != '\0')
	{
		if (s1[i] == s2[q])
		{
			q++;
		}
		i++;
	}
	if (i == q)
		return (1);
	return (0);
}
