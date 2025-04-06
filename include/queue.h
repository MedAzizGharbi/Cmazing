#ifndef QUEUE_H
#define QUEUE_H

#include "maze.h"

typedef struct QueueNode {
  Point data;
  struct QueueNode *next;
} QueueNode;

typedef struct Queue {
  QueueNode *front;
  QueueNode *back;
} Queue;

Queue *create_queue();
void enqueue(Queue *queue, Point data);
Point dequeue(Queue *queue);
bool is_empty(Queue *queue);
void free_queue(Queue *queue);

#endif // !QUEUE_H
