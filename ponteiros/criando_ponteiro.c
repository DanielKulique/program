#include <Stdio.h>
#include <stdlib.h>

int main(){
    int num = 10;

    int *p; //ponteiro p do tipo inteiro
    
    p = &num; //p recebe endereço de num

    printf("Valor de num %d\n", num);
    printf("Endereco de num: %p\n", &num); // retorna endereço de num

    printf("valor de p: %p\n", p);
    printf("endereco de p: %p\n", &p); // retorna endereço de p != endereço de num
    printf("valor apontado por p: %d\n", *p); // retorna 10

    return 0;
}