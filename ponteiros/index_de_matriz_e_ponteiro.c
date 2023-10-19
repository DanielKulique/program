#include <stdio.h>
#include <stdlib.h>

//indexa s como uma matriz

void puts(char *s)
{
    register int t;
    for (t=0; s[t]; ++t) putchar(s[t]);
}

//acessa s como um ponteiro

void putstr(char *s)
{
    while(*s) putchar(*s++);
}