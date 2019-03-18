#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
void ft_printf(char *fmt, ...)
{
    va_list ap;//имя аргумента
    char *p, *sval;
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
                sval = va_arg(ap, char *);
                while(*sval)
                    {
                        //sval = va_arg(ap, char *);
                        ft_putchar(*sval);
                        sval++;
                    }   
            }
        p++;
    }
    va_end(ap);
}

int main ()
{
    char *x = "A";
    ft_printf("%s", x);
    return (0);
}