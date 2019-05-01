/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:35:48 by bhudson           #+#    #+#             */
/*   Updated: 2019/02/07 15:38:08 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int v[], int i, int j)
{
	int	temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void		ft_qsort(int v[], int left, int right)
{
	int	i;
	int	last;

	if (left >= right)
		return ;
	swap(v, left, (left + right) / 2);
	last = left;
	i = left + 1;
	while (i <= right)
	{
		if (v[i] < v[left])
			swap(v, ++last, i);
		i++;
	}
	swap(v, left, last);
	ft_qsort(v, left, last - 1);
	ft_qsort(v, last + 1, right);
}
