#include <stdio.h>
#include <limits.h>

int	main(void)
{
    int print_min;

    print_min = 32;
	printf("%%d------------------\n");
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("\n");

    printf("%%i------------------\n");
    printf("INT_MIN: %i\n", INT_MIN);
    printf("INT_MAX: %i\n", INT_MAX);
    printf("\n");

    printf("%%u------------------\n");
    printf("UINT_MAX: %u", UINT_MAX);
    printf("\n");

    printf("%%x------------------\n");
    printf("UINT_MAX: %x", UINT_MAX);
    printf("\n");

    printf("%%X------------------\n");
    printf("UINT_MAX: %X", UINT_MAX);
    printf("\n");

    printf("%%c------------------\n");
    while (print_min >= 32 && print_min <= 126)
    {
        printf("%c\n", print_min);
        print_min++;
    }
    printf("\n");

    printf("%%s------------------\n");
    printf("%s", "Hello World!");
    printf("\n");

    printf("%%p------------------\n");
    printf("%#x", &print_min);
    printf("\n");
    
    printf("%%-------------------\n");
    printf("%%");
    printf("\n");
	return (0);
}
