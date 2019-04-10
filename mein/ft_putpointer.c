
# include "printf.h"

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