#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1 - Adicionar novo contato
2 - Exibir contatos
3 - Pesquisar contato
3 - Remover contato
4 - Apagar todos os registros
5 - Sair
6- DESALOCAR!
*/

typedef struct data{
    int dia;
    int mes;
}Data;

typedef struct contato{
    char nome[45];
    char telefone[12];
    struct data dataAniversario;
    struct contato *prox; // fazer varios nos // proximos contatos
}Contato;

typedef struct agenda{
    int qnt_contatos;
    Contato *contatos; // ponteiro que olha para estrutura contato(dentro dela ha a lista de varios contatos)
}Agenda;

Agenda *cria_agenda(){
    Agenda *nova_agenda = NULL;
    nova_agenda = (Agenda *)malloc(sizeof(Agenda));//primeiro no CABECA agenda
    if(nova_agenda){
        nova_agenda->qnt_contatos = 0;
        nova_agenda->contatos = NULL;
        return nova_agenda;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA NO CABECA");
        return NULL;
    }

}

Contato *cria_lista(){ //não é utilizado. nó cabeça de contatos, refatorar codigo.
    Contato *novo=NULL;
    novo = (Contato *)malloc(sizeof(Contato)); //primeiro no CABECA(root)
    if(novo){
        strcpy(novo->nome, "");
        strcpy(novo->telefone, "");
        novo->dataAniversario.dia = -1;
        novo->dataAniversario.mes = -1;
        novo->prox = NULL;
        return novo;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA NO CABECA");
        return NULL;
    }
}

Contato *alocaNO_contato(char *nome, char *telefone, int dia, int mes){
    Contato *novo = NULL;
    novo = (Contato *)malloc(sizeof(Contato)); // alocar cada no
    if(novo){
        strcpy(novo->nome, nome);
        strcpy(novo->telefone, telefone);
        novo->dataAniversario.dia = dia;
        novo->dataAniversario.mes = mes;
        novo->prox = NULL;
        return novo;
    }
    else{
        printf("\nERRO AO ALOCAR MEMORIA PARA O NO");
        return NULL;
    }
}

void insereInicio_contato(Agenda *agenda, char *nome, char *telefone, int dia, int mes){
    Contato *novo_contato = NULL;
    novo_contato = alocaNO_contato(nome, telefone, dia, mes);
    if(novo_contato){
        novo_contato->prox = agenda->contatos; // ponteiro proximo aponta para inicio da agenda
        agenda->contatos = novo_contato; //comeco da lista contato aponta para novo contato
        agenda->qnt_contatos ++; // incrementa novo contato conforme forem adicionados na lista
    }
    else{
        printf("\nERRO AO INSERIR CONTATO");
        exit(1);
    }
}

void imprime_agenda(Agenda *agenda){
    Contato *atual = agenda->contatos;
    if(atual == NULL){
        printf("\n\tFILA VAZIA!");
        return;
    }
    else
    {
        printf("\n\t\t\tContatos da Agenda");
        while(atual){
            printf("\nNOME: %s", atual->nome);
            printf("\nTELEFONE: %s", atual->telefone);
            printf("\nDia de Aniversario %d", atual->dataAniversario.dia);
            printf("\nMes de Aniversario %d", atual->dataAniversario.mes);
            atual = atual->prox;
            printf("\n");
        }
        printf("\nTotal de Contatos da Agenda: %d", agenda->qnt_contatos);
    }
}

void pesquisar_contato(Agenda *agenda, char *nome){
    Contato *atual = agenda->contatos; //ponteiro auxiliar para nao modificar a lista encadeada original;

    if(atual==NULL){
        printf("\nAgenda Vazia!");
        return;
    }
    else{
        while(atual)
        {
            if(strcmp(atual->nome, nome) == 0)
            {
                printf("\nUSUARIO ENCONTRADO!");
                printf("\nNOME: %s", atual->nome);
                printf("\nTELEFONE: %s", atual->telefone);
                printf("\nNasceu dia %d, do mes %d", atual->dataAniversario.dia, atual->dataAniversario.mes);
                return;
            }
            atual = atual->prox;
        }
        printf("\nUSUARIO NAO ENCONTRADO");
    }
}

void remover_contato(Agenda *agenda, char *nome){
    Contato *anterior = NULL;
    Contato *atual = agenda->contatos;

    if(atual==NULL){
        printf("\nAgenda Vazia!");
        return;
    }
    else
    {
        while(atual != NULL && strcmp(atual->nome, nome) != 0)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if(atual!=NULL){
            if(anterior == NULL){
                agenda->contatos = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            printf("\nContato [%s] removido!", nome);
            free(atual);
        }
        else{
            printf("\nContato [%s] nao encontrado!", nome);
        }
    }

}

void liberar_agenda(Agenda *agenda){
    Contato *atual = agenda->contatos;
    Contato *proximo;

    while (atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    agenda->contatos = NULL;
}


int main(){
    Agenda *aged_01 = NULL;
    aged_01 = cria_agenda();
    int opcao=0, dia, mes;
    char nome[45], telefone[12];

    printf("\n\t\t\tMENU");

    do{
        printf("\n\t===================================\n");
        printf("\n\tAPERTE \n\t1-EXIBIR CONTATOS \n\t2-ADICIONAR NOVO CONTATO \n\t3-PESQUISAR CONTATO \n\t4-REMOVER CONTATO \n\t5-APAGAR TODOS OS REGISTROS \n\t6-SAIR");
        printf("\n\t===================================\n");
        do{
            printf("\nDigite a opcao: ");
            scanf("%d", &opcao);
            setbuf(stdin, NULL);
            if(opcao < 1 || opcao > 6)
                printf("\nOpcao invalida, tente um valor entre 1 a 6!");
        }while(opcao < 1 || opcao > 6);

        switch (opcao)
        {
        case 1:
            printf("\n\tEXIBINDO CONTATOS");
            imprime_agenda(aged_01);
            break;
        case 2:
            printf("\n\tADICIONE UM NOVO CONTATO");

            printf("\nNOME: ");
            fgets(nome, 45, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nTELEFONE: ");
            fgets(telefone, 12, stdin);
            telefone[strcspn(telefone, "\n")] = '\0';

            printf("\nDia Nascimento:");
            scanf("\n%d", &dia);
            setbuf(stdin, NULL);
            printf("\nMes Nascimento:");
            scanf("\n%d", &mes);
            setbuf(stdin, NULL);
            insereInicio_contato(aged_01, nome, telefone, dia, mes);
            break;
        case 3:
            printf("\nPESQUISANDO CONTATO");
            printf("\nDIGITE O NOME DO CONTATO: ");
            fgets(nome, 45, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            pesquisar_contato(aged_01, nome);
            break;
        case 4:
            printf("\nREMOVENDO CONTATO");
            printf("\nDIGITE O NOME DO CONTATO: ");
            fgets(nome, 45, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            remover_contato(aged_01, nome);
            break;
        case 5:
            printf("\nAPAGANDO TODOS OS CONTATOS!");
            liberar_agenda(aged_01); //liberando memoria
        default:
            break;
        }
    }while(opcao!=6);
    printf("\n\t===================================\n");
    liberar_agenda(aged_01);// liberando ao fim a memoria, independente do usuario;
    return 0;
}
/*
1 - Adicionar novo contato
2 - Exibir contatos
3 - Pesquisar contato
3 - Remover contato
4 - Apagar todos os registros
5 - Sair
6- DESALOCAR!
*/
