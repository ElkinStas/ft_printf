/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:57:38 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/14 13:06:33 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*y;
	char	*x;
	size_t	i;

	i = 0;
	if (!(y = malloc(sizeof(char) * (size + 1))))
	{
		return (NULL);
	}
	x = y;
	while (size > i)
	{
		*y = '\0';
		y++;
		size--;
	}
	*y = '\0';
	return (x);
}
