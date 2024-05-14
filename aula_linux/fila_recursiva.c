#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    //outros campos
    struct no *prox;
}TNo;

TNo *alocaNo(int k);
void insereLista(TNo **p, int k);
void imprimir(TNo *paux);
void removeLista(TNo **p);
void removeTodos(TNo **p);
void insereFim(TNo **p, int k);
void removeFim(TNo **p);
void insereFimRec(TNo **no, int k);
void insereFimRec2(TNo *no, int k);

int main()
{
    TNo *prim=NULL, *prim2=NULL;
    imprimir(prim);
    insereLista(&prim,77);
    insereLista(&prim,36);
    insereLista(&prim,19);
    insereLista(&prim,2);
    insereLista(&prim,89);
    imprimir(prim);
    removeLista(&prim);
    printf("\n-----------------------");
    imprimir(prim);
    //removeTodos(&prim);
    //imprimir(prim);
    printf("\n-----------------------");
    insereFim(&prim2,11);
    insereFim(&prim2,22);
    insereFim(&prim2,33);
    insereFim(&prim2,44);
    insereFim(&prim2,55);
    imprimir(prim2);
    removeFim(&prim2);
    printf("\n-----------------------");
    imprimir(prim2);
    //removeFim para todos
    while(prim2)
    {
       removeFim(&prim2);
    }
    printf("\n-----------------------");
    imprimir(prim2);
    removeFim(&prim);
    printf("\n-----------------------");
    imprimir(prim);
    //insereLista(&prim2,200);
    //imprimir(prim2);
    insereFimRec(&prim, 33);
    imprimir(prim);
    insereFimRec2(prim, 99);
    imprimir(prim);
}

void insereFimRec2(TNo *no, int k){ // RECURSIVA
	
	if(no == NULL) //lista vazia
	{
		no = (TNo *)malloc(sizeof(TNo));
		if(no == NULL) return;
		(no)->chave = k;
		(no)->prox = NULL;
	}
	
	if((no->prox) == NULL)//chegou no ultimo
	{
		no->prox = (TNo *)malloc(sizeof(TNo));
		if(no->prox == NULL) return;
		(no)->chave = k;
		(no)->prox = NULL;
	}
	else{
		insereFimRec2(no->prox, k);
	}

}

void insereFimRec(TNo **no, int k){ //RECURSIVO
	//cria no base;
	if(*no == NULL)
	{
		//TNO novo = NULL;
		//novo = (TNO *)malloc(sizeof(TNO))
		//*no = novo;
		*no = (TNo *)malloc(sizeof(TNo));
		if(*no == NULL) return;
		(*no)->chave=k;
		(*no)->prox=NULL;
	}
	else
	{
		insereFimRec(&(*no)->prox, k);
	}
}


void removeFim(TNo **p)
{
    TNo *aux=*p, *ant=*p;
    if(*p==NULL)
        printf("\nLista vazia!");
    else
    {
        if((*p)->prox==NULL)//s� 1 elemento
        {
            free(*p);
            *p=NULL;
        }
        else
            {
                while(aux->prox)
                {
                    ant=aux;
                    aux=aux->prox;
                }
                free(aux);
                ant->prox=NULL;
            }
    }
}

void insereFim(TNo **p, int k)
{
    TNo *aux=*p, *novo=NULL; //*p � a mesma coisa que prim
    if(*p==NULL)
    {
       novo=alocaNo(k);
       if(novo)
       {
         *p = novo;
       }
    }
    else
    {
        while(aux->prox) //(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        novo=alocaNo(k);
        if(novo)
            aux->prox = novo;
    }
}
void removeTodos(TNo **p)
{
    if(*p==NULL)
        printf("\nLista vazia!");
    else{
    while(*p)
    {
        removeLista(p);
    }
    }
}

//remove no inicio
void removeLista(TNo **p)
{
    TNo *paux=*p;
    if(*p)
    {
        *p = (*p)->prox;
        free(paux);
        paux=NULL;
    }
    else
        printf("\nLista Vazia!");
}

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
//insere no in�cio
void insereLista(TNo **p, int k)
{
   TNo *novo=NULL;
   novo = alocaNo(k);
   if(novo)
   {
       //liga��es dos ponteiros da lista
       novo->prox = *p;
       *p = novo;
   }
}

TNo *alocaNo(int k)
{
    TNo *novo=NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if(novo) //novo!=NULL
    {
        novo->chave=k;
        novo->prox = NULL;
    }
    return novo;
}
