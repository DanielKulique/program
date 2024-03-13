//Escreva um programa que leia a idade e o primeiro nome de varias pessoas. Seu
//programa deve terminar quando uma idade negativa for digitada. Ao terminar, seu
//programa deve escrever o nome e a idade das pessoas mais jovens e mais velhas.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int idade = 0, i=0, j=0;
    int idadeMaior = 0, idadeMenor=0;
    char maisVelho[100], maisJovem[100];

    typedef struct{
        char nome[100];
        int idade;
    }Pessoa;

    Pessoa pessoa[100];
    while(1){
        idade = 0;
        char nome[100];
        printf("\nIdade negativa interrompe o programa:");
        printf("\nDigite a idade da %d pessoa: ", i+1);
        scanf(" %d", &idade);
        if (idade <0)
            break; 
        pessoa[i].idade = idade;
        printf("\nDigite o nome da %d pessoa: ", i+1);
        getchar(); // Limpar o buffer do teclado
        nome[strcspn(nome, "\n")] = '\0'; // Remover o caractere de nova linha se estiver presente
        scanf("%s[^\n]", nome);
        strcpy(pessoa[i].nome, nome);
        i++;
    }
    strcpy(maisVelho, pessoa[0].nome);
    strcpy(maisJovem, pessoa[0].nome);
    idadeMaior = pessoa[0].idade;
    idadeMenor = pessoa[0].idade;

    for (j=0;j<i;j++){
        if (idadeMenor > pessoa[j].idade){
            idadeMenor = pessoa[j].idade;
            strcpy(maisJovem, pessoa[j].nome);
        }
        if (idadeMaior < pessoa[j].idade){
            idadeMaior = pessoa[j].idade;
            strcpy(maisVelho, pessoa[j].nome);
        }
    }
    printf("\n[%s] Mais novo", maisJovem);
    printf("\nCom [%d] Anos", idadeMenor);
    printf("\n[%s] Mais velho", maisVelho);
    printf("\nCom [%d] Anos", idadeMaior);
    
}