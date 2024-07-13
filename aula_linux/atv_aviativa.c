#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct cliente{
	int codigo;
	struct cliente *prox;
}Cliente;

typedef struct mesa{
	int numero_mesa, codigo_cliente;
	struct mesa *prox;
}Mesa;

typedef struct c_cliente{
	Cliente *inicio;
	Cliente *fim;
	int tamanho_fila; //numero cliente
	int tamanho_fila2; //tamanho real da fila atualizado
}Cabeca_cliente;

typedef struct c_mesa{
	Mesa *inicio;
	Mesa *fim;
	int mesas_ocupadas;
}Cabeca_mesa;


Cabeca_cliente *Cria_Lista_Cliente(){
	Cabeca_cliente *nova_cabeca = (Cabeca_cliente *)malloc(sizeof(Cabeca_cliente));
	if(nova_cabeca){
		nova_cabeca->inicio = NULL;
		nova_cabeca->fim = NULL;
		nova_cabeca->tamanho_fila=0;
		nova_cabeca->tamanho_fila2=0;
		return nova_cabeca;
	}
	else{
		printf("Erro ao alocar memoria para cabeca cliente!");
		return NULL;
	}
}
Cabeca_mesa *Cria_Lista_mesa(){
	Cabeca_mesa *nova_cabeca = (Cabeca_mesa *)malloc(sizeof(Cabeca_mesa));
	if(nova_cabeca){
		nova_cabeca->inicio = NULL;
		nova_cabeca->fim = NULL;
		nova_cabeca->mesas_ocupadas = 0;
		return nova_cabeca;
	}
	else{
		printf("Erro ao alocar memoria para cabeca mesa!");
		return NULL;
	}
}

Mesa *aloca_no_mesa(int num){
	Mesa *nova_mesa = (Mesa *)malloc(sizeof(Mesa));
	if(nova_mesa){
		nova_mesa->numero_mesa = num;
		nova_mesa->codigo_cliente = 0; // 0 = nao tem cliente
		nova_mesa->prox = NULL;
		return nova_mesa;
	}
	else{
		printf("\nNo mesa nao alocado");
		return NULL;
	}
}

void inserir_mesa(Cabeca_mesa *lista_mesa, int num){ //fim
	int i=0;
	for(i=0; i<num;i++){
		Mesa *nova_mesa = aloca_no_mesa(i); 
		if(nova_mesa){
			if(lista_mesa->inicio==NULL){
				lista_mesa->inicio = nova_mesa;
				lista_mesa->fim = nova_mesa;
			}
			else{
				lista_mesa->fim->prox = nova_mesa;
				lista_mesa->fim = nova_mesa;
			}
		}
		else
			printf("\nErro ao inserir_mesa");
	}
}


Cliente *aloca_no_cliente(int codigo){
	Cliente *novo_cliente = (Cliente *)malloc(sizeof(Cliente));
	if(novo_cliente){
		novo_cliente->codigo = codigo;
		novo_cliente->prox = NULL;
		return novo_cliente;
	}
	else{
		printf("\nNo cliente nao alocado");
		return NULL;
	}
}

void inserir_cliente(Cabeca_cliente *lista_cliente, int codigo){ //fim
	Cliente *novo_cliente = aloca_no_cliente(codigo); 
	if(novo_cliente){
		if(lista_cliente->inicio==NULL){
			lista_cliente->inicio = novo_cliente;
			lista_cliente->fim = novo_cliente;
		}
		else{
			lista_cliente->fim->prox = novo_cliente;
			lista_cliente->fim = novo_cliente;
		}
		lista_cliente->tamanho_fila ++;
		lista_cliente->tamanho_fila2 ++;
	}
	else
		printf("\nErro ao inserir_mesa");
}

