#include <stdio.h>

int main()
{
    int x;
    int *p;

    //apontar p (ponteiro para inteiro) para um float

    p = &x;
    printf("%p", p);
}