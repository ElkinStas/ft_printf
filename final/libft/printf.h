
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

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
    int             match;
}					t_flist;

void    ft_checkmin(long long z, t_flist **base, long long *checkmin);
void    ft_zerodigital(t_flist **base, int checkmin);
void   ft_check_indent3(t_flist **base, unsigned long long y);
void    ft_putpointer(void* z, t_flist **base);
void    ft_minus1(char **p, t_flist *base);
int     ft_printf(const char *restrict format, ...);
void    ft_create_base(t_flist*base);
void    fucnctcheck(char **p, t_flist *base);
void    ft_minus2(t_flist **base);
void    ft_plus1(char **p, t_flist *base);
void    ft_cage(t_flist *base);
void    ft_indent(char **p, t_flist *base);
void    ft_point(char **p, t_flist *base);
void    functionchar(va_list ap, t_flist *base);
void    ft_space(t_flist *base);
void    functionpointer(va_list ap, t_flist *base);
void    functionfloat(va_list ap, t_flist *base);
void    functiondigitalu(va_list ap, t_flist *base);
void    functionper(t_flist *base);
void    functionstring(va_list ap, t_flist *base);
void    functiondigital(va_list ap, t_flist *base);
void    functioneight(va_list ap, t_flist *base);
void    functionsix(va_list ap, t_flist *base);
void    functionsiX(va_list ap, t_flist *base);
void    ft_text(char **p, t_flist *base);
void    ft_checklongitudeu(void*  z, t_flist **base, unsigned long long *checkmin);
void    ft_zerodigital(t_flist **base, int checkmin);
void	ft_loputnbrmin(long long z, t_flist **base, long long checkmin);
void	ft_loputnbr(void* z, t_flist **base);
void    ft_checklongitude(long long z, t_flist **base, long long *checkmin);
void    ft_loputnbrindentu(void*  z,t_flist *base, int *check);
void    ft_indentdchar(t_flist **base);
void    ft_checkminu(void* z, t_flist **base, unsigned long long *checkmin);
void    ft_loputnbrindentprintu(t_flist *base, int check);
void    ft_uputnbr(void* z, t_flist **base);
void    ft_indentd2(t_flist **base, int check);
void    ft_indentd3(t_flist **base);
void    ft_indent4(t_flist **base);
void    functionindent5(t_flist *base, int *check);
void    ft_indentdchar(t_flist **base);
void    ft_loputnbrindentprint(t_flist *base, int check, int checkmin);
void    ft_loputnbrindentu(void*  z,t_flist *base, int *check);
void    ft_putsix(long long z, t_flist **base);
int     ft_print_float(int *count, long long per, int *len, long double fl);
int     ft_print_float3(int **count, long long per);
void    ft_loputnbrindentu(void*  z,t_flist *base, int *check);
int	    ft_count_sympoint(long double f, t_flist *flags);
void    ft_checklongitudex(long long z, t_flist **base, long long checkmin);
void    ft_loputnbrindentux(long long  z,t_flist *base, int *check);
void    functflag2(char **p, t_flist *base);
void    ft_checklongitudeo(long long z, t_flist **base, long long checkmin);
void    ft_loputnbrindent(long long  z,t_flist *base, int *check);
void    ft_convertation2(long long y);
void    floatconvert(long double *z, t_flist **base);
int	    ft_single_part(double f);
int	    ft_print_accuracy(long double f, int len);
void	ft_putnbr2(long long n);
int     ft_check_last_symb(long double fl, int len);
void    countresh2(long long z, t_flist *base, int check, long long checkmin);







# endif
