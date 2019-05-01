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
		{
			ft_putstr("0x");
			(*base)->longitude = (*base)->longitude + 2;
		}
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}

}

void	ft_loputnbrindentprintp(t_flist *base, int check, int checkmin)
{
	int	i;


	i = base->indent;

	if (check < i)
	{
		i = i - check;
		if (checkmin < 0 && base->zero == '0')
		{
			ft_putchar('-');
			base->count++;
		}
		while (i > 0 && base->sign != '-')
		{
			if (base->zero == '0')
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			base->count++;
		}
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
	if ((*base)->sign2 == '+' && checkmin > 0 && (*base)->resh != 1)
		(*base)->longitude++;
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
	while ((*base)->indent > 0 && (*base)->sign != '-' && checkmin >= 0)
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
			(*base)->longitude++;
		}
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->longitude++;
		(*base)->point--;
	}

}


void	ft_checkminP(long long z, long long *checkmin)
{
	*checkmin = (unsigned long long)z;
	*checkmin = (unsigned long long)*checkmin;
}
void	ft_checklongitudeP(t_flist **base, long long checkmin)
{
		checkmin = (unsigned long long)checkmin;
	while ((checkmin) != 0)
	{
		(checkmin) = (checkmin) / 16;
		(*base)->longitude++;
	}
	if ((*base)->sign2 == '+' && (*base)->sign == '-' && checkmin >= 0 && (*base)->space == '1')
	{
		if (((*base)->point > 0) && ((*base)->indent > 0))
			;
		else
		{
			ft_putchar(' ');
			(*base)->count++;
		}
	}
	(*base)->point = (*base)->point - (*base)->longitude;
}

void	ft_zerodigital5(t_flist **base, long long checkmin)
{
	if (checkmin < 0)
		(*base)->longitude++;
	(*base)->indent = (*base)->indent - ((*base)->longitude);
	if ((*base)->resh == 1)
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
	if ((*base)->resh == 1)
		{
			ft_putstr("0x");
			(*base)->resh = 0;
			(*base)->count = (*base)->count + 2;
		}
	    while ((*base)->point > 0 && checkmin >= 0 )
	{
		ft_putchar('0');
		(*base)->count++;
		(*base)->point--;
	}
}
void	ft_minus_p(t_flist **base)
{
	if ((*base)->signf > (*base)->longitude)
	{
		(*base)->signf = (*base)->signf - (*base)->longitude-2;
		while ((*base)->signf > 0)
		{
			ft_putchar(' ');
			(*base)->signf--;
			(*base)->count++;
		}
	}
}

void	ft_loputnbr_p(long long z, t_flist *base, int *check)
{
	unsigned long long	y;

	y = (unsigned long long)z;
	y = (unsigned long long)y;
	if (y >= 16)
		ft_loputnbr_p((long long)(y / 16), base, check);
	(*check)++;
}
void	ft_countresh_p(unsigned long long z, t_flist *base, int check, long long checkmin)
{
	base->count = base->count + 2;
	check = 2;
	if (base->zero == '0' && base->resh != 1)
		ft_putstr("0x");
	if (base->zero == '0' && base->resh == 1 && base->point < 0)
		ft_putstr("0x");
	if (base->indent > 0)
	{
		ft_loputnbr_p(z, base, &check);
		ft_loputnbrindentprintp(base, check, checkmin);
	}
	if (base->zero != '0' && checkmin != 0)
		ft_putstr("0x");
	base->resh = 0;
}
void	ft_convertationP(unsigned long long y)
{
	if (y == 10)
		ft_putchar('a');
	else	if (y == 11)
		ft_putchar('b');
	else	if (y == 12)
		ft_putchar('c');
	else	if (y == 13)
		ft_putchar('d');
	else	if (y == 14)
		ft_putchar('e');
	else	if (y == 15)
		ft_putchar('f');
	else
		ft_putchar((char)(y % 16 + '0'));
}
void	ft_check_indent5(t_flist **base, unsigned long long y)
{
	if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
	{
		if ((y == 0 && (*base)->point2 == '.' && (*base)->point != 0))
			{
				ft_putchar('0');
				((*base)->count)++;
			}
	}
	else	if ((y != 0) || (*base)->point2 != '.'
			|| (y == 0 && (*base)->point2 == '.'))
	{
		ft_convertationP((unsigned long long)y);
		((*base)->count)++;
	}
}

void	ft_put_pointer(unsigned long long z, t_flist **base)
{
	unsigned long long	y;

	y = (unsigned long long)z;
	if (y >= 16)
		ft_put_pointer((y / 16), base);
	y = y % 16;
	ft_check_indent5(base, y);
}

void	ft_pointer(va_list ap, t_flist *base)
{
	void	*z;

	int			check;
	long long	checkmin;
	int			flag;
	check = 0;
	flag = 0;
	z = va_arg(ap, void*);
	ft_checkminP((long long)z, &checkmin);
	ft_checklongitudeP(&base, checkmin);
	base->resh = 1;
	if (z == 0 && base->indent > 0)
		base->indent = base->indent - 1;
	if (base->point > 0)
		base->indent = base->indent - base->point;
	if (base->point > 0)
		ft_zerodigital5(&base, checkmin);
	if (base->resh == 1 && checkmin != 0)
		ft_countresh_p((unsigned long long)z, base, check, checkmin);
	else	if (base->indent > 0)
	{
		ft_loputnbr_p((long long)z, base, &check);
		ft_loputnbrindentprintp(base, check, checkmin);
	}
	if ((base->resh == 1) && (base->count = base->count + 2))
		ft_putstr("0x");
	ft_put_pointer((unsigned long long)z, &base);
	ft_minus_p(&base);
}

void	ft_checkmino(long long z, t_flist **base, long long *checkmin)
{
	if (((*base)->spec == 1) && (*checkmin = (short)z))
		*checkmin = (short)*checkmin;
	else	if (((*base)->spec == 2) && (*checkmin = (long)z))
		*checkmin = (long)*checkmin;
	else	if ((*base)->spec == 4 && (*checkmin = (long long)z))
		*checkmin = (long long)*checkmin;
	else	if ((*base)->spec == 0 && (*checkmin = (int)z))
		*checkmin = (int)*checkmin;
	else	if ((*base)->spec == 3 && (*checkmin = (unsigned char)z))
		*checkmin = (unsigned char)*checkmin;
}

