#include "printf.h"

void	ft_checkminx(long long z, t_flist **base, long long *checkmin)
{
	if (((*base)->spec == 1) && (*checkmin = (unsigned short)z))
		*checkmin = (unsigned short)*checkmin;
	else	if (((*base)->spec == 2) && (*checkmin = (unsigned long)z))
		*checkmin = (unsigned long)*checkmin;
	else	if ((*base)->spec == 4 && (*checkmin = (unsigned long long)z))
		*checkmin = (unsigned long long)*checkmin;
	else	if ((*base)->spec == 0 && (*checkmin = (unsigned int)z))
		*checkmin = (unsigned int)*checkmin;
	else	if ((*base)->spec == 3 && (*checkmin = (unsigned char)z))
		*checkmin = (unsigned char)*checkmin;
}

void	ft_zerodigital2(t_flist **base, long long checkmin)
{
	//if ((*base)->sign2 == '+' && checkmin > 0 && (*base)->resh != 1)
		//(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1 && (*base)->longitude >= (*base)->point)
		(*base)->indent = (*base)->indent - 2;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point -1;
	if ((*base)->resh == 1 && checkmin != 0)
		ft_putstr("0x");
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}

}



void	ft_pointerindent(t_flist *base, int check, int *flag)
{
	int	i;

	i = base->indent;
	if (check < i)
	{
		i = i - check;

		*flag = 1;
		if (base->zero == '0')
		 ft_putstr("0x");
		while (i > 0 && base->sign != '-')
		{
			if (base->zero == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			base->count++;
		}
		if (base->zero != '0')
		ft_putstr("0x");
	}
}

void	ft_zerodigital3(t_flist **base, long long checkmin, int *flag)
{
	/*if ((*base)->sign2 == '+' && checkmin > 0)
		(*base)->longitude++;*/
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	//if((*base)->point > 0 && checkmin >= 0)
		//ft_putstr("0x");
	*flag = 1;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	if((*base)->indent > 0 && (*base)->sign != '-')
		ft_putstr("0x");
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point -1;
	    while ((*base)->point > 0 && checkmin >= 0)
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}

void	countreshbig(long long z, t_flist *base, int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0' && base->resh != 1)
		ft_putstr("0X");
	if (base->zero == '0' && base->resh == 1 && base->point < 0)
		ft_putstr("0X");
	if (base->indent > 0)
	{
		ft_loputnbrindentux(z, base, &check);
		ft_loputnbrindentprint(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0X");
	base->resh = 0;
}


void	ft_zerodigitalbig(t_flist **base, long long checkmin)
{
	//if ((*base)->sign2 == '+' && checkmin > 0 && (*base)->resh != 1)
		//(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1 && (*base)->longitude >= (*base)->point)
		(*base)->indent = (*base)->indent - 2;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point -1;
	if ((*base)->resh == 1 && checkmin != 0)
		ft_putstr("0X");
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}

}
void	ft_zerooct(t_flist **base, long long checkmin)
{
	//if ((*base)->sign2 == '+' && checkmin > 0 && (*base)->resh != 1)
		//(*base)->longitude++;
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1 && (*base)->longitude >= (*base)->point)
		(*base)->indent = (*base)->indent - 2;
	while ((*base)->indent > 0 && (*base)->sign != '-')
	{
		ft_putchar(' ');
		(*base)->count++;
		(*base)->indent--;
	}
	(*base)->zero = '0';
	if (checkmin == 0)
		(*base)->point = (*base)->point -1;
	if ((*base)->resh == 1 && checkmin != 0 && (*base)->indent >= 0)
		{
			ft_putstr("0");
			(*base)->count++;
		}
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}

}
