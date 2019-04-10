
# include "printf.h"

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
    base->point = ft_atoi(*p);
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
    i = ft_atoi(*p);
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