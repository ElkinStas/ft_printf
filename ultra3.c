#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


typedef struct      s_flist
{
	struct	s_flist	*next;
	int			    spec;   //  l  ll h hh
	char			sign;  // -
    char            sign2; //+
    int             signf;
	int				point;
    char            point2;  //  .
	int				resh;  // #
	int				L;     //  L  если есть то 1 нет значит 0
    int             count;//счетчик
    int             work;
    int             indent;//отступы
    char            zero;//заполнять ли 0
    char            space;
    int             longitude;
    char            minus;
    char            indent2;
    int match;

}					t_flist;


void    ft_checkmin(long long z, t_flist **base, long long *checkmin);
void    ft_zerodigital(t_flist **base, int checkmin);

void	ft_putnbr2(long long n)
{
	unsigned long long a;

	if (n < 0)
		a = -1 * n;
	else
		a = n;
	if (a >= 10)
		ft_putnbr2(a / 10);
	ft_putchar((char)(a % 10 + '0'));
}

int ft_check_last_symb(long double fl, int len)
{
	long long per;
	long long sum;
	int ar;
	int b = 0;
	while(len)
	{
		fl = fl * 10;
		sum = (long long)fl;
		if ( len == 1)
			{
				fl = fl * 10;
				per = (long long)fl;
				if (per % 10 > 4)
					b = 1;
			}
		ar = sum % 10 + b;
		if ( ar == 10)
			return(1);
		len--;
	}
	return (0);
}


