#include <stdio.h>

int	ft_printf(const char *format, ...);

int     main(void)
{
    int a;
    char b;
    char *c;
    
    a = 100;
    b = 'c';
    c = &b;

    printf("printf:\n");
    printf("a = %#x\n", &a);
    printf("b = %#x\n", &b);
    printf("c = %#x\n", &c);

    ft_printf("ft_printf:\n");
    ft_printf("a = %#x\n", &a);
    ft_printf("b = %#x\n", &b);
    ft_printf("c = %#x\n", &c);

    return (0);
}