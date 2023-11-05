#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Definindo uma estrutura de pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack* stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Função para empilhar um valor na pilha
void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Erro: a pilha esta cheia\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Função para desempilhar um valor da pilha
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha esta vazia\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Função para avaliar uma expressão em notação posfixa
int evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0'); // Converter caractere numérico para inteiro
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Erro: operador invalido na expressao\n");
                    exit(1);
            }
        }
    }

    return pop(&stack); // O resultado final estará no topo da pilha
}

void exercicio7() {
    char expression[] = "34*52*+";
    int result = evaluatePostfix(expression);
    printf("Resultado da expressao: %d\n", result);
}
