#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
int print_min;

    print_min = 32;
	ft_printf("%%d------------------\n");
    ft_printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("\n");

    ft_printf("%%i------------------\n");
    ft_printf("INT_MIN: %i\n", INT_MIN);
    ft_printf("INT_MAX: %i\n", INT_MAX);
    ft_printf("\n");

    ft_printf("%%u------------------\n");
    ft_printf("UINT_MAX: %u", UINT_MAX);
    ft_printf("\n");

    ft_printf("%%x------------------\n");
    ft_printf("UINT_MAX: %x", UINT_MAX);
    ft_printf("\n");

    ft_printf("%%X------------------\n");
    ft_printf("UINT_MAX: %X", UINT_MAX);
    ft_printf("\n");

    ft_printf("%%c------------------\n");
    while (print_min >= 32 && print_min <= 126)
    {
        ft_printf("%c\n", print_min);
        print_min++;
    }
    ft_printf("\n");

    ft_printf("%%s------------------\n");
    ft_printf("%s", "Hello World!");
    ft_printf("\n");

    ft_printf("%%p------------------\n");
    ft_printf("%p", &print_min);
    ft_printf("\n");
    
    ft_printf("%%-------------------\n");
    ft_printf("%%");
    ft_printf("\n");
	return (0);
}
