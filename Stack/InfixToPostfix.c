#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int priority( char op );

int main(){
    stack* st = initialize();
    stack* postfix = initialize();
    char infix[100];
    printf("Enter Infix Experssion : ");
    scanf("%s" , infix);

    for( int i = 0 ; i < strlen(infix) ; i++ ){

        if(isdigit(infix[i])){ // IF INTFIX IS NUMBER PUSH TO OUTPUT DIRECTLY
            push(postfix,infix[i]);
        }else if( infix[i] != ')' ){ // ELSE IF IS IT AN OPERATION
            if(isEmpty(st)){ // CHECK IF EMPTY
                push(st,infix[i]);
            }else{ // ELSE CHECK PRIORITY
                if(priority(infix[i]) > priority(peek(st))){ // IF HIGHTER PRIORITY PUSH IT
                    push(st,infix[i]);
                }else{ // ELSE POP ALL UNTILL A SMALLER PRIORITY APPEAR
                    while( !isEmpty(st) && priority(peek(st)) >= priority(infix[i]) && peek(st) != '('){
                        push(postfix,pop(st));
                    }
                    push(st,infix[i]);
                }
            }
        } else if ( infix[i] == ')' ){
            while(!isEmpty(st) && peek(st) != '(' ){
                push(postfix,pop(st));
            }
            pop(st);
        }
    }

    if(!isEmpty(st)){ // IF STACK STILL HAVE ELEMENTS
        while(!isEmpty(st)){
            push(postfix,pop(st)); // PUSH THEM TO THE OUTPUT
        }
    }

    printf("Postfix Experssion : ");
    for(int i = 0 ; i <= postfix->top ; i++){
        printf("%c " , postfix->arr[i]);
    }
}

int priority( char op ){
    if(op == '('){
        return 2;
    }else if( op == '*' || op == '/' || op == '%'){
        return 1;
    }else if( op == '+' || op == '-'){
        return 0;
    }
}