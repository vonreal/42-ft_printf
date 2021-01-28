#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%%c------------------\n");
    // <1> .(null)
    printf("1-0: %.c\n", 'a');
    // printf("1-1: %.c\n", INT_MAX);
    // printf("1-2: %.c\n", INT_MIN);

    // <2> .(0)
    printf("2-0: %.0c\n", 'a');
    // printf("2-1: %.0c\n", INT_MAX);
    // printf("2-2: %.0c\n", INT_MIN);

    // <3> number: .(plus number)
    printf("3-0: %.1c\n", 'a');
    printf("3-1: %.10c\n", 'a');
    printf("3-2: %.100c\n", 'a');
    //printf("3-3: %.2147483647c\n", 'a');
    // printf("3-4: %.1c\n", INT_MAX);
    // printf("3-5: %.10c\n", INT_MAX);
    // printf("3-6: %.100c\n", INT_MAX);
    //printf("3-7: %.2147483647c\n", INT_MAX);
    // printf("3-8: %.1c\n", INT_MIN);
    // printf("3-9: %.10c\n", INT_MIN);
    // printf("3-10: %.100c\n", INT_MIN);
    //printf("3-11: %.2147483647c\n", INT_MIN);

    // <4> number: .(minus number) 
    // printf("4-0: %.-1c\n", 'a');
    // printf("4-1: %.-10c\n", 'a');
    // printf("4-2: %.-100c\n", 'a');
    // printf("4-3: %.-2147483647c\n", 'a');
    // printf("4-4: %.-1c\n", INT_MAX);
    // printf("4-5: %.-10c\n", INT_MAX);
    // printf("4-6: %.-100c\n", INT_MAX);
    // printf("4-7: %.-2147483647c\n", INT_MAX);
    // printf("4-8: %.-1c\n", INT_MIN);
    // printf("4-9: %.-10c\n", INT_MIN);
    // printf("4-10: %.-100c\n", INT_MIN);
    // printf("4-11: %.-2147483647c\n", INT_MIN);

    // <5> .(*): * = 0
    printf("5-0: %.*c\n", 0, 'a');
    //printf("5-1: %.*c\n", 0, INT_MAX);
    //printf("5-2: %.*c\n", 0, INT_MIN);

    // <6> .(*): * = plus number
    printf("6-0: %.*c\n", 1, 'a');
    printf("6-1: %.*c\n", 10, 'a');
    printf("6-2: %.*c\n", 100, 'a');
    //printf("6-3: %.*c\n", INT_MAX, 'a');
    // printf("6-4: %.*c\n", 1, INT_MAX);
    // printf("6-5: %.*c\n", 10, INT_MAX);
    // printf("6-6: %.*c\n", 100, INT_MAX);
    //printf("6-7: %.*c\n", INT_MAX, INT_MAX);
    // printf("6-8: %.*c\n", 1, INT_MIN);
    // printf("6-9: %.*c\n", 10, INT_MIN);
    // printf("6-10: %.*c\n", 100, INT_MIN);
    //printf("6-11: %.*c\n", INT_MAX, INT_MIN);

    // <7> .(*): * = minus number
    printf("8-0: %.*c\n", -1, 'a');
    printf("8-1: %.*c\n", -10, 'a');
    printf("8-2: %.*c\n", -100, 'a');
    //printf("8-3: %.*c\n", INT_MIN, 'a');
    // printf("8-4: %.*c\n", -1, INT_MAX);
    // printf("8-5: %.*c\n", -10, INT_MAX);
    // printf("8-6: %.*c\n", -100, INT_MAX);
    // printf("8-7: %.*c\n", INT_MIN, INT_MAX);
    // printf("8-8: %.*c\n", -1, INT_MIN);
    // printf("8-9: %.*c\n", -10, INT_MIN);
    // printf("8-10: %.*c\n", -100, INT_MIN);
    //printf("8-11: %.*c\n", INT_MIN, INT_MIN);
    printf("\n");
    return (0);
}