#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da fila
struct Node {
    int data;
    struct Node* next;
};

// Estrutura da fila
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Função para criar uma fila vazia
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Função para enfileirar um elemento na fila
void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento da fila
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    struct Node* temp = queue->front;
    int item = temp->data;
    queue->front = temp->next;
    free(temp);
    return item;
}

// Função para inverter a fila F1
void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue))
        return;
    int data = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, data);
}


// Função para imprimir uma fila
void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void exercicio2() {
    struct Queue* F1 = createQueue();

    // Preencha a fila F1 com alguns elementos
    enqueue(F1, 1);
    enqueue(F1, 2);
    enqueue(F1, 3);
    enqueue(F1, 4);
    enqueue(F1, 5);

    printf("Fila F1: ");
    printQueue(F1);

    reverseQueue(F1);

    printf("Fila F1 (invertida): ");
    printQueue(F1);

}
