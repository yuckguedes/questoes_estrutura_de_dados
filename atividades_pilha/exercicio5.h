/*

Essa atividade é uma especie de editor de texto:

• Considere que um editor de texto representa os caracteres
digitados como uma pilha, sendo que o último caractere lido
fica no topo
• Alguns comandos apagam caracteres
• # representa backspace (apaga só o último caractere digitado)
• @ indica “apagar tudo”
• Faça um programa que execute essas ações usando o TAD
pilha

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

Stack* Create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int IsEmpty(Stack* stack) {
    return stack->top == -1;
}

int IsFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void Push(Stack* stack, char value) {
    if (!IsFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

char Pop(Stack* stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0'; // Valor nulo para indicar pilha vazia
}

char Top(Stack* stack) {
    if (!IsEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0'; // Valor nulo para indicar pilha vazia
}

void PrintStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%c", stack->data[i]);
    }
    printf("\n");
}

//chame a funçao a seguir no main
void exercicio5() {
    Stack* textEditor = Create();

    printf("Digite qualquer coisa ou use # para backspace e @ para apagar tudo):\n");

    char input[100];
    while (1) {
        printf("Texto atual: ");
        PrintStack(textEditor);

        printf("Comando: ");
        scanf("%s", input);

        if (strcmp(input, "#") == 0) {
            Pop(textEditor);
        } else if (strcmp(input, "@") == 0) {
            while (!IsEmpty(textEditor)) {
                Pop(textEditor);
            }
        } else {
            char ch = input[0];
            Push(textEditor, ch);
        }
    }

    free(textEditor);
}
