//Essa atividade é um TAD utilizando pilha

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Tamanho máximo da pilha

// Definindo a estrutura da pilha
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Função para criar uma pilha vazia
Stack* Create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; // Inicializa o topo como -1 (pilha vazia)
    return stack;
}

// Função para verificar se a pilha está vazia
int IsEmpty(Stack* stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int IsFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para adicionar um elemento à pilha (push)
void Push(Stack* stack, int value) {
    if (IsFull(stack)) {
        printf("A pilha esta cheia. Nao e possivel adicionar mais elementos.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Função para remover um elemento da pilha (pop)
int Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("A pilha esta vazia. Nao e possivel remover elementos.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Função para obter o elemento no topo da pilha
int Top(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("A pilha esta vazia. Nao ha elemento no topo.\n");
        return -1;
    }
    return stack->data[stack->top];
}

//chame a funçao a seguir no main
void exercicio2() {
    Stack* stack = Create();

    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);

    printf("Topo da pilha: %d\n", Top(stack));

    Pop(stack);
    printf("Topo da pilha apos a operacao pop: %d\n", Top(stack));

    free(stack); // Libera a memória alocada para a pilha

}
