#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void push(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // Se a fila estiver vazia, o novo nó se torna o primeiro da fila.
        queue->front = queue->rear = newNode;
    } else {
        // Caso contrário, adicionamos o novo nó ao final da fila.
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


int isQueueSorted(Queue* queue) {
    if (queue->front == NULL || queue->front->next == NULL) {
        // A fila está vazia ou tem apenas um elemento, consideramos como ordenada.
        return 1;
    }

    Node* current = queue->front;
    int prevData = current->data;

    while (current != NULL) {
        if (current->data < prevData) {
            // Se o elemento atual for menor que o anterior, a fila não está ordenada.
            return 0;
        }
        prevData = current->data;
        current = current->next;
    }

    // Se chegamos até aqui, a fila está ordenada.
    return 1;
}

void exercicio1() {
    Queue myQueue;
    myQueue.front = myQueue.rear = NULL;

    // Adicione elementos à fila aqui, por exemplo:
    push(&myQueue, 1);
    push(&myQueue, 2);
    push(&myQueue, 3);

    if (isQueueSorted(&myQueue)) {
        printf("A fila esta ordenada de forma crescente.\n");
    } else {
        printf("A fila nao esta ordenada de forma crescente.\n");
    }

}
