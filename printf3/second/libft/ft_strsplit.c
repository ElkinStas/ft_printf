/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:23:08 by bhudson           #+#    #+#             */
/*   Updated: 2019/02/13 17:57:59 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_schetun(char *s, char c)
{
	int		slova;
	int		i;

	slova = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			slova++;
			i++;
			if (s[i] == '\0')
				return (slova);
		}
		i++;
	}
	return (slova);
}

static char			*ft_dvigun(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s != c && ((*(s - 1)) == c || (!(*(s - 1)))))
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}

static char			*ft_pamat(const char *z, char *a, char c)
{
	int		i;

	i = 0;
	if (*z != '\0')
	{
		while (z[i] != c && z[i] != '\0')
		{
			i++;
		}
		if (!(a = (char*)malloc(sizeof(char) * i + 1)))
		{
			while (i-- != 0)
				free(&a[i]);
			free(a);
			return (NULL);
		}
		a[i] = '\0';
		while (i--)
		{
			a[i] = z[i];
		}
		return (a);
	}
	else
		return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**masukaz;
	char	*temp;
	int		j;
	int		y;

	temp = (char*)s;
	if (!s)
		return (NULL);
	j = ft_schetun((char*)s, c);
	if (!(masukaz = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	y = j;
	j = 0;
	while (j < y)
	{
		temp = ft_dvigun(temp, c);
		masukaz[j] = ft_pamat(temp, masukaz[j], c);
		j++;
		temp++;
	}
	masukaz[j] = NULL;
	return (masukaz);
}
