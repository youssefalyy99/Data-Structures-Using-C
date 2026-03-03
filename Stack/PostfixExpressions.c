#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int evaluate( char x , int op1 , int op2 );

int main(){
    char exp[30];
    printf("Enter Expression : ");
    scanf("%s",exp);

    int len = strlen(exp);
    stack* st = initialize ();
    for(int i = 0 ; i < len ; i++){
        if(isdigit(exp[i])){
            push(st,exp[i] - '0');
        }else{
            int op2 = pop(st);
            int op1 = pop(st);
            push(st,evaluate( exp[i],  op1 , op2 ));
        }
    }


    printf("Expression Result = %d " , st->arr[st->top]);
    return 0;
}

int evaluate( char x , int op1 , int op2 ){
    if(x == '*'){
        return op1 * op2;
    }else if(x == '-'){
        return op1 - op2;
    }else if(x == '+'){
        return op1 + op2;
    }else if(x == '/'){
        return op1 / op2;
    }
}