void floatconvert(long double z, t_flist **base, double *q)
{
    
    if (((*base)->spec == 2) && (*q = (double) z))
            (*q) = (double)(*q);
    else if (((*base)->spec  == 5) && (*q = (long double) z))
            (*q) = ( long double)(*q);
    else if ((*base)->spec  == 0 && (*q  = (float) z))
            (*q) = (float)(*q);
} 
int	ft_print_with_rounding(long double fl, int len, int count)
{
	long long per;
	long long sum;
	int ar;
	int c ;

	c = 0;
	int b = 0;
	per = (long long)fl;
	if (count >= 0)
		{
			if (count == 0)
			{
				ft_putnbr2(per+1);
				if (per%10 ==9)
					c = 1;
				ft_putchar('.');
				count++;
			}
			else
			{
				ft_putnbr2(per);
				ft_putchar('.');
			}
		while(len && (count > 0))
		{
		fl = fl * 10;
		sum = (long long)fl;
		if ( count == 1 && len != 1)
			{
					b = 1;
			}
		ar = sum % 10 + b;
		if (ar == 10)
			ft_putchar('0');
		else
			ft_putchar(ar + '0');
		len--;
		count--;
		}
		while (len)
		{
			ft_putchar('0');
			len--;
		}
		}
	else
		{
			ft_putnbr2(per);
			ft_putchar('.');
			while(len)
				{
					fl = fl * 10;
					sum = (long long)fl;
					if (len == 1)
					{
						fl = fl * 10;
						per = (long long)fl;
						if (per % 10 > 4)
							b = 1;
					}
				ar = sum % 10 + b;
				ft_putchar(ar + '0');
				len--;
				count--;
			}
	}
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
	if (flags->point2 != '0')
		sum =6;
	else 
		 sum = flags->indent;
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

void    functionfloat(va_list ap, t_flist *base)
{
    long long   checkmin;
	int i;
	long double f;
	long long fl;
	int cop;
	int count;
     double q;
    count =0;
    i = 0;
    if (base->spec == 0)
	    f = va_arg(ap, double);
    else if (base->spec == 2)
        f = va_arg(ap, double);
    else if (base->spec == 5)
        f = va_arg(ap, long double);
    floatconvert(f, &base, &q);
	i = ft_single_part(q); /* количество символов целой части*/
	cop = (int)q;
    ft_checkmin(cop, &base, &checkmin);
	count = ft_count_sympoint(q, base); /* количество символов после точки */
	fl = (long long)q;
	i = i + ft_print_accuracy(q, count);
	if ( i == 0)
		i = 1;
	base->count = base->count + i + count + 1;
}

void    ft_checklongitudex(long long z, t_flist **base, long long checkmin)
{
    if (((*base)->spec == 1) && (checkmin = (short) z))
          checkmin  = (short)checkmin ;
    else if (((*base)->spec  == 2) && (checkmin = (long) z))
       checkmin  = (long) checkmin ;
    else if ((*base)->spec == 4 && (checkmin  = (long long) z))
        checkmin  = (long long) checkmin ;
    else if ((*base)->spec  == 0 && (checkmin  = (int) z))
           checkmin  = (int) checkmin ;
     else if ((*base)->spec == 3 && (checkmin  = (char) z))
        checkmin  = (char) checkmin ;
    while((checkmin) != 0) 
    {
        (checkmin) = (checkmin)/16;
        (*base)->longitude++;
    }
     (*base)->point =(*base)->point - (*base)->longitude;
}

void    ft_checklongitudeo(long long z, t_flist **base, long long checkmin)
{
    if (((*base)->spec == 1) && (checkmin = (short) z))
          checkmin  = (short)checkmin ;
    else if (((*base)->spec  == 2) && (checkmin = (long) z))
       checkmin  = (long) checkmin ;
    else if ((*base)->spec == 4 && (checkmin  = (long long) z))
        checkmin  = (long long) checkmin ;
    else if ((*base)->spec  == 0 && (checkmin  = (int) z))
           checkmin  = (int) checkmin ;
     else if ((*base)->spec == 3 && (checkmin  = (char) z))
        checkmin  = (char) checkmin ;
    while((checkmin) != 0) 
    {
        (checkmin) = (checkmin)/8;
        (*base)->longitude++;
    }
     (*base)->point =(*base)->point - (*base)->longitude;
}
void    ft_indentd2(t_flist **base, int check)
{
    int i;
    i = (*base)->indent;
   
    if ((*base)->indent > check)
     {
        if((*base)->point2 != '.')
        i = i - check;
         while(i > 0)
         {
             ft_putchar(' ');
             i--;
             (*base)->count++;
         } 
     }
}

void    ft_loputnbrindentu(void*  z,t_flist *base, int *check)
{
   unsigned long long y;
    
     if (((base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
	if (y >= 10)
	    ft_loputnbrindentu((void*)(y / 10), base, check); 
	    (*check)++;
}   

void    ft_loputnbrindentprint(t_flist *base, int check, int checkmin)
{
    int i;
    i = base->indent;
    if (check < i)
    {
        i = i - check;
        if(checkmin < 0 && base->zero == '0')
            {
                ft_putchar('-');
                base->count++;
            }
        while(i > 0 && base->sign != '-')
        {
            if(base->zero == '0')
                ft_putchar('0');
            else
                ft_putchar(' ');
            i --;
            base->count++;
        }
    }
}

void    ft_plus1(char **p, t_flist *base)
{
   int      i;
       
    i = 0;
    (*p)++;
    while (**p == ' ')
       {
           i++;
           (*p)++;
       }
   base->sign2 = '+';
   while (i > 0)
   {
       (*p)--;
       i--;
   }
}

void    ft_minus2(t_flist **base)
{
    if ((*base)->signf > (*base)->count)
       {
            (*base)->signf= (*base)->signf - (*base)->count;
            while ((*base)->signf > 0)
            {
            ft_putchar(' ');
            (*base)->signf --;
            (*base)->count++;
            }
       }
}
void    ft_cage(t_flist *base)
{
    (base)->resh = 1;
}
void    ft_minus1(char **p, t_flist *base)
{
    int i;
    int q;
    q = 0;
    (*p)++;
    if ( (**p) == '0')
        (*p)++;
    if ((*p)[q] == '#')
     {
        ft_cage(base);
        (*p)++;
     }
    while ((*p)[q] >='0' && (*p)[q] <='9')
    {
        q++;
    }
    i =atoi(*p);
    while(q > 0)
    {
      (*p)++;
      q--; 
    }
    base->sign = '-';
    base->signf = i;
}
void    ft_text(char **p, t_flist *base)
{
    int i;
    int q;
    
    i = 0;
    q = ft_strlen(*p);
    while (i < q && **p != '%' && **p != '\0')
    {   
        ft_putchar(**p);
        (base->count)++;
        i++;
        (*p)++;
    }
}
void    ft_uputnbr(void* z, t_flist **base)
{
    unsigned long long y;
    unsigned long long a;
     if (((*base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((*base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((*base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((*base)->spec == 3 && (y = (char) z))
        y = (char) y;
    a = y;
		if (a >= 10)
		    ft_uputnbr((void*)(a / 10), base); 
	ft_putchar((char)(a % 10 + '0'));
    ((*base)->count)++;
}
 void    ft_checklongitudeu(void*  z, t_flist **base, unsigned long long *checkmin)
{
    if (((*base)->spec == 1) && (*checkmin = (unsigned short) z))
          *checkmin  = (unsigned short)*checkmin ;
    else if (((*base)->spec  == 2) && (*checkmin = (unsigned long) z))
       *checkmin  = (unsigned long) *checkmin ;
    else if ((*base)->spec == 4 && (*checkmin  = (unsigned long long) z))
        *checkmin  = (unsigned long long) *checkmin ;
    else if ((*base)->spec  == 0 && (*checkmin  = (unsigned int) z))
           *checkmin  = (unsigned int) *checkmin ;
     else if ((*base)->spec == 3 && (*checkmin  = (unsigned char) z))
        *checkmin  = (unsigned char) *checkmin ;
    while((*checkmin) != 0) 
    {
        (*checkmin) = (*checkmin)/10;
        (*base)->longitude++;
    }
     (*base)->point =(*base)->point - (*base)->longitude;
}
void    ft_checkminu(void* z, t_flist **base, unsigned long long *checkmin)
{
    if (((*base)->spec == 1) && (*checkmin = (unsigned short) z))
          *checkmin  = (unsigned short)*checkmin ;
    else if (((*base)->spec  == 2) && (*checkmin = (unsigned long) z))
       *checkmin  = (unsigned long) *checkmin ;
    else if ((*base)->spec == 4 && (*checkmin  = (unsigned long long) z))
        *checkmin  = (unsigned long long) *checkmin ;
    else if ((*base)->spec  == 0 && (*checkmin  = (unsigned int) z))
           *checkmin  = (unsigned int) *checkmin ;
     else if ((*base)->spec == 3 && (*checkmin  = (unsigned char) z))
        *checkmin  = (unsigned char) *checkmin ;
    
}
void    ft_loputnbrindentprintu(t_flist *base, int check)
{
    int i;
    i = base->indent;
    if (check < i)
    {
        i = i - check;
        
        while(i > 0 && base->sign != '-')
        {
            if(base->zero == '0')
                ft_putchar('0');
            else
                ft_putchar(' ');
            i --;
            base->count++;
        }
    }
}
void    functiondigitalu(va_list ap, t_flist *base)
{
    void    *z;
    int     check;
    unsigned long long   checkmin;
    
    checkmin = 0;
    check = 0;
    z = va_arg(ap, void*);

    ft_checklongitudeu(z, &base, &checkmin);
    ft_checkminu(z, &base, &checkmin);

    if(base->point >0)
        base->indent = base->indent - base->point;

    if (base->sign2 == '+')
        {
            if(base->zero == '0')
                {
                    ft_putchar('+');
                    (base)->count++;
                }
                check++;
         }
    if (base->point > 0)
        ft_zerodigital(&base, checkmin);
    if (base->indent > 0)
        {
            ft_loputnbrindentu(z, base, &check);
            ft_loputnbrindentprintu(base, check);
        }
    ft_uputnbr(z, &base);
    if (base->sign == '-')
        ft_minus2(&base);  
}


void	ft_loputnbr(void* z, t_flist **base)
{
	long long y;
    unsigned long long a;
     if (((*base)->spec == 1) && (y = (short) z))
          y = (short)y;
    else if (((*base)->spec  == 2) && (y = (long) z))
       y = (long) y;
    else if ((*base)->spec == 4 && (y = (long long) z))
        y = (long long) y;
    else if ((*base)->spec  == 0 && (y = (int) z))
           y = (int) y;
     else if ((*base)->spec == 3 && (y = (char) z))
        y = (char) y;
      a = y;
	if (y < 0)
	{
		a = -1 * y;
		ft_putchar('-');
        ((*base)->count)++;
	}
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), base); 
	ft_putchar((char)(a % 10 + '0'));
    ((*base)->count)++;
}

void    fucnctcheck(char **p, t_flist *base)
{
    int i;
    int h;
    int l;

    i = 0;
    h = 0;
    l = 0;
    while((*p)[i] && (*p)[i] != '#' && (*p)[i] != '%')
    {
        if ((*p)[i] == 'h')
        {
            if (h == 0)
            {
                base->spec = 1;
                h = 1;
            }
            else
                 base->spec = 3;
        }
        else if ((*p)[i] == 'l')
        {
            if (l == 0)
            {
                base->spec = 2;
                l = 1;
            }
            else
                base->spec = 4;
        }
        else if ((*p)[i] == 'L')
            base->spec = 5;
        i++;
    }
    if ((base->spec == 1 || base->spec == 5|| base->spec == 2) && (base->match = 1))
     (*p)++;
     
     
    if ((base->spec == 3 || base->spec == 4) && (base->match = 1))
        (*p) = (*p) + 2;
}
void    ft_checkstr(char *sval, int *check)
{
    *check = 0;
    while (*sval)
    {
        (*check)++;
        sval++;
    }
}
void    functionstring(va_list ap, t_flist *base)
{
    char    *sval;
    int     check;
    check = 0;

     sval = va_arg(ap, char *);
     if (sval == NULL)
       { 
           ft_putstr("(null)");
            (base->count)= (base->count) + 6;
       }
     else 
     {   
         ft_checkstr(sval, &check);
          if(base->point >0 && check != 0)
       {
           base->indent = base->indent - base->point;
            if (check != 0)
            check = base->point;
       }
        if (base->indent > 0)
        ft_indentd2(&base, check);
    while(check > 0)
    { 
        ft_putchar(*sval);
        sval++;
        check--;
        (base->count)++;
    }
    if (base->sign == '-')
        ft_minus2(&base);   
     }
}

void	ft_puteight(long long z, t_flist **base)
{
	unsigned long long y;
    unsigned long long a;
     if (((*base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((*base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((*base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((*base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    
		a = y;
		if (a >= 8)
		        ft_puteight((a / 8), base);
        if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
        {
            if((*base)->indent2 != '0')
            {
                ft_putchar(' '); 
                ((*base)->count)++;
            }
            else if ((*base)->resh == 1)
            {
                ft_putchar('0'); 
                ((*base)->count)++;
            }
        }
    else if((y != 0) || (*base)->point2 != '.')
   {
    ft_putchar((char)(a % 8 + '0'));
       ((*base)->count)++;
   }
}

void    ft_loputnbrindentuo(long long  z,t_flist *base, int *check)
{
   unsigned long long y;
    
     if (((base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    if (y >= 16)
	    ft_loputnbrindentuo((long long)(y / 8), base, check); 
     (*check)++;
}   
void    functioneight(va_list ap, t_flist *base)
{
    long long z;
    int    check;
    check = 0;
    long long checkmin;
    z = va_arg(ap, long long int);
    ft_checkmin(z, &base, &checkmin);
    ft_checklongitudeo(z, &base, checkmin);
    
    if(base->point >0)
       base->indent = base->indent - base->point;
        
    if (base->point > 0)
        ft_zerodigital(&base, checkmin);
    if(base->resh == 1  && checkmin != 0)
    {
        base->count++;
        check = 1;
         if(base->zero == '0')
            ft_putstr("0");
        if (base->indent > 0)
        {
            ft_loputnbrindentuo(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->zero != '0' && checkmin != 0)
        ft_putstr("0");
        base->resh = 0;
    }
    else if (base->indent > 0)
        {
            ft_loputnbrindentuo(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->resh == 1 && checkmin != 0)
    {
        ft_putstr("0");
        base->count ++;
    }

    ft_puteight(z, &base);
    ft_minus2(&base);
}

void    ft_convertation2(long long y)
{
 
    if (y == 10 )
         ft_putchar ('A');
    else if  (y == 11 )
         ft_putchar ('B');
    else if (y == 12 )
         ft_putchar ('C');
    else if (y == 13)
         ft_putchar ('D');
    else if (y == 14 )
         ft_putchar ('E');
    else if (y == 15 ) 
         ft_putchar ('F');
    else 
	   ft_putchar((char)(y % 16 + '0'));
}

void    ft_convertation(long long y)
{
   if (y == 10)
         ft_putchar ('a');
    else if  (y == 11)
         ft_putchar ('b');
    else if (y == 12)
         ft_putchar ('c');
    else if (y == 13)
         ft_putchar ('d');
    else if (y == 14)
         ft_putchar ('e');
    else if (y == 15)
         ft_putchar ('f');
    else 
	   ft_putchar((char)(y % 16 + '0')); 
}

void    ft_putsix(long long z, t_flist **base)
{   
    unsigned long long y;
    
     if (((*base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((*base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((*base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((*base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    if (y >= 16)
		ft_putsix((long long)(y / 16), base);
     y = y % 16;
     if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
        {
            if((*base)->indent2 != '0')
            {
                ft_putchar(' '); 
                ((*base)->count)++;
            }
        }
    else if((y != 0) || (*base)->point2 != '.')
   {
    ft_convertation((long long)y);
     ((*base)->count)++;
   }
}

void    ft_loputnbrindentux(long long  z,t_flist *base, int *check)
{
   unsigned long long y;
    
     if (((base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    if (y >= 16)
	    ft_loputnbrindentux((long long)(y / 16), base, check); 
     (*check)++;
}   

void    functionsix(va_list ap, t_flist *base)
{
    long long z;
    int    check;
    check = 0;
    long long checkmin;
    z = va_arg(ap, long);
    ft_checkmin(z, &base, &checkmin);
    ft_checklongitudex(z, &base, checkmin);
    
    if(base->point >0)
       base->indent = base->indent - base->point;
        
    if (base->point > 0)
        {
            ft_zerodigital(&base, checkmin);
        } 
    if(base->resh == 1  && checkmin != 0)
    {
        base->count = base->count + 2;
        check = 2;
         if(base->zero == '0')
            ft_putstr("0x");
        if (base->indent > 0)
        {
            ft_loputnbrindentux(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->zero != '0' && checkmin != 0)
        ft_putstr("0x");
        base->resh = 0;
    }
    else if (base->indent > 0)
        {
            ft_loputnbrindentux(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->resh == 1 && checkmin != 0)
    {
        ft_putstr("0x");
        base->count = base->count + 2;
    }
    ft_putsix(z, &base);
    ft_minus2(&base);
}
void    ft_putsiX(long long z, t_flist **base)
{
    unsigned long long y;
    
     if (((*base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((*base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((*base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    else if ((*base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    if (y >= 16)
		ft_putsiX((long long)(y / 16), base);
     y = y % 16;
     if (y == 0 && (*base)->point2 == '.' && (*base)->zero != '0')
        {
            if((*base)->indent2 != '0')
            {
                ft_putchar(' '); 
                ((*base)->count)++;
            }
        }
    else if((y != 0) || (*base)->point2 != '.')
   {
    ft_convertation2((long long)y);
     ((*base)->count)++;
   }
}
void    functionsiX(va_list ap, t_flist *base)
{
   long long z;
    int    check;
    check = 0;
    long long checkmin;
    z = va_arg(ap, long);
    ft_checkmin(z, &base, &checkmin);
    ft_checklongitudex(z, &base, checkmin);
    
    if(base->point >0)
       base->indent = base->indent - base->point;
        
    if (base->point > 0)
            ft_zerodigital(&base, checkmin);
    if(base->resh == 1  && checkmin != 0)
    {
        base->count = base->count + 2;
        check = 2;
         if(base->zero == '0')
            ft_putstr("0X");
        if (base->indent > 0)
        {
            ft_loputnbrindentux(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->zero != '0' && checkmin != 0)
            ft_putstr("0X");
        base->resh = 0;
    }
    else if (base->indent > 0)
        {
            ft_loputnbrindentux(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
        if(base->resh == 1 && checkmin != 0)
    {
        ft_putstr("0X");
        base->count = base->count + 2;
    }
    ft_putsiX(z, &base);
    ft_minus2(&base);
}

void    ft_indentdchar(t_flist **base)
{
    int i;
    
    i = 1;
    if ((*base)->indent > i)
     {
         i = (*base)->indent - i;
         while(i > 0)
         {
              if((*base)->zero == '0')
                ft_putchar('0');
            else
                ft_putchar(' ');
             i--;
             (*base)->count++;
         } 
     }
}
void    functionchar(va_list ap, t_flist *base)
{
    char    z;
  
    z = va_arg(ap, int);
    if (base->indent > 0)
        ft_indentdchar(&base);
    ft_putchar(z);
    (base->count)++;
    ft_minus2(&base);
}

void    ft_loputnbrindent(long long  z,t_flist *base, int *check)
{
    long long y;
    long long a;
   
     if (((base)->spec == 1) && (y = (short) z))
          y = (short)y;
    else if (((base)->spec  == 2) && (y = (long) z))
       y = (long) y;
    else if ((base)->spec == 4 && (y = (long long) z))
        y = (long long) y;
    else if ((base)->spec  == 0 && (y = (int) z))
           y = (int) y;
     else if ((base)->spec == 3 && (y = (char) z))
        y = (char) y;
      a = y;
	if (y < 0)
	{
		a = -1 * y;
		(*check)++;
	}
	if (a >= 10)
	    ft_loputnbrindent((long long)(a / 10), base, check); 
	(*check)++;
}

void    ft_checkmin(long long z, t_flist **base, long long *checkmin)
{
    if (((*base)->spec == 1) && (*checkmin = (short) z))
          *checkmin  = (short)*checkmin ;
    else if (((*base)->spec  == 2) && (*checkmin = (long) z))
       *checkmin  = (long) *checkmin ;
    else if ((*base)->spec == 4 && (*checkmin  = (long long) z))
        *checkmin  = (long long) *checkmin ;
    else if ((*base)->spec  == 0 && (*checkmin  = (int) z))
           *checkmin  = (int) *checkmin ;
     else if ((*base)->spec == 3 && (*checkmin  = (char) z))
        *checkmin  = (char) *checkmin ;
    
}
void    ft_checklongitude(long long z, t_flist **base, long long *checkmin)
{
    if (((*base)->spec == 1) && (*checkmin = (short) z))
          *checkmin  = (short)*checkmin ;
    else if (((*base)->spec  == 2) && (*checkmin = (long) z))
       *checkmin  = (long) *checkmin ;
    else if ((*base)->spec == 4 && (*checkmin  = (long long) z))
        *checkmin  = (long long) *checkmin ;
    else if ((*base)->spec  == 0 && (*checkmin  = (int) z))
           *checkmin  = (int) *checkmin ;
     else if ((*base)->spec == 3 && (*checkmin  = (char) z))
        *checkmin  = (char) *checkmin ;
    while((*checkmin) != 0) 
    {
        (*checkmin) = (*checkmin)/10;
        (*base)->longitude++;
    }
     (*base)->point =(*base)->point - (*base)->longitude;
}

void    ft_check_indent(t_flist ***base, unsigned long long a)
{
    if (a == 0 && (**base)->point2 == '.' && (**base)->zero != '0')
        {
            if((**base)->indent2 != '0')
            {
                ft_putchar(' '); 
                ((**base)->count)++;
            }
        }
    else if((a != 0) || (**base)->point2 != '.')
   {
        ft_putchar((char)(a % 10 + '0'));
        ((**base)->count)++;
   }
}
void    ft_check_minus_base(t_flist ***base, long long checkmin)
{
    if((checkmin < 0 && (**base)->zero != '0') ||((**base)->zero == '0' && (**base)->indent == 0))
    {
        if((**base)->minus != '-')
            {
                ft_putchar('-');
                ((**base)->count)++;
            }
    }
}
void	ft_loputnbrmin(long long z, t_flist **base, long long checkmin)
{
	long long y;
     unsigned long long a;

    if (((*base)->spec == 1) && (y = (short) z))
          y = (short)y;
    else if (((*base)->spec  == 2) && (y = (long) z))
       y = (long) y;
    else if ((*base)->spec == 4 && (y = (long long) z))
        y = (long long) y;
    else if ((*base)->spec  == 0 && (y = (int) z))
           y = (int) y;
     else if ((*base)->spec == 3 && (y = (char) z))
        y = (char) y;
    a = y;
	if (y < 0)
	{
		a = -1 * y;
        ft_check_minus_base(&base, checkmin);
	}
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), base); 
    ft_check_indent(&base, a);
}

void    ft_zero_digit_part2(t_flist ***base, int checkmin)
{
    if ((**base)->sign2 == '+' && checkmin > 0)
    {
        ft_putchar('+');
        (**base)->count++;
    }
    if (checkmin < 0)
    {
        ft_putchar('-');
        (**base)->minus = '-';
        (**base)->count++;
    }
    while ((**base)->point > 0)
    {
        ft_putchar('0');
        (**base)->count++;
        (**base)->point--;
    }
}
void    ft_zerodigital(t_flist **base, int checkmin)
{
    if ((*base)->sign2 == '+' && checkmin > 0)
        (*base)->longitude++;
    if (checkmin < 0)
        (*base)->longitude++;
    (*base)->indent = (*base)->indent - ((*base)->longitude);
    while((*base)->indent > 0 && (*base)->sign != '-')
    {
        ft_putchar(' ');
        (*base)->count++;
        (*base)->indent--;
    }
    (*base)->zero = '0';
    ft_zero_digit_part2(&base, checkmin);
}

void    ft_check_sign(t_flist **base, long long checkmin, int *check)
{
     if((*base)->point >0)
       (*base)->indent = (*base)->indent - (*base)->point;
    if ((*base)->sign2 == '+' && checkmin >= 0)
     {
         if((*base)->zero == '0')
         {
             ft_putchar('+');
            (*base)->count++;
         }
         (*check)++;
     }
     if( (*base)->sign2 != '+' && checkmin >= 0 && (*base)->space == '1') 
    {
        if(((*base)->point > 0) && ((*base)->indent > 0))
            ;
         else
        {
            ft_putchar(' ');
            (*base)->count++;
        }
    } 
}
void    functiondigital(va_list ap, t_flist *base)
{
    long long   z;
    int         check;
    long long   checkmin;

     check = 0;
     checkmin = 0;
     z = va_arg(ap, long long);
     ft_checklongitude(z, &base, &checkmin);
     ft_checkmin(z, &base, &checkmin);
     ft_check_sign(&base, checkmin, &check);  
    if (base->point > 0)
            ft_zerodigital(&base, checkmin);
     if (base->indent > 0)
        {
            ft_loputnbrindent(z, base, &check);
            ft_loputnbrindentprint(base, check, checkmin);
        }
     if (base->sign2 == '+' && checkmin >= 0 && base->zero != '0')
     {
         ft_putchar('+');
         (base)->count++;
     }
     ft_loputnbrmin(z, &base, checkmin);
     if (base->sign == '-')
        ft_minus2(&base);
}

void    functionper(t_flist *base)
{
    if (base->indent > 0)
        ft_indentdchar(&base);
    ft_putchar('%');
    base->count++;
    ft_minus2(&base);  
}

void    ft_convertationpointer(unsigned long long y)
{
   if (y == 10)
         ft_putchar ('a');
    else if  (y == 11)
         ft_putchar ('b');
    else if (y == 12)
         ft_putchar ('c');
    else if (y == 13)
         ft_putchar ('d');
    else if (y == 14)
         ft_putchar ('e');
    else if (y == 15)
         ft_putchar ('f');
    else 
	   ft_putchar((char)(y % 16 + '0')); 
}
void    ft_putpointer(void* z, t_flist **base)
{   
     unsigned long long y;
    
     if (((*base)->spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if (((*base)->spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if ((*base)->spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (y = (unsigned long long) z))
     y = (unsigned long long) y;
    else if ((*base)->spec == 3 && (y = (char) z))
        y = (unsigned char) y;
    if (y >= 16)
		ft_putpointer((void*)(y / 16), base);
     y = y % 16;
    ft_convertationpointer((unsigned long long)y);
     ((*base)->count)++;
}
void    functionpointer(va_list ap, t_flist *base)
{
      void*     z;

    base->count = base->count +2;
    z = va_arg(ap, void*);
    ft_putstr("0x");
    ft_putpointer(z, &base);

}

void    ft_point(char **p, t_flist *base)
{
    int q;
    
    q = 0;
    (*p)++;
    q++;
    base->point2 = '.';
    while ((*p)[q] >='0' && (*p)[q] <='9')
    {
        q++;
    }
    base->point =atoi(*p);
    q= q -1;
    while(q > 0)
    {
      (*p)++;
      q--; 
    }
    if(base->point == 0)
        (*p)--;
}

void    ft_space(t_flist *base)
{
    base->space = '1';
}
void    ft_indent(char **p, t_flist *base)
{
    int i;
    int q;
    q = 0;
    if ((*p)[q] == '0')
    {
        base->zero = '0';
        q++;
    }
    while ((*p)[q] >='0' && (*p)[q] <='9')
        q++;
    i = atoi(*p);
    q = q -1;
    while(q > 0)
    {
      (*p)++;
      q--; 
    }
    base->indent = i;
    base->indent2 = '1';
}

void    ft_create_base(t_flist*base)
{
    base->count = 0; 
    base->spec = 0;  
    base->signf = 0; 
    base->work = 0;
    base->indent = 0;
    base->sign2 = '0';
    base->space = '0';
    base->point = -1;
    base->sign = '0';
    base->longitude = 0;
     base->point2 = '0';
     base->zero = '1';
     base->minus = '0';
     base->indent2 = '0';
     base->resh = 0;

}
char     *ft_func_check_signs(char *p, t_flist *base)
{
    char *ptr;

    ptr = p;
    if(*ptr == '-' && (base->match = 1))
        ft_minus1(&ptr, base); 
    if(*ptr == '+' && (base->match = 1))
        ft_plus1(&ptr, base); 
    if(*ptr == '#' && (base->match = 1))           
        ft_cage(base);
    if(*ptr == ' ' && (base->match = 1))
        ft_space(base);
    if (*p >= '0' && *p <= '9' && base->point2 == '.')
        base->match = 1;
    if (*ptr >= '0' && *ptr <= '9' && base->point2 != '.' && (base->match = 1)) 
        ft_indent(&ptr, base);
    if(*ptr == '.' && (base->match = 1))
        ft_point(&ptr, base);
    return (ptr);
}

void    ft_func_check_symb1(va_list ap, char *p, t_flist *base)
{
    if (*p == 'c' && (base->match = 1) && (base->work = 1))
        functionchar(ap, base);
    if (*p == 'p'&& (base->match = 1) && (base->work = 1))
        functionpointer(ap, base);
    if (*p == 'f'&& (base->match = 1) && (base->work = 1))
        functionfloat(ap, base);
    if (*p == 'u'&& (base->match = 1) && (base->work = 1))
        functiondigitalu(ap, base);
    if (*p == '%' && (base->match = 1) && (base->work = 1))
        functionper(base);
    if (*p == 's' && (base->match = 1) && (base->work = 1))
        functionstring(ap, base);
    if ((*p == 'd' || *p == 'i') && (base->match = 1) && (base->work = 1))
        functiondigital(ap, base);
    if (*p == 'o' && (base->match = 1) && (base->work = 1))
        functioneight(ap, base);
    if (*p == 'x' && (base->match = 1) && (base->work = 1))
        functionsix(ap, base);
    if (*p == 'X' && (base->match = 1) && (base->work = 1))
        functionsiX(ap, base);
}

int	ft_search_flags(va_list ap, char *p, t_flist base)
{
    while (*p != '\0' )
    {
         base.work = 0;
        if(*p != '%')
            ft_text(&p, &base);
        if (*p != '\0')
            p++;
        while (*p != '\0' && base.work == 0 )
        {
            base.match = 0;
            fucnctcheck(&p, &base);
            p = ft_func_check_signs(p, &base);
            ft_func_check_symb1(ap, p, &base);
            if (*p != '\0' && base.match != 0)
                    p++;
                else
                {
                    break;
                }
        }
    }
    return(base.count);
}

int ft_printf(const char *restrict format, ...)
{
    va_list ap;//имя аргумента
    char *p;
    t_flist base;

    ft_create_base(&base);
    va_start (ap, format);//ап укажет на первый безымянный аргумент
    p = (char *)format;
    base.count = ft_search_flags(ap, p, base);
    
    va_end(ap);
    return(base.count);
}
int main ()
{
    //int l;
   float F = 2.56;
 // char *x = "this";
   //ft_printf("%d", ft_printf("%s", x));
    //printf("\n");
   // int z;
  //  int l;
   // char s = 'S';
    //z = 13478;
    //printf("%d", (printf("%p", x)));
     //printf("\n");
     //ft_printf("%d", (ft_printf("%p", x)));
    //ft_printf("%d", (ft_printf("%c", 'z')));
    //printf("%d", printf("%o", 'z'));
    //ft_printf("%d", ft_printf("%o", 'z'));
   //unsigned long long q = 123, r = 6;
   //short l;
  
   //ft_printf("%d", ft_printf("%s", x));
   //ft_printf("%d", ft_printf("%llu", q));
    // printf("%hhi", q);
    // printf("%lu", sizeof(long));
    //ft_printf("%li", q);
   //int x = 7562673;
 // ft_printf("%d", ft_printf("%X", x));
  //char *z;
  //ft_printf("%d",ft_printf("%p",z));
  //printf("\n");
  //printf("%d",printf("%p",z));
    //unsigned int q = 123456789;
    //short int  q =  −32769;
    //ft_printf("%d",(ft_printf("'%-10d0'", q)));
    //printf("%d", ft_printf("%-10x", q));
    //printf("%d", printf("%+10.5d", 4242));
  ft_printf("%.10p", &F);
    printf("\n");
   //ft_printf("%d", ft_printf( "gavgavgav\n%hhx\n", q));
   //ft_printf("%d", ft_printf( "gavgavgav\n%x\n", q));
   //ft_printf("%d", ft_printf( "%lu", q));
    printf("%.10p", &F);

    return (0);
} 