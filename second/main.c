#include "libft/libft.h"
#include "libft/printf.h"
#include <stdio.h>
int main()
{
    long long a = 99999999999999;
    
    printf("%d",printf("%10.5o", 4242));//63
    printf("\n");
    ft_printf("%d",ft_printf("%10.5o", 4242));//63
    printf("\n");

     printf("%d",printf("% 10.5o", 4242));//65
    printf("\n");
    ft_printf("%d",ft_printf("% 10.5o", 4242));//65
    printf("\n");

    printf("%d",printf("%+10.5o", 4242));//66
    printf("\n");
    ft_printf("%d",ft_printf("%+10.5o", 4242));//66
    printf("\n");

    printf("%d",printf("%03.2o", -1));//70
    printf("\n");
    ft_printf("%d",ft_printf("%03.2o", -1));//70
    printf("\n");

    printf("%d",printf("@moulitest: %.10o", -42));//71
    printf("\n");
    ft_printf("%d",ft_printf("@moulitest: %.10o", -42));//71
    printf("\n");
    return(0);
}