#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct{
    Node* head;
} cdll;

cdll* initialize();
Node* newnode();
void insertAtBeginning( cdll* l , int value );
void insertAtEnd( cdll* l , int value );
void deleteFromBeginning( cdll* l );
void deleteFromEnd(cdll* l);
void display(cdll* l);

int main(){
        cdll* doublelinkedlist = initialize();
        insertAtBeginning( doublelinkedlist , 1 );
        insertAtBeginning( doublelinkedlist , 2 );
        insertAtBeginning( doublelinkedlist , 3 );
        insertAtBeginning( doublelinkedlist , 4 );
        insertAtEnd( doublelinkedlist , 99 );
        insertAtEnd( doublelinkedlist , 88 );
        insertAtEnd( doublelinkedlist , 77 );
        deleteFromEnd(doublelinkedlist);
        deleteFromEnd(doublelinkedlist);
        deleteFromBeginning( doublelinkedlist );
        display(doublelinkedlist);
    return 0;
}

cdll* initialize(){
    cdll* l = malloc(sizeof(cdll));
    l->head = NULL;
    return l;
}

Node* newnode(){
    Node* n = malloc(sizeof(Node));
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertAtBeginning( cdll* l , int value ){
    Node* n = newnode();
    if(l->head == NULL){
        l->head = n;
        n->data = value;
        n->next = n;
        n->prev = n;
    }else{
        Node* tail= l->head->prev;
        n->data = value;
        n->next = l->head;
        n->prev = tail;
        tail->next = n;
        l->head->prev = n;
        l->head = n;
    }
}

void insertAtEnd( cdll* l , int value ){
    Node* n = newnode();
    if(l->head == NULL){
        l->head = n;
        n->data = value;
        n->next = n;
        n->prev = n;
    }else{
        Node* tail = l->head->prev;
        n->data = value;
        tail->next = n;
        n->next = l->head;
        n->prev = tail;
        l->head->prev = n;
    }
}

void deleteFromBeginning( cdll* l ){
    if(l->head == NULL){
        return;
    }else if(l->head == l->head->next){
        free(l->head);
        l->head = NULL;
    }else{
        Node* after = l->head->next;
        after->prev = l->head->prev;
        l->head->prev->next = after; 
        free(l->head);
        l->head = after;
    }
}

void deleteFromEnd(cdll* l){
    if(l->head == NULL){
        return;
    }else if(l->head == l->head->next){
        free(l->head);
        l->head = NULL;
    }else{
        Node* tail = l->head->prev;
        tail->prev->next = l->head ;
        l->head->prev = tail->prev;
        free(tail);
    }
}

void display(cdll* l){
    Node* temp = l->head;
    do{
        printf("%d ", temp->data );
        temp = temp->next;
    }while(temp != l->head);
}