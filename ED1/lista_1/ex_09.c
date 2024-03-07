//Entre com um nome e imprima o nome somente se a primeira letra do nome for “a”
//(maiúscula ou minúscula)


#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[10];
    printf("\nDigite seu nome: ");
    scanf("%s", nome);
    if (nome[0] == 'a' || nome[0] == 'A')    
        printf("Nome: [%s]", nome);
}
