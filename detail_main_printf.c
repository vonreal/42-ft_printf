#include <stdio.h>
#include <limits.h>

int	main(void)
{
    int print_min;

    print_min = 32;
	print("%%d------------------\n");
    print("INT_MIN: %d\n", INT_MIN);
    print("INT_MAX: %d\n", INT_MAX);
    print("\n");

    print("%%i------------------\n");
    print("INT_MIN: %i\n", INT_MIN);
    print("INT_MAX: %i\n", INT_MAX);
    print("\n");

    print("%%u------------------\n");
    print("UINT_MAX: %u", UINT_MAX);
    print("\n");

    print("%%x------------------\n");
    print("UINT_MAX: %x", UINT_MAX);
    print("\n");

    print("%%X------------------\n");
    print("UINT_MAX: %X", UINT_MAX);
    print("\n");

    print("%%c------------------\n");
    while (print_min >= 32 && print_min <= 126)
    {
        print("%c\n", print_min);
        print_min++;
    }
    print("\n");

    print("%%s------------------\n");
    print("%s", "Hello World!");
    print("\n");

    print("%%p------------------\n");
    print("%#x", &print_min);
    print("\n");
    
    print("%%-------------------\n");
    print("%%");
    print("\n");
	return (0);
}
