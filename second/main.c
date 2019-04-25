#include "libft/libft.h"
#include "libft/printf.h"
#include <stdio.h>
int main()
{
    long long a = 99999999999999;

   /*printf("%d", printf("the %x", 1));
    printf("\n");
    printf("%d", ft_printf("the %x", 1));
    printf("\n");

    printf("2\n");
    printf("%d", printf("%x", -1));
    printf("\n");
    printf("%d", ft_printf("%x", -1));
    printf("\n");

    printf("3\n");
    printf("%d", printf("%x is one", 1));
    printf("\n");
    printf("%d", ft_printf("%x is one", 1));
    printf("\n");

    printf("4\n");
    printf("%d", printf("%x", 4242));
    printf("\n");
    printf("%d", ft_printf("%x", 4242));
    printf("\n");

    printf("5\n");
    printf("%d", printf("%x", -4242));
    printf("\n");
    printf("%d", ft_printf("%x", -4242));
    printf("\n");

    printf("6\n");
    printf("%d", printf("%x", 2147483647));
    printf("\n");
    printf("%d", ft_printf("%x", 2147483647));
    printf("\n");

    printf("7\n");
    printf("%d", printf("%x", 2147483648));
    printf("\n");
    printf("%d", ft_printf("%x", 2147483648));
    printf("\n");

    printf("8\n");
    printf("%d", printf("%x", -2147483648));
    printf("\n");
    printf("%d", ft_printf("%x", -2147483648));
    printf("\n");

    printf("9\n");
    printf("%d", printf("%x", -2147483649));
    printf("\n");
    printf("%d", ft_printf("%x", -2147483649));
    printf("\n");

    printf("10\n");
    printf("%d", printf("% x", 42));
    printf("\n");
    printf("%d", ft_printf("% x", 42));
    printf("\n");

    printf("11\n");
    printf("%d", printf("% x", -42));
    printf("\n");
    printf("%d", ft_printf("% x", -42));
    printf("\n");

    printf("12\n");
    printf("%d", printf("%+x", 42));
    printf("\n");
    printf("%d", ft_printf("%+x", 42));
    printf("\n");

    printf("13\n");
    printf("%d", printf("%+x", -42));
    printf("\n");
    printf("%d", ft_printf("%+x", -42));
    printf("\n");

    printf("14\n");
    printf("%d", printf("%+x", 0));
    printf("\n");
    printf("%d", ft_printf("%+x", 0));
    printf("\n");*/

    /*printf("15\n");
    long long l = 4242424242424242424;
    printf("%d", printf("%+llx", 4242424242424242424));
    printf("\n");
    printf("%d", ft_printf("%+llx", 4242424242424242424));
    printf("\n");
    printf("16\n");
    printf("%d", printf("% +x", 42));
    printf("\n");
    printf("%d", ft_printf("% +x", 42));
    printf("\n");

    printf("17\n");
    printf("%d", printf("% +x", -42));
    printf("\n");
    printf("%d", ft_printf("% +x", -42));
    printf("\n");

    printf("18\n");
    printf("%d", printf("%+ x", 42));
    printf("\n");
    printf("%d", ft_printf("%+ x", 42));
    printf("\n");

    printf("19\n");
    printf("%d", printf("%+ x", -42));
    printf("\n");
    printf("%d", ft_printf("%+ x", -42));
    printf("\n");

    printf("20\n");
    printf("%d", printf("%  +x", 42));
    printf("\n");
    printf("%d", ft_printf("%  +x", 42));
    printf("\n");

    printf("21\n");
    printf("%d", printf("%  +x", -42));
    printf("\n");
    printf("%d", ft_printf("%  +x", -42));
    printf("\n");

    printf("22\n");
    printf("%d", printf("%+  x", 42));
    printf("\n");
    printf("%d", ft_printf("%+  x", 42));
    printf("\n");

    printf("23\n");
    printf("%d", printf("%+  x", -42));
    printf("\n");
    printf("%d", ft_printf("%+  x", -42));
    printf("\n");

    printf("24\n");
    printf("%d", printf("% ++x", 42));
    printf("\n");
    printf("%d", ft_printf("% ++x", 42));
    printf("\n");

    printf("25\n");
    printf("%d", printf("% ++x", -42));
    printf("\n");
    printf("%d", ft_printf("% ++x", -42));
    printf("\n");

    printf("26\n");
    printf("%d", printf("%++ x", 42));
    printf("\n");
    printf("%d", ft_printf("%++ x", 42));
    printf("\n");

    printf("27\n");
    printf("%d", printf("%++ x", -42));
    printf("\n");
    printf("%d", ft_printf("%++ x", -42));
    printf("\n");

    printf("28\n");
    printf("%d", printf("%0x", -42));
    printf("\n");
    printf("%d", ft_printf("%0x", -42));
    printf("\n");

    printf("29\n");
    printf("%d", printf("%00x", -42));
    printf("\n");
    printf("%d", ft_printf("%00x", -42));
    printf("\n");

    printf("30\n");
    printf("%d", printf("%5x", 42));
    printf("\n");
    printf("%d", ft_printf("%5x", 42));
    printf("\n");

    printf("31\n");
    printf("%d", printf("%05x", 42));
    printf("\n");
    printf("%d", ft_printf("%05x", 42));
    printf("\n");

    printf("32\n");
    printf("%d", printf("%0+5x", 42));
    printf("\n");
    printf("%d", ft_printf("%0+5x", 42));
    printf("\n");

    printf("33\n");
    printf("%d", printf("%5x", -42));
    printf("\n");
    printf("%d", ft_printf("%5x", -42));
    printf("\n");

    printf("34\n");
    printf("%d", printf("%05x", -42));
    printf("\n");
    printf("%d", ft_printf("%05x", -42));
    printf("\n");

    printf("35\n");
    printf("%d", printf("%0+5x", -42));
    printf("\n");
    printf("%d", ft_printf("%0+5x", -42));
    printf("\n");

    printf("36\n");
    printf("%d", printf("%-5x", 42));
    printf("\n");
    printf("%d", ft_printf("%-5x", 42));
    printf("\n");

    printf("37\n");
    printf("%d", printf("%-05x", 42));
    printf("\n");
    printf("%d", ft_printf("%-05x", 42));
    printf("\n");

    printf("38\n");
    printf("%d", printf("%-5x", -42));
    printf("\n");
    printf("%d", ft_printf("%-5x", -42));
    printf("\n");

    printf("39\n");
    printf("%d", printf("%-05x", -42));
    printf("\n");
    printf("%d", ft_printf("%-05x", -42));
    printf("\n");

    printf("40\n");
    printf("%d", printf("%hx", 32767));
    printf("\n");
    printf("%d", ft_printf("%hx", 32767));
    printf("\n");

    printf("41\n");
    short int d = -32769;
    printf("%d", printf("%hx", d));
    printf("\n");
    printf("%d", ft_printf("%hx", d));
    printf("\n");

    printf("42\n");
    printf("%d", printf("%hx", 32768));
    printf("\n");
    printf("%d", ft_printf("%hx", 32768));
    printf("\n");

    printf("43\n");
    short int s = -32769;
    printf("%d", printf("%hx", s));
    printf("\n");
    printf("%d", ft_printf("%hx", s));
    printf("\n");

    printf("44\n");
    printf("%d", printf("%hhx", 127));
    printf("\n");
    printf("%d", ft_printf("%hhx", 127));
    printf("\n");

    printf("45\n");
    printf("%d", printf("%hhx", 128));
    printf("\n");
    printf("%d", ft_printf("%hhx", 128));
    printf("\n");

    printf("46\n");
    printf("%d", printf("%hhx", -128));
    printf("\n");
    printf("%d", ft_printf("%hhx", -128));
    printf("\n");

    printf("47\n");
    printf("%d", printf("%hhx", -129));
    printf("\n");
    printf("%d", ft_printf("%hhx", -129));
    printf("\n");

    printf("48\n");
    printf("%d", printf("%lx", 2147483647));
    printf("\n");
    printf("%d", ft_printf("%lx", 2147483647));
    printf("\n");

    printf("49\n");
    printf("%d", printf("%lx", -2147483648));
    printf("\n");
    printf("%d", ft_printf("%lx", -2147483648));
    printf("\n");

    printf("50\n");
    printf("%d", printf("%lx", 2147483648));
    printf("\n");
    printf("%d", ft_printf("%lx", 2147483648));
    printf("\n");

    printf("51\n");
    printf("%d", printf("%lx", -2147483649));
    printf("\n");
    printf("%d", ft_printf("%lx", -2147483649));
    printf("\n");

    printf("52\n");
    printf("%d", printf("%llx", 9223372036854775807));
    printf("\n");
    printf("%d", ft_printf("%llx", 9223372036854775807));
    printf("\n");

    printf("53\n");
    printf("%d", printf("%llx", -9223372036854775808));
    printf("\n");
    printf("%d", ft_printf("%llx", -9223372036854775808));
    printf("\n");

    printf("54\n");
    printf("%d", printf("%x %x", 1, -2));
    printf("\n");
    printf("%d", ft_printf("%x %x", 1, -2));
    printf("\n");

    printf("55\n");
    printf("%d", printf("%x %x %x", 1, -2, 33));
    printf("\n");
    printf("%d", ft_printf("%x %x %x", 1, -2, 33));
    printf("\n");

    printf("56\n");
    printf("%d", printf("%x %x %x %x", 1, -2, 33, 42));
    printf("\n");
    printf("%d", ft_printf("%x %x %x %x", 1, -2, 33, 42));
    printf("\n");

    printf("57\n");
    printf("%d", printf("%x %x %x %x gg!", 1, -2, 33, 42, 0));
    printf("\n");
    printf("%d", ft_printf("%x %x %x %x gg!", 1, -2, 33, 42, 0));
    printf("\n");

    printf("58\n");
    printf("%d", printf("%4.15x", 42));
    printf("\n");
    printf("%d", ft_printf("%4.15x", 42));
    printf("\n");*/

    printf("59\n");
    printf("%d", printf("%.2x", 4242));
    printf("\n");
    printf("%d", ft_printf("%.2x", 4242));
    printf("\n");

    /*printf("60\n");
    printf("%d", printf("%.10x", 4242));
    printf("\n");
    printf("%d", ft_printf("%.10x", 4242));
    printf("\n");

    printf("61\n");
    printf("%d", printf("%10.5x", 4242));
    printf("\n");
    printf("%d", ft_printf("%10.5x", 4242));
    printf("\n");

    printf("62\n");
    printf("%d", printf("%-10.5x", 4242));
    printf("\n");
    printf("%d", ft_printf("%-10.5x", 4242));
    printf("\n");

    printf("63\n");
    printf("%d", printf("% 10.5x", 4242));
    printf("\n");
    printf("%d", ft_printf("% 10.5x", 4242));
    printf("\n");

    printf("64\n");
    printf("%d", printf("%+10.5x", 4242));
    printf("\n");
    printf("%d", ft_printf("%+10.5x", 4242));
    printf("\n");

    printf("65\n");
    printf("%d", printf("%-+10.5x", 4242));
    printf("\n");
    printf("%d", ft_printf("%-+10.5x", 4242));
    printf("\n");

    printf("66\n");
    printf("%d", printf("%03.2x", 0));
    printf("\n");
    printf("%d", ft_printf("%03.2x", 0));
    printf("\n");

    printf("67\n");
    printf("%d", printf("%03.2x", 1));
    printf("\n");
    printf("%d", ft_printf("%03.2x", 1));
    printf("\n");

    printf("68\n");
    printf("%d", printf("%03.2x", -1));
    printf("\n");
    printf("%d", ft_printf("%03.2x", -1));
    printf("\n");

    printf("69\n");
    printf("%d", printf("@moulitest: %.10x", -42));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %.10x", -42));
    printf("\n");

    printf("70\n");
    printf("%d", printf("@moulitest: %.x %.0x", 42, 43));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %.x %.0x", 42, 43));
    printf("\n");

    printf("71\n");
    printf("%d", printf("@moulitest: %.x %.0x", 0, 0));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %.x %.0x", 0, 0));
    printf("\n");

    printf("72\n");
    printf("%d", printf("@moulitest: %5.x %5.0x", 0, 0));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %5.x %5.0x", 0, 0));
    printf("\n");*/
    return(0);
}
