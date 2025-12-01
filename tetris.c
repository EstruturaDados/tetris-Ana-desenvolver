
// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.

#include <stdio.h>  // funções de entrada/saída (printf, scanf)
#include <stdlib.h> // funções gerais (rand, srand)
#include <time.h>   // para usar time() e gerar números aleatórios diferentes a cada execução

#define TAM 5   // tamanho fixo da fila circular

int main() {
// STRUCT QUE REPRESENTA UMA PEÇA DO TETRIS
// Cada peça tem um nome (tipo) e um ID único

typedef struct {
    char nome;  // 'I', 'O', 'T', 'L'
    int id;     // identificador único
} Peca;
    
    



   