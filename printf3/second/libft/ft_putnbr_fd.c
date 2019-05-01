/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:16:53 by bhudson           #+#    #+#             */
/*   Updated: 2018/12/21 13:47:25 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	if (n < 0)
	{
		a = -1 * n;
		ft_putchar_fd('-', fd);
	}
	else
	{
		a = n;
	}
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
	}
	ft_putchar_fd((char)(a % 10 + '0'), fd);
}
