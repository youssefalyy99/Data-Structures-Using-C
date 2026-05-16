#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* leftRot(Node* x);
Node* rightRot(Node* y);
Node* newNode(int data);
Node* insert(Node* root , int data);
int max(int a , int b);
int height(Node* n);
int getBalance(Node* n);


int main(){

}

int max(int a , int b){
    if(a > b){
        return a;
    }else if(b >= a){
        return b;
    }
}

int height(Node* n){
    if(n == NULL){
        return 0;
    }else{
        return n->height;
    }
}

Node* newNode(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->heigth = 1;
    return n;
}

int getBalance(Node* n){
    if(n == NULL){
        return 0;
    }else{
        return height(n->left) - height(n->left);
    }
}

Node* insert(Node* root , int data){
    // NORMAL INSERT FIRST

    if(root == NULL){
        root = newNode(data);
    }else if( val > root->data ){
        root->right = insert(root->right , data );
    }else if( val < root->data ){
        root->left = insert(root->left , data );
    }else{
        return root;
    }

    //UPDATE HEIGHT
    root->height = 1 + max( height(root->left) , height(root->left) );

    // BALANCE FACTOR
    int balance = getBalance(root);

    //LL
    if(balance > 1 && data < root->left->data ){
        return rightRot(root);
    }

    //RR
    if(balance < -1 && data > root->right->data ){
        return leftRot(root);
    }

    //LR
    if(balance > 1 && data > root->left->data){
        root->left = leftRot(root->left);
        return rightRot(root);
    }

    //RL
    if(balance < -1 && data < root->right->data){
        root->right = rightRot(root->right);
        return leftRot(root);
    }

    return root;
}

Node* rightRot(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1 + max(height(y->left),height(y->right));
    return x;
}

Node* leftRot(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1 + max(height(y->left),height(y->right));
    return y;
}