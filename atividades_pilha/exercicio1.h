//Essa atividade consiste em tranformar numeros decimais em binário, colocando o resto das divisões do numero decimal em uma pilha, para no final juntar e formar o numero binario.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int items[MAX];
};

void push(struct Stack *ps, int x) {
    if (ps->top == MAX - 1) {
        printf("Erro: stack overflow\n");
        exit(1);
    } else {
        ps->items[++(ps->top)] = x;
    }
}

int pop(struct Stack *ps) {
    if (ps->top == -1) {
        printf("Erro: stack underflow\n");
        exit(1);
    } else {
        return ps->items[(ps->top)--];
    }
}

//chame a funçao a seguir no main
void exercicio1() {
    struct Stack s;
    s.top = -1;

    int n;
    printf("Digite um numero decimal: ");
    scanf("%d", &n);

    while (n > 0) {
        int rem = n % 2;
        push(&s, rem);
        n /= 2;
    }

    printf("O numero em binario e: ");
    while (s.top != -1) {
        printf("%d", pop(&s));
    }
    printf("\n");

}
