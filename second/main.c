#include "libft/libft.h"
#include "libft/printf.h"
#include <stdio.h>


int main()
{


/*

  printf("1\n");
    printf("%d", printf("the %o", 1));
    printf("\n");
    printf("%d", ft_printf("the %o", 1));
    printf("\n");

    printf("2\n");
    printf("%d", printf("%o", -1));
    printf("\n");
    printf("%d", ft_printf("%o", -1));
    printf("\n");

    printf("3\n");
    printf("%d", printf("%o is one", 1));
    printf("\n");
    printf("%d", ft_printf("%o is one", 1));
    printf("\n");

    printf("4\n");
    printf("%d", printf("%o", 4242));
    printf("\n");
    printf("%d", ft_printf("%o", 4242));
    printf("\n");

    printf("5\n");
    printf("%d", printf("%o", -4242));
    printf("\n");
    printf("%d", ft_printf("%o", -4242));
    printf("\n");

    printf("6\n");
    printf("%d", printf("%o", 2147483647));
    printf("\n");
    printf("%d", ft_printf("%o", 2147483647));
    printf("\n");

    printf("7\n");
    printf("%d", printf("%o", 2147483648));
    printf("\n");
    printf("%d", ft_printf("%o", 2147483648));
    printf("\n");

    printf("8\n");
    printf("%d", printf("%o", -2147483648));
    printf("\n");
    printf("%d", ft_printf("%o", -2147483648));
    printf("\n");

    printf("9\n");
    printf("%d", printf("%o", -2147483649));
    printf("\n");
    printf("%d", ft_printf("%o", -2147483649));
    printf("\n");

    printf("10\n");
    printf("%d", printf("% o", 42));
    printf("\n");
    printf("%d", ft_printf("% o", 42));
    printf("\n");

    printf("11\n");
    printf("%d", printf("% o", -42));
    printf("\n");
    printf("%d", ft_printf("% o", -42));
    printf("\n");

    printf("12\n");
    printf("%d", printf("%+o", 42));
    printf("\n");
    printf("%d", ft_printf("%+o", 42));
    printf("\n");

    printf("13\n");
    printf("%d", printf("%+o", -42));
    printf("\n");
    printf("%d", ft_printf("%+o", -42));
    printf("\n");

    printf("14\n");
    printf("%d", printf("%+o", 0));
    printf("\n");
    printf("%d", ft_printf("%+o", 0));
    printf("\n");

    printf("15\n");
    long long l = 4242424242424242424;
    printf("%d", printf("%+llo", l));
    printf("\n");
    printf("%d", ft_printf("%+llo", l));
    printf("\n");
    printf("16\n");
    printf("%d", printf("% +o", 42));
    printf("\n");
    printf("%d", ft_printf("% +o", 42));
    printf("\n");

    printf("17\n");
    printf("%d", printf("% +o", -42));
    printf("\n");
    printf("%d", ft_printf("% +o", -42));
    printf("\n");

    printf("18\n");
    printf("%d", printf("%+ o", 42));
    printf("\n");
    printf("%d", ft_printf("%+ o", 42));
    printf("\n");

    printf("19\n");
    printf("%d", printf("%+ o", -42));
    printf("\n");
    printf("%d", ft_printf("%+ o", -42));
    printf("\n");

    printf("20\n");
    printf("%d", printf("%  +o", 42));
    printf("\n");
    printf("%d", ft_printf("%  +o", 42));
    printf("\n");

    printf("21\n");
    printf("%d", printf("%  +o", -42));
    printf("\n");
    printf("%d", ft_printf("%  +o", -42));
    printf("\n");

    printf("22\n");
    printf("%d", printf("%+  o", 42));
    printf("\n");
    printf("%d", ft_printf("%+  o", 42));
    printf("\n");

    printf("23\n");
    printf("%d", printf("%+  o", -42));
    printf("\n");
    printf("%d", ft_printf("%+  o", -42));
    printf("\n");

    printf("24\n");
    printf("%d", printf("% ++o", 42));
    printf("\n");
    printf("%d", ft_printf("% ++o", 42));
    printf("\n");

    printf("25\n");
    printf("%d", printf("% ++o", -42));
    printf("\n");
    printf("%d", ft_printf("% ++o", -42));
    printf("\n");

    printf("26\n");
    printf("%d", printf("%++ o", 42));
    printf("\n");
    printf("%d", ft_printf("%++ o", 42));
    printf("\n");

    printf("27\n");
    printf("%d", printf("%++ o", -42));
    printf("\n");
    printf("%d", ft_printf("%++ o", -42));
    printf("\n");

    printf("28\n");
    printf("%d", printf("%0o", -42));
    printf("\n");
    printf("%d", ft_printf("%0o", -42));
    printf("\n");

    printf("29\n");
    printf("%d", printf("%00o", -42));
    printf("\n");
    printf("%d", ft_printf("%00o", -42));
    printf("\n");

    printf("30\n");
    printf("%d", printf("%5o", 42));
    printf("\n");
    printf("%d", ft_printf("%5o", 42));
    printf("\n");

    printf("31\n");
    printf("%d", printf("%05o", 42));
    printf("\n");
    printf("%d", ft_printf("%05o", 42));
    printf("\n");

    printf("32\n");
    printf("%d", printf("%0+5o", 42));
    printf("\n");
    printf("%d", ft_printf("%0+5o", 42));
    printf("\n");

    printf("33\n");
    printf("%d", printf("%5o", -42));
    printf("\n");
    printf("%d", ft_printf("%5o", -42));
    printf("\n");

    printf("34\n");
    printf("%d", printf("%05o", -42));
    printf("\n");
    printf("%d", ft_printf("%05o", -42));
    printf("\n");

    printf("35\n");
    printf("%d", printf("%0+5o", -42));
    printf("\n");
    printf("%d", ft_printf("%0+5o", -42));
    printf("\n");

    printf("36\n");
    printf("%d", printf("%-5o", 42));
    printf("\n");
    printf("%d", ft_printf("%-5o", 42));
    printf("\n");

    printf("37\n");
    printf("%d", printf("%-05o", 42));
    printf("\n");
    printf("%d", ft_printf("%-05o", 42));
    printf("\n");

    printf("38\n");
    printf("%d", printf("%-5o", -42));
    printf("\n");
    printf("%d", ft_printf("%-5o", -42));
    printf("\n");

    printf("39\n");
    printf("%d", printf("%-05o", -42));
    printf("\n");
    printf("%d", ft_printf("%-05o", -42));
    printf("\n");

    printf("40\n");
    printf("%d", printf("%ho", 32767));
    printf("\n");
    printf("%d", ft_printf("%ho", 32767));
    printf("\n");

    printf("41\n");
    short int d = -32769;
    printf("%d", printf("%ho", d));
    printf("\n");
    printf("%d", ft_printf("%ho", d));
    printf("\n");

    printf("42\n");
    printf("%d", printf("%ho", 32768));
    printf("\n");
    printf("%d", ft_printf("%ho", 32768));
    printf("\n");

    printf("43\n");
    short int s = -32769;
    printf("%d", printf("%ho", s));
    printf("\n");
    printf("%d", ft_printf("%ho", s));
    printf("\n");

    printf("44\n");
    printf("%d", printf("%hho", 127));
    printf("\n");
    printf("%d", ft_printf("%hho", 127));
    printf("\n");

    printf("45\n");
    printf("%d", printf("%hho", 128));
    printf("\n");
    printf("%d", ft_printf("%hho", 128));
    printf("\n");

    printf("46\n");
    printf("%d", printf("%hho", -128));
    printf("\n");
    printf("%d", ft_printf("%hho", -128));
    printf("\n");

    printf("47\n");
    printf("%d", printf("%hho", -129));
    printf("\n");
    printf("%d", ft_printf("%hho", -129));
    printf("\n");

    printf("48\n");
    printf("%d", printf("%lo", 2147483647));
    printf("\n");
    printf("%d", ft_printf("%lo", 2147483647));
    printf("\n");

    printf("49\n");
    printf("%d", printf("%lo", -2147483648));
    printf("\n");
    printf("%d", ft_printf("%lo", -2147483648));
    printf("\n");

    printf("50\n");
    printf("%d", printf("%lo", 2147483648));
    printf("\n");
    printf("%d", ft_printf("%lo", 2147483648));
    printf("\n");

    printf("51\n");
    printf("%d", printf("%lo", -2147483649));
    printf("\n");
    printf("%d", ft_printf("%lo", -2147483649));
    printf("\n");

    printf("52\n");
    printf("%d", printf("%llo", 9223372036854775807));
    printf("\n");
    printf("%d", ft_printf("%llo", 9223372036854775807));
    printf("\n");

    printf("53\n");
    printf("%d", printf("%llo", -9223372036854775808));
    printf("\n");
    printf("%d", ft_printf("%llo", -9223372036854775808));
    printf("\n");

    printf("54\n");
    printf("%d", printf("%o %o", 1, -2));
    printf("\n");
    printf("%d", ft_printf("%o %o", 1, -2));
    printf("\n");

    printf("55\n");
    printf("%d", printf("%o %o %o", 1, -2, 33));
    printf("\n");
    printf("%d", ft_printf("%o %o %o", 1, -2, 33));
    printf("\n");

    printf("56\n");
    printf("%d", printf("%o %o %o %o", 1, -2, 33, 42));
    printf("\n");
    printf("%d", ft_printf("%o %o %o %o", 1, -2, 33, 42));
    printf("\n");

    printf("57\n");
    printf("%d", printf("%o %o %o %o gg!", 1, -2, 33, 42, 0));
    printf("\n");
    printf("%d", ft_printf("%o %o %o %o gg!", 1, -2, 33, 42, 0));
    printf("\n");

    printf("58\n");
    printf("%d", printf("%4.15o", 42));
    printf("\n");
    printf("%d", ft_printf("%4.15o", 42));
    printf("\n");

    printf("59\n");
    printf("%d", printf("%.2o", 4242));
    printf("\n");
    printf("%d", ft_printf("%.2o", 4242));
    printf("\n");

    printf("60\n");
    printf("%d", printf("%.10o", 4242));
    printf("\n");
    printf("%d", ft_printf("%.10o", 4242));
    printf("\n");

    printf("61\n");
    printf("%d", printf("%10.5o", 4242));
    printf("\n");
    printf("%d", ft_printf("%10.5o", 4242));
    printf("\n");

    printf("62\n");
    printf("%d", printf("%-10.5o", 4242));
    printf("\n");
    printf("%d", ft_printf("%-10.5o", 4242));
    printf("\n");

    printf("63\n");
    printf("%d", printf("% 10.5o", 4242));
    printf("\n");
    printf("%d", ft_printf("% 10.5o", 4242));
    printf("\n");

    printf("64\n");
    printf("%d", printf("%+10.5o", 4242));
    printf("\n");
    printf("%d", ft_printf("%+10.5o", 4242));
    printf("\n");

    printf("65\n");
    printf("%d", printf("%-+10.5o", 4242));
    printf("\n");
    printf("%d", ft_printf("%-+10.5o", 4242));
    printf("\n");

    printf("66\n");
    printf("%d", printf("%03.2#o", 0));
    printf("\n");
    printf("%d", ft_printf("%03.2#o", 0));
    printf("\n");

    printf("67\n");
    printf("%d", printf("%03.2o#", 1));
    printf("\n");
    printf("%d", ft_printf("%03.2o#", 1));
    printf("\n");
*/
    printf("68\n");
    printf("%d", printf("%03.2#o", -1));
    printf("\n");
    printf("%d", ft_printf("%03.2#o", -1));
    printf("\n");
     printf("%d", printf("%o", -1));
/*
    printf("69\n");
    printf("%d", printf("@moulitest: %.10o", -42));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %.10o", -42));
    printf("\n");

    printf("70\n");
    printf("%d", printf("@moulitest: %#.o %.0#o", 42, 43));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %#.o %.0#o", 42, 43));
    printf("\n");

    printf("71\n");
    printf("%d", printf("@moulitest: %.#o %.0o", 0, 0));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %.#o %.0o", 0, 0));
    printf("\n");

    printf("72\n");
    printf("%d", printf("@moulitest: %5.o %5#.0o", 0, 0));
    printf("\n");
    printf("%d", ft_printf("@moulitest: %5.o %#5.0o", 0, 0));
    printf("\n");
*/
    return (0);
}
