#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%%i------------------\n");
    // <1> .(null)
    printf("1-0: %.i\n", 12345);
    printf("1-1: %.i\n", INT_MAX);
    printf("1-2: %.i\n", INT_MIN);

    // <2> .(0)
    printf("2-0: %.0i\n", 12345);
    printf("2-1: %.0i\n", INT_MAX);
    printf("2-2: %.0i\n", INT_MIN);

    // <3> number: .(plus number)
    printf("3-0: %.1i\n", 12345);
    printf("3-1: %.10i\n", 12345);
    printf("3-2: %.100i\n", 12345);
    //printf("3-3: %.2147483647i\n", 12345);
    printf("3-4: %.1i\n", INT_MAX);
    printf("3-5: %.10i\n", INT_MAX);
    printf("3-6: %.100i\n", INT_MAX);
    //printf("3-7: %.2147483647i\n", INT_MAX);
    printf("3-8: %.1i\n", INT_MIN);
    printf("3-9: %.10i\n", INT_MIN);
    printf("3-10: %.100i\n", INT_MIN);
    //printf("3-11: %.2147483647i\n", INT_MIN);

    // <4> number: .(minus number) 
    // printf("4-0: %.-1i\n", 12345);
    // printf("4-1: %.-10i\n", 12345);
    // printf("4-2: %.-100i\n", 12345);
    // printf("4-3: %.-2147483647i\n", 12345);
    // printf("4-4: %.-1i\n", INT_MAX);
    // printf("4-5: %.-10i\n", INT_MAX);
    // printf("4-6: %.-100i\n", INT_MAX);
    // printf("4-7: %.-2147483647i\n", INT_MAX);
    // printf("4-8: %.-1i\n", INT_MIN);
    // printf("4-9: %.-10i\n", INT_MIN);
    // printf("4-10: %.-100i\n", INT_MIN);
    // printf("4-11: %.-2147483647i\n", INT_MIN);

    // <5> .(*): * = 0
    printf("5-0: %.*i\n", 0, 12345);
    //printf("5-1: %.*i\n", 0, INT_MAX);
    //printf("5-2: %.*i\n", 0, INT_MIN);

    // <6> .(*): * = plus number
    printf("6-0: %.*i\n", 1, 12345);
    printf("6-1: %.*i\n", 10, 12345);
    printf("6-2: %.*i\n", 100, 12345);
    //printf("6-3: %.*i\n", INT_MAX, 12345);
    printf("6-4: %.*i\n", 1, INT_MAX);
    printf("6-5: %.*i\n", 10, INT_MAX);
    printf("6-6: %.*i\n", 100, INT_MAX);
    //printf("6-7: %.*i\n", INT_MAX, INT_MAX);
    printf("6-8: %.*i\n", 1, INT_MIN);
    printf("6-9: %.*i\n", 10, INT_MIN);
    printf("6-10: %.*i\n", 100, INT_MIN);
    //printf("6-11: %.*i\n", INT_MAX, INT_MIN);

    // <7> .(*): * = minus number
    printf("8-0: %.*i\n", -1, 12345);
    printf("8-1: %.*i\n", -10, 12345);
    printf("8-2: %.*i\n", -100, 12345);
    //printf("8-3: %.*i\n", INT_MIN, 12345);
    printf("8-4: %.*i\n", -1, INT_MAX);
    printf("8-5: %.*i\n", -10, INT_MAX);
    printf("8-6: %.*i\n", -100, INT_MAX);
    //printf("8-7: %.*i\n", INT_MIN, INT_MAX);
    printf("8-8: %.*i\n", -1, INT_MIN);
    printf("8-9: %.*i\n", -10, INT_MIN);
    printf("8-10: %.*i\n", -100, INT_MIN);
    //printf("8-11: %.*i\n", INT_MIN, INT_MIN);
    printf("\n");
    return (0);
}