#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{ //enderecos
    char endereco_ip[16];
    char dominio[50];
    struct no *proximo;
}NO;

NO* criar_lista(){
    NO *novo=NULL;
    novo = (NO*)malloc(sizeof(NO));//NO CABECA
    if(novo){
        strcpy(novo->endereco_ip, "");
        strcpy(novo->dominio, "");
        novo->proximo = NULL;
        return novo;
    }
    return NULL;
}

NO *alocaNO(char *ip, char *dom){
    NO *novo = NULL;
    novo = (NO*)malloc(sizeof(NO));//aloca cada no
    if(novo){
        strcpy(novo->endereco_ip, ip);
        strcpy(novo->dominio, dom);
        novo->proximo = NULL;
        return novo;
    }
    else
        return NULL;
}

void insereInicio(NO *p, char *ip, char *dom){
    NO *novo = NULL;
    novo = alocaNO(ip, dom);
    if(novo){
        novo->proximo = p->proximo;
        p->proximo = novo;
    }
}

void imprime(NO *paux){
    if(paux==NULL){
        printf("\nLista Vazia");
    }
    else
    {
        while(paux){
            printf("\nDOMINIO: %s", paux->dominio);
            printf("\nIP: %s", paux->endereco_ip);
            paux = paux->proximo;
            printf("\n");
        }
    }
}

void buscar_dominio(NO *p_dns, char *ip){ //arrumar com auxiliar
    if(p_dns == NULL)
    {
        printf("\nLista Vazia!");
        return;
    }
    else
    {
        while(p_dns != NULL)
        {
            if(strcmp(ip, p_dns->endereco_ip) == 0)
            {
                printf("\nDOMINIO ENCONTRADO!");
                printf("\nIP REQUISITADO: %s", p_dns->endereco_ip);
                printf("\nDOMINIO RELACIONADO: %s", p_dns->dominio);
                return;
            }
            p_dns = p_dns->proximo;
        }
        printf("\nDOMINIO NAO ENCONTRADO!");
    }
}

int main(){
    NO *DNS;
    DNS = criar_lista();
    int continuar = 1;
    char ip[16];
    
    insereInicio(DNS, "192.168.0.1", "www.facebook.com");
    insereInicio(DNS, "172.217.28.206", "www.google.com");
    insereInicio(DNS, "104.18.34.177", "www.reddit.com");
    insereInicio(DNS, "104.16.25.235", "www.cloudflare.com");
    insereInicio(DNS, "198.252.206.16", "www.stackexchange.com");
    //buscar_dominio(DNS, "123213");

    do{
        printf("\nDigite o endereço IP:");
        fgets(ip, 16, stdin);
        setbuf(stdin, NULL);
        ip[strcspn(ip, "\n")] = '\0';
        buscar_dominio(DNS, ip);
        printf("\n[1]-VERIFICAR NOVAMENTE \n[0]-SAIR \n");
        scanf("%d", &continuar);
        setbuf(stdin, NULL);
    }while(continuar);
    //imprime(DNS->proximo);

    return 0;
}