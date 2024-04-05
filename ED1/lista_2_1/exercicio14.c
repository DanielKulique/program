#include<stdio.h>
#include <alloc.h>
int main ()
{
int y, x=3, k=5, *p,*q;
p = &x;
q = (int *)malloc(6 * sizeof(int));
for(y = 0; y< 3; y++)
{
p--; // aponta para uma regiao na memoria do SO
scanf(“%d”, p); // ler uma regiao na memoria do SO
p++; // volta a apontar para o endereço de x 
scanf(“%d”, p); printa endereço de p;
*q = k; //endereço de q[0] recebe o conteudo k(5)
*(q+1) = x; //q[1] recebe o conteudo de x(5)
q = q + 2; //endereço de q recebe endereço de q + 2 posiçoes na memoria;
}
}