void imprimir_mesa(Cabeca_mesa *lista_mesa){
	Mesa *aux = lista_mesa->inicio;
	if(lista_mesa->inicio==NULL){
		printf("\nNao ha mesas");
	}
	else{
		while(aux->prox){
			printf("\nNumero da mesa [%d] - Cliente [%d]", aux->numero_mesa, aux->codigo_cliente);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void imprimir_lista_atendimento(Cabeca_cliente *lista_cliente){
	Cliente *aux = lista_cliente->inicio;
	if(lista_cliente->inicio==NULL){
		printf("\nNao ha clientes");
	}
	else{
		while(aux->prox){
			printf("\nCliente [%d]", aux->codigo);
			aux = aux->prox;
		}
		printf("\n");
	}
}

void Remove_cliente_fila(Cabeca_cliente *lista_cliente){ //remove no inicio
	if (lista_cliente->inicio == NULL){
		printf("\nLista de clientes vazia.\n");
		return;
	}
	Cliente *removido = lista_cliente->inicio;

	lista_cliente->inicio = lista_cliente->inicio->prox;

	free(removido);

	printf("\nCliente removido do inicio da fila");
}

void remove_cliente_meio_fila(Cabeca_cliente *lista_cliente, int codigo_cliente){ //remove meio
	Cliente *aux = lista_cliente->inicio;
	if(aux == NULL){
		printf("\nLista Vazia");
		return;
	}
	if(aux->codigo == codigo_cliente){//primeiro da lista
		lista_cliente->inicio = aux->prox;
		free(aux);
		printf("\nCliente retirado");
		return;
	}
	Cliente *anterior = NULL;
	while(aux != NULL && aux->codigo != codigo_cliente){
		anterior = aux;
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("\nNao foi encontrado o cliente");
		return;
	}
	if(anterior != NULL){
		anterior->prox = aux->prox;
		free(aux);
		printf("\nCliente retirado");
	}
}

void desaloca_lista(Cabeca_cliente *lista){
	Cliente *aux = lista->inicio;
	if(aux==NULL){
		printf("\nFila desalocada");
		return;
	}
	Cliente *prox = NULL;
	while(aux!=NULL){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	lista->inicio = NULL;
	printf("\nLista desalocada");
}

void desaloca_mesa(Cabeca_mesa *lista){
	Mesa *aux = lista->inicio;
	if(aux==NULL){
		printf("\nFila desalocada");
		return;
	}
	Mesa *prox = NULL;
	while(aux!=NULL){
		prox = aux->prox;
		free(aux);
		aux = prox;
	}
	lista->inicio = NULL;
	printf("\nLista desalocada");
}


int main(){
	int i = 0, op = 0;
	//criar mesa;
	Cabeca_mesa *lista_mesa = Cria_Lista_mesa();
	inserir_mesa(lista_mesa, 4);
	imprimir_mesa(lista_mesa);
	
	//criar lista_cliente;
	Cabeca_cliente *lista_cliente = Cria_Lista_Cliente();

	while(op!=4)
	{
		printf("\n1 - alocar cliente"); //fila - e verifica mesa
		printf("\n2 - Retirar cliente"); //mesa // fila
		printf("\n3 - Imprimir filas");
		printf("\n4 - Sair");
		printf("\n5 - Informe opcao");
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			{	
				printf("\nAdicionando cliente N - %d ", lista_cliente->tamanho_fila);
				inserir_cliente(lista_cliente, lista_cliente->tamanho_fila);
				lista_cliente->tamanho_fila2 =+ 1;
				if(lista_mesa->mesas_ocupadas<4){
					if(lista_mesa->inicio->codigo_cliente == 0)
						lista_mesa->inicio->codigo_cliente = lista_cliente->inicio->codigo;
					else{
						Mesa *aux = lista_mesa->inicio;
						while(aux->codigo_cliente != 0){
							aux = aux->prox;
						}
						aux->codigo_cliente = lista_cliente->inicio->codigo;
					}
					Remove_cliente_fila(lista_cliente);
					lista_mesa->mesas_ocupadas += 1;
					lista_cliente->tamanho_fila2 -= 1;
				}
			}break;
		case 2:
			{
				int acao=0;
				do{
					printf("\nRetirar cliente \n[1] - mesa \n[2] - fila \n-> ");
					scanf("%d", &acao);
				}while(acao != 1 && acao != 2);
				if(acao==1){
					printf("\nRemovendo mesa");
					int menor = INT_MAX;
					Mesa *casa_menor = NULL;

					//encontra a mesa com o menor codigo de cliente
					Mesa *aux = lista_mesa->inicio;
					while(aux != NULL){
						if(aux->codigo_cliente != 0 && aux->codigo_cliente<menor){
							menor = aux->codigo_cliente;
							casa_menor = aux;
						}
						aux = aux->prox;
					}
					if(casa_menor != NULL){
						printf("\nRemovendo cliente da mesa: %d", casa_menor->codigo_cliente);
						casa_menor->codigo_cliente = 0;
						lista_mesa->mesas_ocupadas -= 1;
					}
					else{
						printf("\nNenhuma mesa com cliente encontrada.\n");
					}
				}
				else{
					int numero_cliente;
					//retira cliente da fila
					printf("\nRemovendo cliente da fila");
					printf("\nDigite o codigo do cliente\n-> ");
					scanf("%d", &numero_cliente);
					remove_cliente_meio_fila(lista_cliente, numero_cliente);
				}
			}break;
		case 3:
			{
				printf("\nImprimindo fila de espera: ");
				imprimir_lista_atendimento(lista_cliente);
				printf("\nImprimindo fila de mesa");
				imprimir_mesa(lista_mesa);
			}break;
		case 4:
			{	
				printf("\nSaindo");
				op = 4;
				desaloca_mesa(lista_mesa);
				desaloca_lista(lista_cliente);
			}break;
		}
	}
}