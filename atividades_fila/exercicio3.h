#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_NOME_LIVRO 100

// Definição do TAD fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila esta vazia.\n");
        return -1;
    } else {
        int data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        return data;
    }
}

// Definição do registro do livro
typedef struct {
    char nome[MAX_NOME_LIVRO];
    int disponibilidade;
    Queue fila_espera;
} Livro;

// Função para cadastrar um livro
void cadastrarLivro(Livro* biblioteca, int* numLivros, const char* nomeLivro) {
    if (*numLivros < MAX_LIVROS) {
        strcpy(biblioteca[*numLivros].nome, nomeLivro);
        biblioteca[*numLivros].disponibilidade = 1; // Livro inicialmente disponível
        initializeQueue(&biblioteca[*numLivros].fila_espera);
        (*numLivros)++;
        printf("Livro \"%s\" cadastrado com sucesso.\n", nomeLivro);
    } else {
        printf("A biblioteca atingiu o limite maximo de livros.\n");
    }
}

// Função para retirar um livro
void retirarLivro(Livro* biblioteca, int numLivros, const char* nomeLivro) {
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].nome, nomeLivro) == 0) {
            if (biblioteca[i].disponibilidade) {
                biblioteca[i].disponibilidade = 0; // Marcar como indisponível
                printf("Livro \"%s\" retirado com sucesso.\n", nomeLivro);
            } else {
                printf("O livro \"%s\" nao esta disponivel no momento. Voce pode entrar na fila de espera.\n", nomeLivro);
            }
            return;
        }
    }
    printf("O livro \"%s\" nao foi encontrado na biblioteca.\n", nomeLivro);
}

// Função para solicitar um livro
void solicitarLivro(Livro* biblioteca, int numLivros, const char* nomeLivro, int numPessoa) {
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].nome, nomeLivro) == 0) {
            if (biblioteca[i].disponibilidade) {
                biblioteca[i].disponibilidade = 0; // Marcar como indisponível
                printf("Livro \"%s\" retirado com sucesso pela pessoa %d.\n", nomeLivro, numPessoa);
            } else {
                enqueue(&biblioteca[i].fila_espera, numPessoa);
                printf("O livro \"%s\" nao esta disponivel no momento. A pessoa %d entrou na fila de espera.\n", nomeLivro, numPessoa);
            }
            return;
        }
    }
    printf("O livro \"%s\" nao foi encontrado na biblioteca.\n", nomeLivro);
}

// Função para liberar um livro
void liberarLivro(Livro* biblioteca, int numLivros, const char* nomeLivro) {
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].nome, nomeLivro) == 0) {
            if (!biblioteca[i].disponibilidade) {
                if (!isEmpty(&biblioteca[i].fila_espera)) {
                    int numPessoa = dequeue(&biblioteca[i].fila_espera);
                    printf("O livro \"%s\" foi liberado. A pessoa %d recebeu o livro.\n", nomeLivro, numPessoa);
                } else {
                    biblioteca[i].disponibilidade = 1; // Marcar como disponível
                    printf("O livro \"%s\" foi liberado e agora esta disponivel.\n", nomeLivro);
                }
            } else {
                printf("O livro \"%s\" ja esta disponível.\n", nomeLivro);
            }
            return;
        }
    }
    printf("O livro \"%s\" nao foi encontrado na biblioteca.\n", nomeLivro);
}

void exercicio3() {
    Livro biblioteca[MAX_LIVROS];
    int numLivros = 0;
    int numPessoa = 1;

    // Exemplo de utilização das funções
    cadastrarLivro(biblioteca, &numLivros, "Jogos Vorazes");
    cadastrarLivro(biblioteca, &numLivros, "Harry Potter");
    retirarLivro(biblioteca, numLivros, "Jogos Vorazes");
    retirarLivro(biblioteca, numLivros, "Harry Potter");
    solicitarLivro(biblioteca, numLivros, "Harry Potter", numPessoa++);
    solicitarLivro(biblioteca, numLivros, "Jogos Vorazes", numPessoa++);
    liberarLivro(biblioteca, numLivros, "Harry Potter");
    liberarLivro(biblioteca, numLivros, "Jogos Vorazes");

}
