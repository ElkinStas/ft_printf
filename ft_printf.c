#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


typedef struct      s_flist
{
	struct	s_flist	*next;
	int			    spec;   //  l  ll h hh
	char			sign;  // + -
    int             signf;
	int				point;  //  .
	int				resh;  // #
	int				L;     //  L  если есть то 1 нет значит 0
    int             count;//счетчик

}					t_flist;

void    ft_minus2(char **p, t_flist **base)
{   
    if ((*base)->signf > (*base)->count)
       {
            (*base)->signf= (*base)->signf - (*base)->count;
            while ((*base)->signf >= 0)
            {
            ft_putchar(' ');
            (*base)->signf --;
            (*base)->count++;
            }
       }
}

void    ft_minus1(char **p, t_flist *base)
{
    int i;
    int q;
    q = 0;
    (*p)++;
    while ((*p)[q] >='0' && (*p)[q] <='9')
    {
        q++;
        //i =atoi(*p);
         //(*p)++;
    }
    i =atoi(*p);
    while(q > 0)
    {
      (*p)++;
      q--; 
    }
    //(*p)++;
    base->sign = '-';
    base->signf = i;
   /* while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }*/
}
void    ft_text(char **p, t_flist *base)
{
    int i;
    int q;
    i = 0;
    //if (**p != '\0' )
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
void    functiondigitalu(va_list ap, t_flist *base)
{
     void*     z;

     z = va_arg(ap, void*);
     ft_uputnbr(z, &base);
}

void	ft_loputnbr(void* z, t_flist **base)
{
	long long y;
    long long a;
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
	else
		a = y;
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), base); 
	ft_putchar((char)(a % 10 + '0'));
    ((*base)->count)++;
}

void    fucnctcheck(char **p, t_flist *base)
{
    int i;
    i = 0;
    int h = 0;
    int l = 0;
    while((*p)[i])
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
                i++;
            }
    if (base->spec == 1 || base->spec == 2)
     (*p)++;
    if (base->spec == 3 || base->spec == 4)
        *p = *p + 2;
}

void    functionstring(va_list ap, t_flist *base)
{
    char    *sval;
     sval = va_arg(ap, char *);
    while(*sval)
    {
       
        ft_putchar(*sval);
        sval++;
        (base->count)++;
    }
    if (base->sign == '-')
        ft_minus2(&sval, &base);   

}
/*void    ft_conversionu(void* z, long long *y, t_flist **base)
{
  
     if (((*base)->spec == 1) && (*y = (unsigned short) z))
       *y = (unsigned short)y;
    else if (((*base)->spec == 2) && (*y = (unsigned long) z))
       *y = (unsigned long) y;
    else if ((*base)->spec == 4 && (*y = (unsigned long long) z))
        *y = (unsigned long long) y;
    else if ((*base)->spec == 0 && (*y = (unsigned int) z))
     *y = (unsigned int) y;
    else if ((*base)->spec == 3 && (*y = (char) z))
        *y = (unsigned char) y;
}*/
void	ft_puteight(void* z, t_flist **base)
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
	{
		ft_puteight((void*)(a / 8), base);
	}
	ft_putchar((char)(a % 8 + '0'));
    ((*base)->count)++;
}
void    functioneight(va_list ap, t_flist *base)
{
    void* z;
    z = va_arg(ap, void*);
    ft_puteight(z, &base);
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
void    ft_putsix(void* z, t_flist **base)
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
		ft_putsix((void*)(y / 16), base);
     y = y % 16;
    ft_convertation((long long)y);
     ((*base)->count)++;
}
void    functionsix(va_list ap, t_flist *base)
{
    void* z;
  
    z = va_arg(ap, void*);
    ft_putsix(z, &base);
}
void    ft_putsiX(void* z, t_flist **base)
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
		ft_putsiX((void*)(y / 16), base);
     y = y % 16;
    ft_convertation2((long long)y);
     ((*base)->count)++;
}
void    functionsiX(va_list ap, t_flist *base)
{
    void* z;
    z = va_arg(ap, void*);
    ft_putsiX(z, &base);
}
void    functionchar(va_list ap, t_flist *base)
{
    char    z;
    z = va_arg(ap, int);
    ft_putchar(z);
    (base->count)++;
}

void    functiondigital(va_list ap, t_flist *base)
{
     void*     z;
     z = va_arg(ap, void*);
     ft_loputnbr(z, &base);
      if (base->sign == '-')
        ft_minus2(z, &base);   

}

void    functionpointer(va_list ap, t_flist *base)
{
    void*     z;
    long       y;
    base->count = 2;
    z = va_arg(ap, void*);
    y = (long)z;
    ft_putstr("0x");
    ft_putsix(z, &base);

}


int ft_printf(char *fmt, ...)
{
    va_list ap;//имя аргумента
    char *p;
    int ret;
    t_flist base;
    base.count = 0; 
    base.spec = 0;   
    va_start (ap, fmt);//ап укажет на первый безымянный аргумент
    
    p = fmt;
    while (*p)
    {
        if(*p != '%')
        {
            ft_text(&p, &base);
            //continue;
           // p++;
        }
              p++;

        fucnctcheck(&p, &base);
            if(*p == '-')
            {
               ft_minus1(&p, &base); 
            }

            if(*p == 's')
            {
               
               functionstring(ap, &base);
            }
            
            if (*p == 'd' || *p == 'i')
            {
                functiondigital(ap, &base);
            }
            if (*p == 'c')
            {
                functionchar(ap, &base);
            }
            if (*p == 'o')
            {
                functioneight(ap, &base);
            }
          if (*p == 'x')
            {
                functionsix(ap, &base);
            }
            if (*p == 'X')
            {
                functionsiX(ap, &base);
            }
            if (*p == 'p')
            {
                functionpointer(ap, &base);
            }
            if (*p == 'u')
            {
                functiondigitalu(ap, &base);
            }
            if (*p == '%')
             ft_putchar('%');
        if (*p != '\0')
        p++;
    }
    va_end(ap);
    
    return(base.count);
}