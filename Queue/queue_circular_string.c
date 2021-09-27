#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_EMPTY NULL

typedef struct {
    char **values;
    int head, tail, num_entries, size;
} queue;

void init_queue(queue *q, int max_size) {
    q->size = max_size;
    q->values = (char **) malloc(sizeof(char *) * q->size);
    q->num_entries = 0; // we`re empty
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue *q) {
    return (q->num_entries == 0);
}

bool queue_full(queue *q) {
    return (q->num_entries == q->size);
}

void queue_distroy(queue *q) {
    free(q->values);
    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;
}

bool enqueue(queue *q, char *value) {
    
    if (queue_full(q)) {
        printf("Queue is full\n");
        return false;
    }

    q->values[q->tail] = (char*) malloc((sizeof value + 1)* sizeof(char));
    strcpy(q->values[q->tail], value);

    q->num_entries++;

    // If tail is equal or greater than size,
    // use modulo (q->tail = 0)
    q->tail = (q->tail + 1) % q->size;

    return true;
}

char* dequeue(queue *q) {
    if (queue_empty(q)) {
        return QUEUE_EMPTY;
    }

    int current_head = q->head;

    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return q->values[current_head];
}

int main() {
    queue q1;
    char* t;

    init_queue(&q1, 5);

    enqueue(&q1, "*16SW=1,1");
    enqueue(&q1, "*16SW=1,0");
    enqueue(&q1, "*26SW=1,1");
    enqueue(&q1, "*26SW=1,0");
    enqueue(&q1, "*36SW=1,1");
    // Below value was skipped (full queue)
    enqueue(&q1, "*36SW=1,0");

    while ((t = dequeue(&q1)) != QUEUE_EMPTY) {
        printf("t = %s\n", t);
    }

    

    return 0;
}