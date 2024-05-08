#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char cpf[12];
    char nomeCompleto[25];
    char telefone[15];
    char email[25];
    double salario;
    struct funcionario *proximo;
} Funcionario;

typedef struct departamento{
    char setor[50];
    int qtd_funcionarios;
    Funcionario *inicio; //"CABEÇA"
} Departamento;

void criar_Lista(Departamento *lista){
    lista->inicio = NULL;
    lista->qtd_funcionarios = 0;
}

void Inserir_Funcionario(Departamento *depto){
    Funcionario *novo = malloc(sizeof(Funcionario));

    if(novo){
        printf("\nCPF: ");
        fgets(novo->cpf, 12, stdin);
        setbuf(stdin, NULL);
        printf("\nNOME COMPLETO: ");
        fgets(novo->nomeCompleto, 25, stdin);
        setbuf(stdin, NULL);
        printf("\nTELEFONE: ");
        fgets(novo->telefone, 15, stdin);
        setbuf(stdin, NULL);
        printf("\nEMAIL: ");
        fgets(novo->email, 12, stdin);
        setbuf(stdin, NULL);
        printf("\nSALARIO:");
        scanf("%lf", &novo->salario); 
        setbuf(stdin, NULL);
        novo->proximo = depto->inicio;
        depto->inicio = novo;
        depto->qtd_funcionarios ++;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA\n");
    }
}


int main() {
    Departamento Dep_01;
    strcpy(Dep_01.setor, "RH");

    Inserir_Funcionario(&Dep_01);
    Inserir_Funcionario(&Dep_01);



    // Exemplo de acesso aos funcionários da lista
    Funcionario *atual = Dep_01.inicio;
    while (atual != NULL) {
        printf("CPF: %s Nome: %s Salario: %2.f\n", atual->cpf, atual->nomeCompleto, atual->salario);
        atual = atual->proximo;
    }

    return 0;
}