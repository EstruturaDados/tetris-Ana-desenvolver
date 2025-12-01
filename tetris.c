
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
int proximoID = 1;   // contador para gerar ID único para cada peça

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

    fila[fim] = gerarPeca();
    fim = (fim + 1) % TAM;
    quantidade++;

    printf("Peça inserida com sucesso!\n");
}

   