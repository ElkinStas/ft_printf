#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

void    ft_uputnbr(void* z, int spec, int **count)
{
    unsigned long long y;
    unsigned long long a;
     if ((spec == 1) && (y = (unsigned short) z))
       y = (unsigned short)y;
    else if ((spec == 2) && (y = (unsigned long) z))
       y = (unsigned long) y;
    else if (spec == 4 && (y = (unsigned long long) z))
        y = (unsigned long long) y;
    else if (spec == 0 && (y = (unsigned int) z))
     y = (unsigned int) y;
    a = y;
	
	if (a >= 10)
		ft_uputnbr((void*)(a / 10), spec, count); 
	ft_putchar((char)(a % 10 + '0'));
    (**count)++;
}
void    functiondigitalu(va_list ap, int spec, int *count)
{
     void*     z;

     z = va_arg(ap, void*);
     ft_uputnbr(z, spec, &count);
}
void	ft_loputnbr(void* z, int spec, int **count)
{
	long long y;
    long long a;
     if ((spec == 1) && (y = (short) z))
          y = (short)y;
    else if ((spec == 2) && (y = (long) z))
       y = (long) y;
    else if (spec == 4 && (y = (long long) z))
        y = (long long) y;
    else if (spec == 0 && (y = (int) z))
           y = (int) y;
      a = y;
	if (y < 0)
	{
		a = -1 * y;
		ft_putchar('-');
	}
	else
		a = y;
	if (a >= 10)
		ft_loputnbr((void*)(a / 10), spec, count); 
	ft_putchar((char)(a % 10 + '0'));
    (**count)++;
}

void    fucnctcheck(char **p, int *spec)
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
                            *spec = 1;
                            h = 1;
                        }
                    else
                        *spec = 3;                  
                    
                }
                else if ((*p)[i] == 'l')
                {
                    if (l == 0)
                        {
                            *spec = 2;
                             l = 1;
                        }
                    else
                        *spec = 4;
                   
                }
                i++;
            }
    if (*spec == 1 || *spec == 2)
     (*p)++;
    if (*spec == 3 || *spec == 4)
        *p = *p + 2;
}

void    functionstring(va_list ap, int *count)
{
    char    *sval;
     sval = va_arg(ap, char *);
    while(*sval)
    {
       
        ft_putchar(*sval);
        sval++;
        (*count)++;
    }   

}
void	ft_puteight(int z, int **count)
{
	
	if (z >= 8)
	{
		ft_puteight(z / 8, count);
	}
	ft_putchar((char)(z % 8 + '0'));
    (**count)++;
}
void    functioneight(va_list ap, int *count)
{
    long z;
    z = va_arg(ap, int);
    ft_puteight(z, &count);
}
void    ft_putsix(long z, int **count)
{
    if (z >= 16)
		ft_putsix(z / 16, count);
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
       (**count)++;
}
void    functionsix(va_list ap, int *count)
{
    long z;
    z = va_arg(ap, int);
    ft_putsix(z, &count);
}
void    ft_putsiX(int z, int **count)
{
    if (z >= 16)
		ft_putsiX(z / 16, count);
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
       (**count)++;
}
void    functionsiX(va_list ap, int *count)
{
    long z;
    z = va_arg(ap, int);
    ft_putsiX(z, &count);
}
void    functionchar(va_list ap, int *count)
{
    char    z;
    z = va_arg(ap, int);
    ft_putchar(z);
    (*count)++;
}

void    functiondigital(va_list ap, int spec, int *count)
{
     void*     z;

     z = va_arg(ap, void*);
   /* if (spec == 1)
        y = (short) z;
    else if (spec == 2)
       y = (long) z;
    else if (spec == 4)
        y = (long long) z;
    else 
       y = (int) z;
     */
     ft_loputnbr(z, spec, &count);
}

void    functionpointer(va_list ap, int *count)
{
    void*     z;
    long       y;
    *count = 2;
    z = va_arg(ap, void*);
    y = (long)z;
    //ft_putsix (z);
    //printf("%lx", y);
    ft_putstr("0x");
    ft_putsix(y, &count);

}


int ft_printf(char *fmt, ...)
{
    va_list ap;//имя аргумента
    char *p;
    int ival;
    double dval;
    int spec;
    spec = 0;
    int count;
    count = 0;
    //int i = 0;
   // int h = 0;
   // int l = 0;

    va_start (ap, fmt);//ап укажет на первый безымянный аргумент
    
    p = fmt;
    while (*p)
    {
        if(*p != '%')
        {
            ft_putchar(*p);
            continue;
        }
        p++;

        fucnctcheck(&p, &spec);
        
            if(*p == 's')
            {
               
               functionstring(ap, &count);
            }
            
            if (*p == 'd' || *p == 'i')
            {
                functiondigital(ap, spec, &count);
            }
            if (*p == 'c')
            {
                functionchar(ap, &count);
            }
            if (*p == 'o')
            {
                functioneight(ap, &count);
            }
            if (*p == 'x')
            {
                functionsix(ap, &count);
            }
            if (*p == 'X')
            {
                functionsiX(ap, &count);
            }
            if (*p == 'p')
            {
                functionpointer(ap, &count);
            }
            if (*p == 'u')
            {
                functiondigitalu(ap, spec, &count);
            }
            if (*p == '%')
             ft_putchar('%');
        p++;
    }
    va_end(ap);
    return(count);
}

int main ()
{
    //char *x = "Where is Kirill";
   //ft_printf("%d", ft_printf("%s", x));
    //printf("\n");
    //char z;
    //z = 'a';
    //printf("%d", (printf("%p", x)));
     //printf("\n");
     //ft_printf("%d", (ft_printf("%p", x)));
    //ft_printf("%d", (ft_printf("%c", 'z')));
    ////printf("%c", 'z');
   //unsigned long long q = 123, r = 6;
   //short l;
  
   //ft_printf("%d", ft_printf("%s", x));
   //ft_printf("%d", ft_printf("%llu", q));
    // printf("%hhi", q);
    // printf("%lu", sizeof(long));
    //ft_printf("%li", q);
   //int x = 7562673;
   //ft_printf("%x", x);
  //char *z;
  //ft_printf("%p",z);
  //printf("\n");
  //printf("%p",z);
    ft_printf("%%");
    return (0);
}