//TAD do exercicio2 mas com uma função que inverte a pilha

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
        printf("A pilha está cheia. Não é possível adicionar mais elementos.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Função para remover um elemento da pilha (pop)
int Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("A pilha está vazia. Não é possível remover elementos.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Função para obter o elemento no topo da pilha
int Top(Stack* stack) {
    if (IsEmpty(stack)) {
        printf("A pilha está vazia. Não há elemento no topo.\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Função para inverter a posição dos elementos de uma pilha
void ReverseStack(Stack* stack) {
    int reversed[MAX_SIZE];
    int index = 0;

    while (!IsEmpty(stack)) {
        reversed[index++] = Pop(stack);
    }

    for (int i = 0; i < index; i++) {
        Push(stack, reversed[i]);
    }
}


void exercicio4() {
    Stack* stack = Create();

    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);

    printf("Pilha original:\n");
    while (!IsEmpty(stack)) {
        printf("%d\n", Pop(stack));
    }

    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);

    ReverseStack(stack);

    printf("Pilha invertida:\n");
    while (!IsEmpty(stack)) {
        printf("%d\n", Pop(stack));
    }

    free(stack);
}
