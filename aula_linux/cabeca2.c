#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}TNo;

typedef struct cabeca{
    int qtde;
    TNo *prox, *ult;
}TCabeca;

TCabeca *criaLista();
TNo *alocaNo(int k);
void insereInicio(TCabeca *p, int k);
void imprimir(TNo *paux);
void removeInicio(TCabeca *p);

int main()
{
    TCabeca *lista=criaLista();
    insereInicio(lista, 11);
    insereInicio(lista, 37);
    insereInicio(lista, 16);
    insereInicio(lista, 81);
    imprimir(lista->prox);
}

//lista simples
void imprimir(TNo *paux)
{
    if(paux==NULL)
        printf("\nLista vazia!");
    else
    {
        while(paux)
        {
            printf("\n%d", paux->chave);
            paux=paux->prox;
        }
    }
}
TNo *alocaNo(int k)
{
    TNo *novo=NULL;
    novo=(TNo *)malloc(sizeof(TNo));
    if(novo)
    {
        novo->chave=k;
        novo->prox=NULL;
    }
    return novo;
}

void insereInicio(TCabeca *p, int k)
{
    TNo *novo=NULL;
    novo=alocaNo(k);
    if(novo)
    {
        novo->prox=p->prox;
        if(p->prox==NULL)
            p->ult=novo;
        p->prox=novo;
        p->qtde++;
    }
}

TCabeca *criaLista()
{
    TCabeca *novo=NULL;
    novo=(TCabeca *)malloc(sizeof(TCabeca));
    if(novo)
    {
        novo->qtde=0;
        novo->prox=NULL;
        novo->ult=NULL;
    }
    return novo;
}

