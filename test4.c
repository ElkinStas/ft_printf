#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


typedef struct      s_flist
{
	struct	s_flist	*next;
	int			    spec;   //  l  ll h hh
	char			sign;  // + -
	int				point;  //  .
	int				resh;  // #
	int				L;     //  L  если есть то 1 нет значит 0
    int             count;//счетчик

}					t_flist;

void    ft_text(char **p, t_flist *base)
{
    int i;
    int q;
    i = 0;
    q = ft_strlen(*p);
    while (i < q && **p != '%')
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

}
void	ft_puteight(int z, t_flist **base)
{
	
	if (z >= 8)
	{
		ft_puteight(z / 8, base);
	}
	ft_putchar((char)(z % 8 + '0'));
    ((*base)->count)++;
}
void    functioneight(va_list ap, t_flist *base)
{
    long z;
    z = va_arg(ap, int);
    ft_puteight(z, &base);
}
void    ft_putsix(long z, t_flist **base)
{
    if (z >= 16)
		ft_putsix(z / 16, base);
     z = z % 16;
    if (z == 10)
         ft_putchar ('a');
    else if  (z == 11)
         ft_putchar ('b');
    else if (z == 12)
         ft_putchar ('c');
    else if (z == 13)
         ft_putchar ('d');
    else if (z == 14)
         ft_putchar ('e');
    else if (z == 15)
         ft_putchar ('f');
    else 
	   ft_putchar((char)(z % 16 + '0'));
       ((*base)->count)++;
}
void    functionsix(va_list ap, t_flist *base)
{
    long z;
    z = va_arg(ap, int);
    ft_putsix(z, &base);
}
void    ft_putsiX(int z, t_flist **base)
{
    if (z >= 16)
		ft_putsiX(z / 16, base);
     z = z % 16;
    if (z == 10 )
         ft_putchar ('A');
    else if  (z == 11 )
         ft_putchar ('B');
    else if (z == 12 )
         ft_putchar ('C');
    else if (z == 13)
         ft_putchar ('D');
    else if (z == 14 )
         ft_putchar ('E');
    else if (z == 15 ) 
         ft_putchar ('F');
    else 
	   ft_putchar((char)(z % 16 + '0'));
       ((*base)->count)++;
}
void    functionsiX(va_list ap, t_flist *base)
{
    long z;
    z = va_arg(ap, int);
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
}

void    functionpointer(va_list ap, t_flist *base)
{
    void*     z;
    long       y;
    base->count = 2;
    z = va_arg(ap, void*);
    y = (long)z;
    ft_putstr("0x");
    ft_putsix(y, &base);

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
        p++;
    }
    va_end(ap);
    
    return(base.count);
}

int main ()
{
   // char *x = "hi Roma";
   //ft_printf("%d", ft_printf("%s", x));
    //printf("\n");
   // int z;
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
    int q = 1234567;
    //ft_printf("%hhd", q);
   printf("%d", printf( "gavgavgav\n"));
   // printf("%hhd", q);

    return (0);
}