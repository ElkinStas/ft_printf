#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

//int     fucnctcheck()

void    functionstring(va_list ap)
{
    char    *sval;
     sval = va_arg(ap, char *);
    while(*sval)
    {
       
        ft_putchar(*sval);
        sval++;
    }   

}
void	ft_puteight(int z)
{
		
	if (z >= 8)
	{
		ft_puteight(z / 8);
	}
	ft_putchar((char)(z % 8 + '0'));
}
void    functioneight(va_list ap)
{
    int z;
    z = va_arg(ap, int);
    ft_puteight(z);
}
void    ft_putsix(int z)
{
    if (z >= 16)
		ft_putsix(z / 16);
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
}
void    functionsix(va_list ap)
{
    int z;
    z = va_arg(ap, int);
    ft_putsix(z);
}
void    ft_putsiX(int z)
{
    if (z >= 16)
		ft_putsiX(z / 16);
     z = z % 16;
    if (z == 10)
         ft_putchar ('A');
    else if  (z == 11)
         ft_putchar ('B');
    else if (z == 12)
         ft_putchar ('C');
    else if (z == 13)
         ft_putchar ('D');
    else if (z == 14)
         ft_putchar ('E');
    else if (z == 15)
         ft_putchar ('F');
    else 
	   ft_putchar((char)(z % 16 + '0'));
}
void    functionsiX(va_list ap)
{
    int z;
    z = va_arg(ap, int);
    ft_putsiX(z);
}
void    functionchar(va_list ap)
{
    char    z;
    z = va_arg(ap, int);
    ft_putchar(z);
}

void    functiondigital(va_list ap)
{
    int     z;
    z = va_arg(ap, int);
    ft_putnbr(z);
}
void ft_printf(char *fmt, ...)
{
    va_list ap;//имя аргумента
    char *p;
    char z;
    int ival;
    double dval;

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
    
            if(*p == 's')
            {
               
               functionstring(ap);
            }
            
            if (*p == 'd' || *p == 'i')
            {
                functiondigital(ap);
            }
            if (*p == 'c')
            {
                functionchar(ap);
            }
            if (*p == 'o')
            {
                functioneight(ap);
            }
            if (*p == 'x')
            {
                functionsix(ap);
            }
            if (*p == 'X')
            {
                functionsiX(ap);
            }
        p++;
    }
    va_end(ap);
}

int main ()
{
    //char *x = "Abs";
    //ft_printf("%s", x);
    //printf("\n");
   // char z;
   // z = 'a';
    //ft_printf("%c", 'z');
    ////printf("%c", 'z');
   // //int q = 5, r = 6;
    //ft_printf("%d", q);
   // ft_printf("%i", r);
   int x = 7562;
   ft_printf("%X", x);
    return (0);
}