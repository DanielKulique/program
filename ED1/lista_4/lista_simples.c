#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *proximo;
}NO;

NO *aloca(int k);
void liberarLista(NO **fila);
void adiciona_inicio(NO **fila, int elemento); // adiciona um elemento no inicio da fila
void adicionar_final(NO **fila, int elemento); // adiciona um elemento no fim da fila
void imprimir_fila(NO *fila);
NO *pesquisar(NO **fila, int elemento);
int valor_maximo(NO **fila);
int valor_minimo(NO **fila);
int soma_elementos(NO **fila);
int quantidade(NO **fila);               // quantidade de elementos na lista
int repeticoes(NO **fila, int elemento); // quantidade que um elemento especifico se repete;
void removerElemento(NO **fila, int elemento);
NO *copiarLista(NO **fila);
void inverterLista(NO **fila);
int compararLista(NO **lista_1, NO **lista_2);
NO *juntarLista(NO **lista_1, NO **lista_2);

int main()
{
    NO *ponteiro = NULL, *ponteiro2 = NULL; // aponta para uma fila de nos;
    int sim = 1, elem;

    printf("\n\t\tADICIONAR INICIO\n");
    adiciona_inicio(&ponteiro, 10);
    adiciona_inicio(&ponteiro, 34);
    adiciona_inicio(&ponteiro, 23);
    adiciona_inicio(&ponteiro, 63);
    imprimir_fila(ponteiro);
    printf("\n\t\tADICIONAR FINAL:\n");
    adicionar_final(&ponteiro, 23);
    adicionar_final(&ponteiro, 34);
    adicionar_final(&ponteiro, 45);
    adicionar_final(&ponteiro, 53);
    adicionar_final(&ponteiro, 62);
    imprimir_fila(ponteiro);
    // free(ponteiro);
    // ponteiro=NULL;

    /*
    do{
        printf("\nDigite o elemento a ser encontrado: ");
        scanf("%d", &elem);
        setbuf(stdin, NULL);
        printf("\nENDERECO %p :", (pesquisar(&ponteiro, elem)));
        printf("\nContinuar? [S-1] [N-0]: ");
        scanf("%d", &sim);
        setbuf(stdin, NULL);
    }while(sim);
    */

    printf("\nVALOR MAXIMO DA LISTA: %d", valor_maximo(&ponteiro));
    printf("\nVALOR MINIMO DA LISTA: %d", valor_minimo(&ponteiro));
    printf("\nSOMA DA LISTA: %d", soma_elementos(&ponteiro));
    printf("\nQUANTIDADE DE ELEMENTOS: %d", quantidade(&ponteiro));
    printf("\nQUANTAS VEZES O ELEMENTO %d SE REPETE: %d", 23, repeticoes(&ponteiro, 23));
    removerElemento(&ponteiro, 10);
    printf("\n APOS REMOVER: \n");
    imprimir_fila(ponteiro);
    printf("\n\tPONTEIRO 2\n"); 
    ponteiro2 = copiarLista(&ponteiro);
    imprimir_fila(ponteiro2);
    printf("\n\tINVERTER FILA\n");
    inverterLista(&ponteiro);
    imprimir_fila(ponteiro);
    printf("\n EH IGUAL: %d", (compararLista(&ponteiro2, &ponteiro)));
    printf("\nJuntar Lista");
    juntarLista(&ponteiro2, &ponteiro2);
    return 0;
}

NO *aloca(int k)
{
    NO *novo;
    novo = (NO *)malloc(sizeof(NO));
    if (novo)
    {
        novo->chave = k;
        novo->proximo = NULL;
    }
    return novo;
}

void adiciona_inicio(NO **fila, int elemento)
{
    NO *novo;
    novo = aloca(elemento);

    if (novo) // se alocado;
    {
        novo->proximo = *fila;
        *fila = novo;
    }
}

