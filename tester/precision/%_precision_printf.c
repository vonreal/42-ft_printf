#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%%------------------\n");
    // <1> .(null)
    printf("1-0: %.%\n");
    printf("1-1: %.%\n");
    printf("1-2: %.%\n");

    // <2> .(0)
    printf("2-0: %.0%\n");
    printf("2-1: %.0%\n");
    printf("2-2: %.0%\n");

    // <3> number: .(plus number)
    printf("3-0: %.1%\n");
    printf("3-1: %.10%\n");
    printf("3-2: %.100%\n");
    //printf("3-3: %.2147483647%\n");
    printf("3-4: %.1%\n");
    printf("3-5: %.10%\n");
    printf("3-6: %.100%\n");
    //printf("3-7: %.2147483647%\n");
    printf("3-8: %.1%\n");
    printf("3-9: %.10%\n");
    printf("3-10: %.100%\n");
    //printf("3-11: %.2147483647%\n");

    // <4> number: .(minus number) 
    // printf("4-0: %.-1%\n");
    // printf("4-1: %.-10%\n");
    // printf("4-2: %.-100%\n");
    // printf("4-3: %.-2147483647%\n");
    // printf("4-4: %.-1%\n");
    // printf("4-5: %.-10%\n");
    // printf("4-6: %.-100%\n");
    // printf("4-7: %.-2147483647%\n");
    // printf("4-8: %.-1%\n");
    // printf("4-9: %.-10%\n");
    // printf("4-10: %.-100%\n");
    // printf("4-11: %.-2147483647%\n");

    // <5> .(*): * = 0
    printf("5-0: %.*%\n", 0);
    //printf("5-1: %.*%\n", 0);
    //printf("5-2: %.*%\n", 0);

    // <6> .(*): * = plus number
    printf("6-0: %.*%\n", 1);
    printf("6-1: %.*%\n", 10);
    printf("6-2: %.*%\n", 100);
    //printf("6-3: %.*%\n");
    printf("6-4: %.*%\n", 1);
    printf("6-5: %.*%\n", 10);
    printf("6-6: %.*%\n", 100);
    //printf("6-7: %.*%\n");
    printf("6-8: %.*%\n", 1);
    printf("6-9: %.*%\n", 10);
    printf("6-10: %.*%\n", 100);
    //printf("6-11: %.*%\n");

    // <7> .(*): * = minus number
    printf("8-0: %.*%\n", -1);
    printf("8-1: %.*%\n", -10);
    printf("8-2: %.*%\n", -100);
    //printf("8-3: %.*%\n");
    printf("8-4: %.*%\n", -1);
    printf("8-5: %.*%\n", -10);
    printf("8-6: %.*%\n", -100);
    //printf("8-7: %.*%\n");
    printf("8-8: %.*%\n", -1);
    printf("8-9: %.*%\n", -10);
    printf("8-10: %.*%\n", -100);
    printf("\n");
    return (0);
}