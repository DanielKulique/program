#include <stdio.h>
#include <stdlib.h>

/*int main(){
    
    FILE *entrada = fopen("entrada.txt", "w"); //abre 
    if(entrada == NULL){
        printf("\nERRO AO ABRIR ARQUIVO");
        return 0;
    }
    fprintf(entrada, "%s %c %d", "schaum", 's', 66); //escreve no arquivo
    fclose(entrada);
    

    FILE *entrada = fopen("entrada.txt", "r");//reading "r" leitura
    int x;
    char nome[15];
    char inicial;
    fscanf(entrada, "%s %c %d", nome, &inicial, &x); //le o arquivo
    printf("NOME: %s, INICIAL: %c IDADE: %d", nome, inicial, x);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100 // Tamanho máximo de uma linha no arquivo
#define MAX_FACTIONS 10 // Número máximo de facções
#define MAX_SIZE 100 // Tamanho máximo permitido para a matriz

// Estrutura para armazenar informações sobre as ações do jogo
typedef struct {
    char tipo[20]; // Tipo de ação (pos, move, coleta, constroi, etc.)
    char faccao[3]; // Identificador da facção (por exemplo, FA, FB)
    int x, y; // Coordenadas (posição, destino, etc.)
    int parametro1, parametro2; // Parâmetros adicionais, se necessário
} Acao;

// Função para imprimir a matriz do jogo
void imprimeMatriz(char matriz[MAX_SIZE][MAX_SIZE], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *arquivo;
    char linha[MAX_LINE_LENGTH];
    Acao acao;

    // Variáveis para armazenar o tamanho da matriz do jogo e o número de facções
    int linhas, colunas, num_faccoes;

    // Abre o arquivo para leitura
    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê o tamanho da matriz do jogo
    fgets(linha, sizeof(linha), arquivo);
    sscanf(linha, "%d %d", &linhas, &colunas);
    printf("Linhas: %d, Colunas: %d\n", linhas, colunas);

    // Verifica se o tamanho da matriz está dentro dos limites permitidos
    if (linhas > MAX_SIZE || colunas > MAX_SIZE) {
        printf("Erro: O tamanho da matriz excede o limite permitido.\n");
        fclose(arquivo);
        return 1;
    }


    // Lê o número de facções
    fgets(linha, sizeof(linha), arquivo);
    sscanf(linha, "%d", &num_faccoes);
    printf("Número de facções: %d\n", num_faccoes);

    // Declara uma matriz estática para armazenar o posicionamento das facções
    char matriz[MAX_SIZE][MAX_SIZE] = {0}; // Inicializa a matriz com zeros

    // Lê o posicionamento de cada facção e preenche a matriz
    for (int i = 0; i < num_faccoes; i++) {
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%s %d %d", acao.faccao, &acao.x, &acao.y);
        matriz[acao.x - 1][acao.y - 1] = acao.faccao[0]; // Armazena o identificador da facção na matriz
        printf("Facção: %s, Posição: (%d, %d)\n", acao.faccao, acao.x, acao.y);
    }

    printf("\naqui====================================================================");
    // Imprime o estado inicial da matriz
    imprimeMatriz(matriz, linhas, colunas);

    // Lê e processa cada linha do arquivo (ações do jogo)
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Divide a linha em partes usando espaço como delimitador
        char *token = strtok(linha, " ");
        if (token == NULL) continue; // Ignora linhas vazias

        // Copia o tipo de ação
        strcpy(acao.tipo, token);

        // Obtém e armazena as informações adicionais da linha
        sscanf(strtok(NULL, " "), "%s %d %d", acao.faccao, &acao.parametro1, &acao.parametro2);
        // Se o tipo de ação for 'pos', 'move', ou 'coleta', então os parâmetros 1 e 2 são as coordenadas
        if (strcmp(acao.tipo, "pos") == 0 || strcmp(acao.tipo, "move") == 0 || strcmp(acao.tipo, "coleta") == 0) {
            acao.x = acao.parametro1;
            acao.y = acao.parametro2;
        }

        // Agora você pode processar a ação conforme necessário
        // Por exemplo, imprimir as informações da ação
        printf("Tipo: %s, Facção: %s, Coordenadas: (%d, %d)\n", acao.tipo, acao.faccao, acao.x, acao.y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
