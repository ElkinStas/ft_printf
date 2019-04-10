
# include "printf.h"

void    ft_print_float2(int *count, long long per, int *len, long double fl)
{
    int ar;
    long long sum;
    int b;

    b = 0;
    ft_putnbr2(per);
	ft_putchar('.');
    while(*len)
    {
        fl = fl * 10;
		sum = (long long)fl;
		if ((*len) == 1)
        {
			fl = fl * 10;
			per = (long long)fl;
			if (per % 10 > 4)
                b = 1;
		}
		ar = sum % 10 + b;
		ft_putchar(ar + '0');
		(*len)--;
		(*count)--;
	}
}
int	ft_print_with_rounding(long double fl, int len, int count)
{
	long long per;
	//long long sum;
	//int ar;
	int c ;

	c = 0;
	//int b = 0;
	per = (long long)fl;
	if (count >= 0)
		{
			c = ft_print_float(&count, per, &len, fl);
		while (len)
		{
			ft_putchar('0');
			len--;
		}
		}
	else
        ft_print_float2(&count, per, &len, fl);
	return (c);
}
int	ft_print_accuracy(long double f, int len)
{
	long double fl;
	int b = len;
	int ar;
	fl = f;

	ar = -1;
	if(len > 0)
	{
		while (len && ft_check_last_symb(fl, len) == 1)
			{
				ar = len -1 ; // функция запоминает символ, где потом надо округлять
				len--;
			}
		len--;
	}
	return(ft_print_with_rounding(fl, b, ar));
}

int	ft_count_sympoint(long double f, t_flist *flags)
{
	f = 0;
	int sum =0;
	if (flags->point2 != '.')
		sum =6;
	else 
		 sum = flags->point;
		return (sum);
}

int	ft_single_part(double f)
{
	int i = 0;
	long long fl;
	fl = (long long)f;
	while(fl)
	{
		i++;
		fl =fl/10;
	}
	return (i);
}