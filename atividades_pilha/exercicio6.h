#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do TAD Pilha
#define MAX_TAMANHO 100

struct Pilha {
    char itens[MAX_TAMANHO];
    int topo;
};

// Função para criar uma pilha vazia
void create(struct Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
bool isEmpty(struct Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para verificar se a pilha está cheia
bool isFull(struct Pilha *pilha) {
    return pilha->topo == MAX_TAMANHO - 1;
}

// Função para empilhar um elemento na pilha
void push(struct Pilha *pilha, char item) {
    if (!isFull(pilha)) {
        pilha->itens[++(pilha->topo)] = item;
    }
}

// Função para desempilhar um elemento da pilha
char pop(struct Pilha *pilha) {
    if (!isEmpty(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return '\0';
}

// Função para acessar o elemento no topo da pilha
char top(struct Pilha *pilha) {
    if (!isEmpty(pilha)) {
        return pilha->itens[pilha->topo];
    }
    return '\0';
}

// Função para verificar o equilíbrio de parênteses em uma equação
void verificarEquacao(char equacao[]) {
    struct Pilha pilha;
    create(&pilha);

    int errosAbertura = 0;
    int errosFechamento = 0;

    for (int i = 0; equacao[i] != '\0'; i++) {
        if (equacao[i] == '(') {
            push(&pilha, equacao[i]);
        } else if (equacao[i] == ')') {
            char topo = pop(&pilha);
            if (topo == '\0') {
                errosFechamento++;
            }
        }
    }

    while (!isEmpty(&pilha)) {
        errosAbertura++;
        pop(&pilha);
    }

    if (errosAbertura == 0 && errosFechamento == 0) {
        printf("Os parenteses estao balanceados corretamente.\n");
    } else {
        printf("Erro em abertura de parenteses: %d vezes\n", errosAbertura);
        printf("Erro em fechamento de parenteses: %d vezes\n", errosFechamento);
    }
}

void exercicio6() {
    char equacao[] = "(a + b) * (c - d)";
    verificarEquacao(equacao);

}
