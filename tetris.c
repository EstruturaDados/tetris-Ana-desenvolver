
// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.

#include <stdio.h>  // funções de entrada/saída (printf, scanf)
#include <stdlib.h> // funções gerais (rand, srand)
#include <time.h>   // para usar time() e gerar números aleatórios diferentes a cada execução

#define TAM 5   // tamanho fixo da fila circular

// STRUCT QUE REPRESENTA UMA PEÇA DO TETRIS
// Cada peça tem um nome (tipo) e um ID único

typedef struct {
    char nome;  // 'I', 'O', 'T', 'L'
    int id;     // identificador único
} Peca;

// VARIÁVEIS DA FILA CIRCULAR
Peca fila[TAM];   // vetor que armazena as 5 peças da fila
int inicio = 0;   // posição da próxima peça a ser removida (dequeue)
int fim = 0;      // posição onde a próxima peça será inserida (enqueue)
int quantidade = 0;  // quantidade atual de peças na fila
int proximoID = 0;   // contador para gerar ID único para cada peça

// FUNÇÃO PARA GERAR UMA PEÇA NOVA
// Retorna uma peça com tipo aleatório e ID único

Peca gerarPeca(){
    char tipos[] = {'I', 'O', 'T', 'L'};  // tipos possíveis das peças

    Peca p;
    p.nome = tipos[rand() % 4];  // escolhe um tipo aleatório
    p.id = proximoID++;          // ID único e sequencial

    return p;  // devolve a peça criada
}

// ENQUEUE – INSERIR PEÇA
void enqueue() {
    if (quantidade == TAM) {
        printf("Fila cheia! Não é possível inserir.\n");
        return;
    }
// Insere a peça nova no índice 'fim'
    fila[fim] = gerarPeca();

// Avança o índice de forma circular
    fim = (fim + 1) % TAM;

// Aumenta a quantidade de elementos   
    quantidade++;

    printf("Peça inserida com sucesso!\n");
}

// DEQUEUE – REMOVER PEÇA
   void dequeue() {
    if (quantidade == 0) {
        printf("Fila vazia! Nada a remover.\n");
        return;
    }

// Guarda a peça que será removida
    Peca removida = fila[inicio];

// Move o início para próxima posição   
    inicio = (inicio + 1) % TAM;

// Diminui a quantidade
    quantidade--;

// exibe qual peça foi jogada
    printf("Peça jogada: [%c %d]\n", removida.nome, removida.id);
}

// EXIBIR FILA ATUAL
void mostrarFila() {
    printf("\nFila de peças: ");

    if (quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int i = inicio;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM; // avanço circular
    }
    printf("\n");
}

// INICIALIZA COM 5 PEÇAS
void inicializarFila() {
    for (int i = 0; i < TAM; i++) {
        fila[i] = gerarPeca();
    }
    quantidade = TAM;
    inicio = 0;
    fim = 0;
}

// PROGRAMA PRINCIPAL
int main() {
    srand(time(NULL)); // Gera números aleatórios diferentes

    inicializarFila();

    int op; // variável para armazenar a escolha do usuário

    // Loop do menu
    do {
        printf("\n===== MENU TETRIS STACK =====\n");
        printf("1 - Visualizar fila\n");
        printf("2 - Jogar peça (dequeue)\n");
        printf("3 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                mostrarFila();
                break;
            case 2:
                dequeue();
                mostrarFila();
                break;
            case 3:
                enqueue();
                mostrarFila();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

         } while (op != 0);

    return 0;
}