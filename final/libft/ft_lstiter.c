/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:47:59 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/09 20:52:20 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_lst *lst, void (*f)(t_lst *elem))
{
	t_lst *a;

	if (!lst || !f)
		return ;
	while (lst)
	{
		a = lst->next;
		f(lst);
		lst = a;
	}
}
