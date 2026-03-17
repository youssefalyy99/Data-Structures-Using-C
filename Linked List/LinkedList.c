#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* initialize( void );
void insertAtBeginning(LinkedList* ll , int x);
void insertAtEnd ( LinkedList* ll , int x );
void deleteFromEnd( LinkedList* ll );
void deleteFromBeginning( LinkedList* ll );
void display( LinkedList* ll );


int main(){
    LinkedList* ll = initialize();
    insertAtEnd(ll,1);
    insertAtEnd(ll,2);
    insertAtEnd(ll,3);
    display(ll);
    printf("\n");
    insertAtBeginning(ll,9);
    insertAtBeginning(ll,8);
    insertAtBeginning(ll,7);
    display(ll);
    printf("\n");
    deleteFromEnd(ll);
    deleteFromBeginning(ll);
    display(ll);
    return 0;
}

LinkedList* initialize( void ){
    LinkedList* ll = malloc(sizeof(LinkedList));
    ll->head = NULL;
    return ll;
}

void insertAtBeginning(LinkedList* ll , int x){
    Node* n = malloc(sizeof(Node));
    n->data = x;
    n->next = ll->head;
    ll->head = n;
}

void insertAtEnd ( LinkedList* ll , int x){
    Node* n = malloc(sizeof(Node));
    Node* temp = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if(ll->head == NULL){
        ll->head = n;
    }else{
        temp = ll->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
    return;
}

void deleteFromEnd(LinkedList* ll){
    if(ll->head == NULL){ return; }
    if(ll->head->next == NULL){
        free(ll->head);
        ll->head = NULL;
        return;
    }
    Node* prev = NULL;
    Node* temp = ll->head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return;
}


void deleteFromBeginning(LinkedList* ll){
    if(ll->head == NULL){return;}
    Node* temp = ll->head;
    temp = temp->next;
    free(ll->head);
    ll->head = temp;
    return;
}

void display( LinkedList* ll ){
    Node* temp = ll->head;
    if(ll->head == NULL){ return; }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    return;
}