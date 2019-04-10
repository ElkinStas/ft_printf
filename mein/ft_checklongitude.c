
# include "printf.h"

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