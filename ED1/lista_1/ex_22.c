//2.Ler o nome e o valor de uma determinada mercadoria de uma loja. Sabendo que o
//desconto para pagamento à vista é de 10% sobre o valor total, calcular o valor a ser
//pago à vista. Escrever o nome da mercadoria, o valor total, o valor do desconto e o valor
//a ser pago à vista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Produto[100];
    int valor;
    int pagamento;
} Loja;


int main(){
    int i=0, quantidade=0;
    float preco_desconto=0;


    printf("\nQuantos produtos?: ");
    scanf("%d", &quantidade);
    getchar();
    Loja mercadoria[quantidade];

    for (i=0; i<quantidade; i++)
    {
        printf("\n\tPRODUTO %d", i+1);
        printf("\nDigite o nome do produto: ");
        fgets(mercadoria[i].Produto, sizeof(mercadoria[i].Produto), stdin);
        printf("\nDigite o valor do produto: ");
        scanf("%d", &mercadoria[i].valor);
        getchar();
        printf("\nPagamento a vista? \n[1]-sim [0]-não: ");
        scanf("%d", &mercadoria[i].pagamento);
        getchar();     
    }

    for (i=0; i<quantidade; i++)
    {
        printf("\nMercadoria %d", i+1);
        printf("\n%s", mercadoria[i].Produto);
        printf("\nValor Total: ");
        printf("%d", mercadoria[i].valor);
        if(mercadoria[i].pagamento == 1)
        {
            preco_desconto = mercadoria[i].valor - (float)(mercadoria[i].valor*0.1);
            printf("\nDesconto de %.2f Reais", (float)mercadoria[i].valor*0.1);
            printf("\nPreco a vista: %.2f Reais", preco_desconto);
        }
        else
            printf("\nPagamento parcelado, sem desconto.");
    }
    return 0;
}