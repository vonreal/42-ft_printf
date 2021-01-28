#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%%x------------------\n");
    // <1> .(null)
    printf("1-0: %.x\n", 12345);
    printf("1-1: %.x\n", INT_MAX);
    printf("1-2: %.x\n", INT_MIN);

    // <2> .(0)
    printf("2-0: %.0x\n", 12345);
    printf("2-1: %.0x\n", INT_MAX);
    printf("2-2: %.0x\n", INT_MIN);

    // <3> number: .(plus number)
    printf("3-0: %.1x\n", 12345);
    printf("3-1: %.10x\n", 12345);
    printf("3-2: %.100x\n", 12345);
    //printf("3-3: %.2147483647x\n", 12345);
    printf("3-4: %.1x\n", INT_MAX);
    printf("3-5: %.10x\n", INT_MAX);
    printf("3-6: %.100x\n", INT_MAX);
    //printf("3-7: %.2147483647x\n", INT_MAX);
    printf("3-8: %.1x\n", INT_MIN);
    printf("3-9: %.10x\n", INT_MIN);
    printf("3-10: %.100x\n", INT_MIN);
    //printf("3-11: %.2147483647x\n", INT_MIN);

    // <4> number: .(minus number) 
    // printf("4-0: %.-1x\n", 12345);
    // printf("4-1: %.-10x\n", 12345);
    // printf("4-2: %.-100x\n", 12345);
    // printf("4-3: %.-2147483647x\n", 12345);
    // printf("4-4: %.-1x\n", INT_MAX);
    // printf("4-5: %.-10x\n", INT_MAX);
    // printf("4-6: %.-100x\n", INT_MAX);
    // printf("4-7: %.-2147483647x\n", INT_MAX);
    // printf("4-8: %.-1x\n", INT_MIN);
    // printf("4-9: %.-10x\n", INT_MIN);
    // printf("4-10: %.-100x\n", INT_MIN);
    // printf("4-11: %.-2147483647x\n", INT_MIN);

    // <5> .(*): * = 0
    printf("5-0: %.*x\n", 0, 12345);
    //printf("5-1: %.*x\n", 0, INT_MAX);
    //printf("5-2: %.*x\n", 0, INT_MIN);

    // <6> .(*): * = plus number
    printf("6-0: %.*x\n", 1, 12345);
    printf("6-1: %.*x\n", 10, 12345);
    printf("6-2: %.*x\n", 100, 12345);
    //printf("6-3: %.*x\n", INT_MAX, 12345);
    printf("6-4: %.*x\n", 1, INT_MAX);
    printf("6-5: %.*x\n", 10, INT_MAX);
    printf("6-6: %.*x\n", 100, INT_MAX);
    //printf("6-7: %.*x\n", INT_MAX, INT_MAX);
    printf("6-8: %.*x\n", 1, INT_MIN);
    printf("6-9: %.*x\n", 10, INT_MIN);
    printf("6-10: %.*x\n", 100, INT_MIN);
    //printf("6-11: %.*x\n", INT_MAX, INT_MIN);

    // <7> .(*): * = minus number
    printf("8-0: %.*x\n", -1, 12345);
    printf("8-1: %.*x\n", -10, 12345);
    printf("8-2: %.*x\n", -100, 12345);
    //printf("8-3: %.*x\n", INT_MIN, 12345);
    printf("8-4: %.*x\n", -1, INT_MAX);
    printf("8-5: %.*x\n", -10, INT_MAX);
    printf("8-6: %.*x\n", -100, INT_MAX);
    //printf("8-7: %.*x\n", INT_MIN, INT_MAX);
    printf("8-8: %.*x\n", -1, INT_MIN);
    printf("8-9: %.*x\n", -10, INT_MIN);
    printf("8-10: %.*x\n", -100, INT_MIN);
    //printf("8-11: %.*x\n", INT_MIN, INT_MIN);
    printf("\n");
    return (0);
}