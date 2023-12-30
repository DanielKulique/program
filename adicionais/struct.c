#include <stdio.h>
#include <string.h>


//definir uma struct Pessoa

struct Pessoa{
    char nome[50];
    int idade;
    float altura;
};

int main(){
    //declarando uma variavel do tipo Pessoa
    struct Pessoa pessoa1;

    //atribuindo valores aos campos da struct
    strcpy(pessoa1.nome, "Joao");
    pessoa1.idade = 23;
    pessoa1.altura = 1.75;

    //acessando e exibindo os valores

    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    return 0;

}