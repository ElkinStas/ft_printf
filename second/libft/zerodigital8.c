/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerodigital8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:21:05 by bhudson           #+#    #+#             */
/*   Updated: 2019/05/01 18:21:07 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	unsconvert(void *z, unsigned long long	*y, t_flist **base)
{
	if (((*base)->spec == 1) && (*y = (unsigned short)z))
		*y = (unsigned short)*y;
	else	if (((*base)->spec == 2) && (*y = (unsigned long)z))
		*y = (unsigned long)*y;
	else	if ((*base)->spec == 4 && (*y = (unsigned long long)z))
		*y = (unsigned long long)*y;
	else	if ((*base)->spec == 0 && (*y = (unsigned int)z))
		*y = (unsigned int)*y;
	else	if ((*base)->spec == 3 && (*y = (unsigned char)z))
		*y = (unsigned char)*y;
}
