/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:22:49 by bhudson           #+#    #+#             */
/*   Updated: 2019/04/09 20:52:14 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t))
{
	del(((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
