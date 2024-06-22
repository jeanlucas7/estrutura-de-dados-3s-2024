#ifndef ARVB_H
#define ARVB_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);
Node* insertNode(Node* root, int data);
void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
Node* searchNode(Node* root, int key);
Node* deleteNode(Node* root, int key);

#endif