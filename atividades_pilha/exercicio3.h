//TAD do exercicio2 mas com uma função que verifica se duas pilhas são iguais

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

// Função para verificar se duas pilhas são iguais
int AreEqual(Stack* stack1, Stack* stack2) {
    if (stack1->top != stack2->top) {
        return 0; // As pilhas têm tamanhos diferentes, não podem ser iguais
    }

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->data[i] != stack2->data[i]) {
            return 0; // Os elementos são diferentes, as pilhas não são iguais
        }
    }

    return 1; // As pilhas são iguais
}

//chame a função a seguir no main
void exercicio3() {
    Stack* stack1 = Create();
    Stack* stack2 = Create();

    Push(stack1, 10);
    Push(stack1, 20);
    Push(stack1, 30);

    Push(stack2, 10);
    Push(stack2, 20);
    Push(stack2, 30);

    if (AreEqual(stack1, stack2)) {
        printf("As pilhas são iguais.\n");
    } else {
        printf("As pilhas não são iguais.\n");
    }

    free(stack1);
    free(stack2);
}
