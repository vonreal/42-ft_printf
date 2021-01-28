#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int     main(void)
{
    ft_printf("ft_printf: hello [%10d] world\n", 7);
    printf("   printf: hello [%10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%4d] world\n", 77777);
    printf("   printf: hello [%4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-10d] world\n", 7);
    printf("   printf: hello [%-10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-4d] world\n", 77777);
    printf("   printf: hello [%-4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.10d] world\n", 7);
    printf("   printf: hello [%.10d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.4d] world\n", 77777);
    printf("   printf: hello [%.4d] world\n", 77777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%10.6d] world\n", 7);
    printf("   printf: hello [%10.6d] world\n", 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-10.6d] world\n", 7);
    printf("   printf: hello [%-10.6d] world\n", 7);
    write(1, "\n", 1);

        ft_printf("ft_printf: hello [%010.7d] world\n",12345);
    printf("   printf: hello [%010.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%010.3d] world\n",12345);
    printf("   printf: hello [%010.3d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*d] world\n", 10, 7);
    printf("   printf: hello [%*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*d] world\n", -10, 7);
    printf("   printf: hello [%*d] world\n", -10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%.*d] world\n", 10, 7);
    printf("   printf: hello [%.*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%0*d] world\n", 10, 7);
    printf("   printf: hello [%0*d] world\n", 10, 7);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*.*d] world\n", 10, 2, 777);
    printf("   printf: hello [%*.*d] world\n", 10, 2, 777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%*.*d] world\n", -10, 2, 777);
    printf("   printf: hello [%*.*d] world\n", -10, 2, 777);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-4.7d] world\n",12345);
    printf("   printf: hello [%-4.7d] world\n",12345);
    write(1, "\n", 1);

    ft_printf("ft_printf: hello [%-7.3d] world\n",12345);
    printf("   printf: hello [%-7.3d] world\n",12345);
    write(1, "\n", 1);
    return (0);
}