#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node *top;
    Node *start;
} Stack;

Stack* initialize();
Node* newnode();
void push( Stack* st , int value );
void pop(Stack* st);
void display(Stack* st);

int main(){
    Stack* st = initialize();
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    pop(st);
    pop(st);
    push(st,6);
    push(st,7);
    display(st);
    return 0;
}


Stack* initialize(){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    st->start = NULL;
    return st;
}

Node* newnode(){
    Node* n = (Node*)malloc(sizeof(Node));
    n->next = NULL;
    return n;
}

void push( Stack* st , int value ){
    Node* n = newnode();
    if(st->top == NULL){
        st->top = n;
        n->data = value;
        st->start = n;
    }else{
        st->top->next = n;
        st->top = n;
        n->data = value;
    }
}

void pop(Stack* st){
    if(st->top == NULL){
        return;
    }else{
        Node* temp = st->start;
        Node* prev;
        while( temp != st->top ){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        st->top = prev;
        free(temp);
    }
}

void display(Stack* st){
    Node* temp = st->start;
    while(temp != NULL){
        printf("%d " , temp->data );
        temp = temp->next;
    }
    return;
}