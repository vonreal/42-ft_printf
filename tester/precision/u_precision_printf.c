#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%%u------------------\n");
    // <1> .(null)
    printf("1-0: %.u\n", 12345);
    printf("1-1: %.u\n", UINT_MAX);
    printf("1-2: %.u\n", INT_MIN);

    // <2> .(0)
    printf("2-0: %.0u\n", 12345);
    printf("2-1: %.0u\n", UINT_MAX);
    printf("2-2: %.0u\n", INT_MIN);

    // <3> number: .(plus number)
    printf("3-0: %.1u\n", 12345);
    printf("3-1: %.10u\n", 12345);
    printf("3-2: %.100u\n", 12345);
    //printf("3-3: %.2147483647u\n", 12345);
    printf("3-4: %.1u\n", UINT_MAX);
    printf("3-5: %.10u\n", UINT_MAX);
    printf("3-6: %.100u\n", UINT_MAX);
    //printf("3-7: %.2147483647u\n", UINT_MAX);
    printf("3-8: %.1u\n", INT_MIN);
    printf("3-9: %.10u\n", INT_MIN);
    printf("3-10: %.100u\n", INT_MIN);
    //printf("3-11: %.2147483647u\n", INT_MIN);

    // <4> number: .(minus number) 
    // printf("4-0: %.-1u\n", 12345);
    // printf("4-1: %.-10u\n", 12345);
    // printf("4-2: %.-100u\n", 12345);
    // printf("4-3: %.-2147483647u\n", 12345);
    // printf("4-4: %.-1u\n", UINT_MAX);
    // printf("4-5: %.-10u\n", UINT_MAX);
    // printf("4-6: %.-100u\n", UINT_MAX);
    // printf("4-7: %.-2147483647u\n", UINT_MAX);
    // printf("4-8: %.-1u\n", INT_MIN);
    // printf("4-9: %.-10u\n", INT_MIN);
    // printf("4-10: %.-100u\n", INT_MIN);
    // printf("4-11: %.-2147483647u\n", INT_MIN);

    // <5> .(*): * = 0
    printf("5-0: %.*u\n", 0, 12345);
    //printf("5-1: %.*u\n", 0, UINT_MAX);
    //printf("5-2: %.*u\n", 0, INT_MIN);

    // <6> .(*): * = plus number
    printf("6-0: %.*u\n", 1, 12345);
    printf("6-1: %.*u\n", 10, 12345);
    printf("6-2: %.*u\n", 100, 12345);
    //printf("6-3: %.*u\n", UINT_MAX, 12345);
    printf("6-4: %.*u\n", 1, UINT_MAX);
    printf("6-5: %.*u\n", 10, UINT_MAX);
    printf("6-6: %.*u\n", 100, UINT_MAX);
    //printf("6-7: %.*u\n", UINT_MAX, UINT_MAX);
    printf("6-8: %.*u\n", 1, INT_MIN);
    printf("6-9: %.*u\n", 10, INT_MIN);
    printf("6-10: %.*u\n", 100, INT_MIN);
    //printf("6-11: %.*u\n", UINT_MAX, INT_MIN);

    // <7> .(*): * = minus number
    printf("8-0: %.*u\n", -1, 12345);
    printf("8-1: %.*u\n", -10, 12345);
    printf("8-2: %.*u\n", -100, 12345);
    //printf("8-3: %.*u\n", INT_MIN, 12345);
    printf("8-4: %.*u\n", -1, UINT_MAX);
    printf("8-5: %.*u\n", -10, UINT_MAX);
    printf("8-6: %.*u\n", -100, UINT_MAX);
    //printf("8-7: %.*u\n", INT_MIN, UINT_MAX);
    printf("8-8: %.*u\n", -1, INT_MIN);
    printf("8-9: %.*u\n", -10, INT_MIN);
    printf("8-10: %.*u\n", -100, INT_MIN);
    //printf("8-11: %.*u\n", INT_MIN, INT_MIN);
    printf("\n");
    return (0);
}