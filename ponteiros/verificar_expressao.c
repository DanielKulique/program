#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No *desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha Vazia\n");
    return remover;
}

void imprimir(No *pilha) {
    printf("\n\tPilha\n");
    while(pilha){
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }
    printf("\tFim Pilha\n\n");
}

int forma_par(char f, char d){
    switch(f){
        case ')':
            if(d == '(')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
        case ']':
            if(d == '[')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
        case '}':
            if(d == '{')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
    }
}

int identifica_formacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;

    //percorre a string (expressao digitada) até o fim
    while(x[i] != "\0"){
        //se for um caracter de abertura, empilha
        if(x[i] == "[" || x[i] == "(" || x[i] == "{"){
            pilha = enpilhar(pilha, x[i]);
            imprimir(pilha);
        }
        // se for um caracter de fechamento, desempilha e verifica se forma par
        else if(x[i] == "]" || x[i] == ")" || x[i] == "}"){
            remover = desempilhar(&pilha);
            //se nao formar um par, entao a expressao esta mal formada
            if (formar_par(x[i], remover->caracter) == 0) {
                printf("\nEXPRESSAO MAL FORMADA!\n");
                return 1; // expressao esta mal formada
            }
            free(remover);
        }
        i++;
    }
    imprimir(pilha);
    // ao final, se a pilha nao estiver vazia significa que a expressao esta mal formada
    if(pilha){
        printf("\tExpressao mal formada!\n");
        return 1;
    }
    else{
        printf("\tExpressao bem formada!\n");
        return 0;
    }
}

int main() {
    char exp[50];

    printf("\nDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, indentidica_formacao(exp));
}