void adicionar_final(NO **fila, int elemento)
{
    NO *novo, *aux;
    aux = *fila;

    novo = aloca(elemento);

    if (novo)
    {
        if (aux == NULL)
            aux = novo;
        else
        {
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
}

void imprimir_fila(NO *fila)
{
    if (fila == NULL)
    {
        printf("\n\tFILA VAZIA");
    }
    else
    {
        while (fila)
        {
            printf("%d\n", fila->chave);
            fila = fila->proximo;
        }
    }
}

NO *pesquisar(NO **fila, int elemento)
{
    NO *aux;
    aux = *fila;
    if (aux == NULL)
    {
        printf("\n\tFILA VAZIA");
        return NULL;
    }
    else
    {
        while (aux)
        {
            if (aux->chave == elemento)
            {
                printf("\nElemento encontrado!");
                return aux;
            }
            aux = aux->proximo;
        }
        printf("\nelemento nao encontrado");
        return NULL;
    }
    return NULL;
}

int valor_maximo(NO **fila)
{
    NO *aux;
    aux = *fila;
    int maximo;

    if (aux == NULL)
    {
        printf("\nFILA VAZIA!");
        return 0;
    }
    else
    {
        maximo = aux->chave;
        while (aux->proximo)
        {
            if (aux->chave >= maximo)
                maximo = aux->chave;
            aux = aux->proximo;
        }
        return maximo;
    }
}

int valor_minimo(NO **fila)
{
    NO *aux;
    aux = *fila;
    int minimo;
    if (aux == NULL)
    {
        printf("\nFILA VAZIA");
        return 0;
    }
    else
    {
        minimo = aux->chave;
        while (aux)
        {
            if (aux->chave <= minimo)
                minimo = aux->chave;
            aux = aux->proximo;
        }
        return minimo;
    }
}

int soma_elementos(NO **fila)
{
    NO *aux;
    aux = *fila;
    int soma = 0;
    if (aux == NULL)
    {
        printf("\nFILA VAZIA");
        return 0;
    }
    else
    {
        while (aux)
        {
            soma += aux->chave;
            aux = aux->proximo;
        }
        return soma;
    }
}

int quantidade(NO **fila)
{
    NO *aux;
    aux = *fila;
    int quantidade = 0;
    if (aux == NULL)
    {
        printf("\nFILA VAZIA");
        return 0;
    }
    else
    {
        while (aux)
        {
            quantidade++;
            aux = aux->proximo;
        }
        return quantidade;
    }
}

int repeticoes(NO **fila, int elemento)
{
    NO *aux;
    aux = *fila;
    int rep = 0;
    if (aux == NULL)
    {
        printf("\nFILA VAZIA");
        return 0;
    }
    else
    {
        while (aux)
        {
            if (aux->chave == elemento)
                rep++;
            aux = aux->proximo;
        }
        return rep;
    }
}
void removerElemento(NO **fila, int elemento)
{
    NO *atual, *anterior;
    atual = *fila;
    if (atual == NULL)
    {
        printf("\nFILA VAZIA");
        return;
    }
    if (atual->chave == elemento) //se for o primeiro da lista;
    {
        *fila = atual->proximo;
        free(atual);
        return;
    }
    anterior = atual;
    while (atual != NULL && atual->chave != elemento)
    {      
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\nELEMENTO NAO ENCONTRADO NA LISTA!");
        return;
    }
    anterior->proximo = atual->proximo;
    free(atual);
}

NO *copiarLista(NO **fila){
    NO *nova_lista=NULL, *aux=NULL;
    aux = *fila;

    if(aux==NULL){
        printf("\nFILA VAZIA");
        return NULL;
    }
    while(aux!=NULL){
        NO *novo_no = aloca(aux->chave);
        if(novo_no == NULL)
        {
            printf("\nErro ao alocar memoria: ");
            free(nova_lista); //libera memoria alocada até o memomento
            return NULL;
        }
        if(nova_lista==NULL){
            nova_lista = novo_no;
        }
        else
        {
            NO *ultimo = nova_lista;
            while(ultimo->proximo!=NULL){
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo_no;
        }
        aux=aux->proximo;
    }
    return nova_lista;

}
void inverterLista(NO **fila){
    NO *aux;
    NO *lista_invertida=NULL;
    aux = *fila;


    if(aux == NULL){
        printf("\nFILA VAZIA");
        return;
    }
    while(aux!=NULL){
        NO *novo_no = aloca(aux->chave);
        if(novo_no == NULL){
            printf("\nErro ao alocar memoria");
            liberarLista(&lista_invertida);
            lista_invertida=NULL;
            return;
        }
        novo_no->proximo = lista_invertida; //adicionar no inicio, conecta o inicio da fila com o novo no
        lista_invertida = novo_no; //agora inicio olha para a novo no
        aux = aux->proximo;//proximo no 
    }
    liberarLista(&(*fila));
    *fila = lista_invertida;
}
void liberarLista(NO **fila){
    NO *atual = *fila;
    while(atual!= NULL){
        NO *proximo = atual->proximo; //guarda referencia do proximo no
        free(atual); //libera o atual
        atual = proximo;
    }
}

int compararLista(NO **lista_1, NO **lista_2){
    NO *aux_1, *aux_2;

    aux_1 = *lista_1;
    aux_2 = *lista_2;

    if(aux_1 == NULL || aux_2 == NULL)
    {
        printf("\nUma das listas esta vazia");
        return 0;
    }
    if(quantidade(&aux_1) == quantidade(&aux_2))
    {
        while(aux_1 != NULL)
        {
            if(aux_1->chave != aux_2->chave){
                return 0;
            }
            aux_1 = aux_1->proximo;
            aux_2 = aux_2->proximo;
        }
        return 1;
    }
    else
        return 0;
}

NO *juntarLista(NO **lista_1, NO **lista_2){
    NO *aux_1 = *lista_1;
    NO *aux_2 = *lista_2;

    if(aux_1 == NULL || aux_2 == NULL){
        printf("\nLista Invalida/Vazia!");
        return NULL;
    }

    NO *nova_lista=NULL;
    NO *atual=NULL;

    while(aux_1!=NULL){
        NO *novo_no = aloca(aux_1->chave);
        if(novo_no)
        {
            if(nova_lista==NULL)
            {
                nova_lista = novo_no;
                atual = nova_lista;
            }
            else
            {
                atual->proximo = novo_no; 
                atual = atual->proximo;
            }
        aux_1 = aux_1->proximo;
        }
        else{
            printf("\nNo nao alocado");
            liberarLista(&aux_1);
            return NULL;
        }
    }
    while(aux_2!=NULL){
        NO *novo_no = aloca(aux_2->chave);
        if(novo_no){
            if(nova_lista==NULL)
            {
                nova_lista = novo_no;
                atual = nova_lista;
            }
            else{
                atual->proximo = novo_no;
                atual = atual->proximo;
            }
            aux_2 = aux_2->proximo;
        }
        else{
            printf("\nNo nao alocado");
            liberarLista(&aux_2);
            return NULL;
        }
    }
    imprimir_fila(nova_lista);
    return nova_lista;

}