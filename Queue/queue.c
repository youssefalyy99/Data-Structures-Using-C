#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int arr[100];
    int front;
    int rear;
} queue;

queue* initialize();
int isEmpty(queue* q);
int isFull(queue* q);
void enqueue( queue* q , int x );
int dequeue(queue* q);



int main() {
    queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("%d\n", dequeue(q)); // 10
    printf("%d\n", dequeue(q)); // 20

    enqueue(q, 40);
    printf("%d\n", dequeue(q)); // 30
    printf("%d\n", dequeue(q)); // 40
    return 0;
}

queue* initialize(){
    queue* q = malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue* q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(queue* q){
    if( (q->rear + 1)%100 == q->front ){
        return 1;
    }else{
        return 0;
    }
}

void enqueue( queue* q , int x ){
    if(isEmpty(q)){
        q->rear = 0;
        q->front = 0;
    }else{
        q->rear = (q->rear + 1)%100;
    }
    q->arr[q->rear] = x;
    return;
}

int dequeue(queue* q){
    if(isEmpty(q)){
        return -1;
    }else{
        int val = q->arr[q->front];
    if(q->front == q-> rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = (q->front + 1)%100;
    }
    return val;
    }
}


