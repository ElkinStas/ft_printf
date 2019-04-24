#include "printf.h"

void	ft_zerodigital2(t_flist **base, int checkmin)
{
	if ((*base)->sign2 == '+' && checkmin > 0)
		(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	    while ((*base)->point > 0 && checkmin > 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}
