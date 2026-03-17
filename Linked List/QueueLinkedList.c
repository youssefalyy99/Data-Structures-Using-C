#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
Node* newnode();
void enqueue( Queue* q , int value );
void dequeue( Queue* q );
void display(Queue* q);

int main(){
    Queue* q = initialize();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}


Queue* initialize(){
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
}

Node* newnode(){
    Node* n = malloc(sizeof(Node));
    n->next = NULL;
}

void enqueue( Queue* q , int value ){
    Node* n = newnode();
    if(q->front == NULL && q->rear == NULL){
        q->front = n;
        q->rear = n;
        n->data = value;
    }else{
        q->rear->next = n;
        q->rear = n;
        n->data = value;
    }
}

void dequeue( Queue* q ){
    if(q->front == NULL && q->rear == NULL){
        return;
    }else if(q->front == q->rear){
        Node* temp = q->front;
        free(temp);
        q->front = q->rear = NULL;
    }else{
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

void display(Queue* q){
    Node* temp = q->front;
    while(temp != NULL){
        printf("%d " ,temp->data);
        temp = temp->next;
    }
    return;
}