#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int arr[100];
    int top;
} stack;

stack* initialize (void);
void push(stack *s , int value);
int pop(stack *s);
int peek(stack* s);
int isEmpty(stack *s);
int isFull(stack *s);


int main(){
    
}


stack* initialize (void) {
    stack* s = malloc(sizeof(stack));
    s->top = -1;
    return s;
}

void push(stack *s , int value){
    s->top++;
    s->arr[s->top] = value;
    return;
}

int pop(stack *s){
    int value = s->arr[s->top];
    s->top--;
    return value;
}

int peek(stack* s){
    return s->arr[s->top] ;
}

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(stack *s){
    if(s->top == 100-1){
        return 1;
    }else{
        return 0;
    }
}
