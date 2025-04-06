#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* create_queue(){
    Queue* queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
};

void enqueue(Queue *queue, Point data){
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    if(queue->back != NULL){
        queue->back->next = new_node;
    }
    queue->back = new_node;
    if(queue->front == NULL){
        queue->front = new_node;
    }
}

bool is_empty(Queue *queue){
    return (queue->front == NULL);
}

void free_queue(Queue *queue){
    while(!is_empty(queue)){
        dequeue(queue);
    }
    free(queue);
}

Point dequeue(Queue *queue){
    if(is_empty(queue)){
        printf("queue is empty");
        exit(EXIT_FAILURE);
    }
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    Point data = temp->data;
    if(queue->front == NULL){
        queue->back = NULL;
    }
    free(temp);
    return data;
}
