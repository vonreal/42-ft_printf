#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
int print_min;

    print_min = 32;
	ft_print("%%d------------------\n");
    ft_print("INT_MIN: %d\n", INT_MIN);
    ft_print("INT_MAX: %d\n", INT_MAX);
    ft_print("\n");

    ft_print("%%i------------------\n");
    ft_print("INT_MIN: %i\n", INT_MIN);
    ft_print("INT_MAX: %i\n", INT_MAX);
    ft_print("\n");

    ft_print("%%u------------------\n");
    ft_print("UINT_MAX: %u", UINT_MAX);
    ft_print("\n");

    ft_print("%%x------------------\n");
    ft_print("UINT_MAX: %x", UINT_MAX);
    ft_print("\n");

    ft_print("%%X------------------\n");
    ft_print("UINT_MAX: %X", UINT_MAX);
    ft_print("\n");

    ft_print("%%c------------------\n");
    while (print_min >= 32 && print_min <= 126)
    {
        ft_print("%c\n", print_min);
        print_min++;
    }
    ft_print("\n");

    ft_print("%%s------------------\n");
    ft_print("%s", "Hello World!");
    ft_print("\n");

    ft_print("%%p------------------\n");
    ft_print("%#x", &print_min);
    ft_print("\n");
    
    ft_print("%%-------------------\n");
    ft_print("%%");
    ft_print("\n");
	return (0);
}
