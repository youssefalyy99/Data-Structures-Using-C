#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* newNode(int val);

// Traversal Functions

void PreOrder(Node* root);
void InOrder(Node* root);
void PostOrder(Node* root);

// Binary Tree Functions

Node* insert(Node* root,int key);
Node* searchRecursive(Node* root , int val);
Node* FindMin(Node* root);
Node* Delete(Node *root , int data);


int main() {
    Node* root = NULL;

    // Insert values
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Test Traversals
    printf("PreOrder Traversal: ");
    PreOrder(root);
    printf("\n");

    printf("InOrder Traversal: ");
    InOrder(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    PostOrder(root);
    printf("\n");

    return 0;
}

Node* newNode(int val){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Traversal Binary Tree Functions

void PreOrder(Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node* root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

void PostOrder(Node* root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}

// Binary Tree Construction

Node* insert(Node* root,int key){
    if(root == NULL){
        root = newNode(key);
    }else if( key < root->data ){
        root->left = insert(root->left,key);
    }else if( key > root->data ){
        root->right = insert(root->right,key);
    }
    return root;
}

Node* searchRecursive(Node* root , int val){
    if(root == NULL){
        return NULL;
    }else if( root->data == val ){
        return root;
    }else if (val < root->data){
        return searchRecursive(root->left , val);
    }else if( val > root->data ){
        return searchRecursive(root->right , val);
    }
    return NULL;
}

Node* FindMin(Node* root){
    if(root == NULL){
        return NULL;
    }else if( root->left != NULL ){
        return FindMin(root->left);
    }else{
        return root;
    }
}

Node* Delete(Node *root , int data){
    Node* temp;
    if(root == NULL){
        return NULL;
    }else if( root->data > data ){
        root->left = Delete(root->left,data);
    }else if( root->data < data ){
        root->right= Delete(root->right,data);
    }else{
        if(root->right != NULL && root->left != NULL ){
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right , temp->data );
        }else{
            temp = root;
            if(root->left == NULL){
                root = root->right;
            }else if(root->right == NULL){
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
}