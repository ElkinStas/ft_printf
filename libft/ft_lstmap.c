/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:48:38 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/09 20:52:22 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *d, size_t n)
{
	n = 0;
	ft_memdel(&d);
}

t_lst		*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst	*tmp;
	t_lst	*newl;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	newl = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp->next)
		{
			ft_lstdel(&newl, &del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (newl);
}
