#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);

int     main(void)
{
    ft_printf("1 ft_printf: hello [%10d] world\n", 7);
    printf("1   printf: hello [%10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("2 ft_printf: hello [%4d] world\n", 77777);
    printf("2    printf: hello [%4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("3 ft_printf: hello [%-10d] world\n", 7);
    printf("3    printf: hello [%-10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("4 ft_printf: hello [%-4d] world\n", 77777);
    printf("4    printf: hello [%-4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("5 ft_printf: hello [%.10d] world\n", 7);
    printf("5    printf: hello [%.10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("6 ft_printf: hello [%.4d] world\n", 77777);
    printf("6    printf: hello [%.4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("7 ft_printf: hello [%10.6d] world\n", 7);
    printf("7    printf: hello [%10.6d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("8 ft_printf: hello [%-10.6d] world\n", 7);
    printf("8    printf: hello [%-10.6d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("9 ft_printf: hello [%010.7d] world\n",12345);
    printf("9    printf: hello [%010.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("10 ft_printf: hello [%010.3d] world\n",12345);
    printf("10    printf: hello [%010.3d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("11 ft_printf: hello [%*d] world\n", 10, 7);
    printf("11    printf: hello [%*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("12 ft_printf: hello [%*d] world\n", -10, 7);
    printf("12    printf: hello [%*d] world\n", -10, 7);
    write(1, "\n", 1);

    ft_printf("13 ft_printf: hello [%.*d] world\n", 10, 7);
    printf("13    printf: hello [%.*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("14 ft_printf: hello [%0*d] world\n", 10, 7);
    printf("14    printf: hello [%0*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("15 ft_printf: hello [%*.*d] world\n", 10, 2, 777);
    printf("15    printf: hello [%*.*d] world\n", 10, 2, 777);
    write(1, "\n", 1);

    ft_printf("16 ft_printf: hello [%*.*d] world\n", -10, 2, 777);
    printf("16    printf: hello [%*.*d] world\n", -10, 2, 777);
    write(1, "\n", 1);

    ft_printf("17 ft_printf: hello [%-4.7d] world\n",12345);
    printf("17    printf: hello [%-4.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("18 ft_printf: hello [%-7.3d] world\n",12345);
    printf("18    printf: hello [%-7.3d] world\n",12345);
    write(1, "\n", 1);
    return (0);
}