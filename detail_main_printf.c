#include <stdio.h>
#include <limits.h>

int	main(void)
{
    int print_min;

    print_min = 32;
	printf("%%d------------------");
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("\n");

    printf("%%i------------------");
    printf("INT_MIN: %i\n", INT_MIN);
    printf("INT_MAX: %i\n", INT_MAX);
    printf("\n");

    printf("%%u------------------");
    printf("UINT_MAX: %u", UINT_MAX);
    printf("\n");

    printf("%%x------------------");
    printf("UINT_MAX: %x", UINT_MAX);
    printf("\n");

    printf("%%X------------------");
    printf("UINT_MAX: %X", UINT_MAX);
    printf("\n");

    printf("%%c------------------");
    while (print_min >= 32 && print_min <= 126)
    {
        printf("%c ", print_min);
        print_min++;
    }
    printf("\n");

    printf("%%s------------------");
    printf("%s", "Hello World!");
    printf("\n");

    printf("%%p------------------");
    printf("%#x", &print_min);
    printf("\n");
    
    printf("%%-------------------");
    printf("%%");
    printf("\n");
	return (0);
}
