#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f1(int *a)
{
    *a = 3;
}

void main()
{
    int a=2;
    f1(&a);
    printf("%d", a);
}