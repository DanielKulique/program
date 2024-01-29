#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idade;
    char sexo;
    char nome[100];
}Pessoa;

int main(){
    Pessoa pessoa1;

    printf("Digite seu nome: ");
    fgets(pessoa1.nome, 100, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &pessoa1.idade);
    scanf("%c");
    printf("Digite f ou m para o sexo: ");
    scanf("%c", &pessoa1.sexo);

    printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoa1.nome, pessoa1.idade, pessoa1.sexo);

    return 0;
}