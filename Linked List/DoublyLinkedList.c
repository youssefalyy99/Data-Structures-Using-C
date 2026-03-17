#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct{
    Node* head;
} dll;

dll* initialize();
Node* newnode();
void insertAtBeginning( dll* l , int value );
void insertAtEnd( dll* l , int value );
void deleteFromBeginning( dll* l );
void deleteFromEnd(dll* l);
void display(dll* l);

int main(){
        dll* doublelinkedlist = initialize();
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

dll* initialize(){
    dll* l = malloc(sizeof(dll));
    l->head = NULL;
    return l;
}

Node* newnode(){
    Node* n = malloc(sizeof(Node));
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertAtBeginning( dll* l , int value ){
    Node* n = newnode();
    if(l->head == NULL){
        l->head = n;
        n->data = value;
    }else{
        n->next = l->head;
        l->head->prev = n;
        l->head = n;
        n->data = value;
    }
}

void insertAtEnd( dll* l , int value ){
    Node* n = newnode();
    if(l->head == NULL){
        l->head = n;
        n->data = value;
    }else{
        Node* temp = l->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        n->data = value;
    }
}

void deleteFromBeginning( dll* l ){
    if(l->head == NULL){
        return;
    }else if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
    }else{
        Node* temp = l->head;
        l->head = l->head->next;
        free(temp);
        l->head->prev = NULL;
    }
}

void deleteFromEnd(dll* l){
    if(l->head == NULL){
        return;
    }else if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
    }else{
        Node* temp = l->head;
        Node* prev;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        temp->prev = NULL;
        prev->next = NULL;
        free(temp);
    }
}

void display(dll* l){
    Node* temp = l->head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}