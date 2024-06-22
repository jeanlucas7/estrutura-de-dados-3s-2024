#include <stdio.h>
#include "ArvB.h"

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("In-order: ");
    inOrderTraversal(root);
    printf("\nPre-order: ");
    preOrderTraversal(root);
    printf("\nPost-order: ");
    postOrderTraversal(root);
    printf("\n");

    int key = 40;
    Node* foundNode = searchNode(root, key);
    if (foundNode != NULL) {
        printf("Nó %d encontrado.\n", key);
    } else {
        printf("Nó %d não encontrado.\n", key);
    }

    root = deleteNode(root, 20);
    printf("Após remover 20, In-order: ");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("Após remover 30, In-order: ");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("Após remover 50, In-order: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
