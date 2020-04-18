#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __linux__
#endif

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* createNode(int value, Node* parent){
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insertNode(Node **head, int value){
    Node *insertionNode = NULL, *tmp = NULL;
    if(*head == NULL){
        *head = createNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp){
        if(value > tmp->data){
            if(tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = createNode(value, tmp);
                return;
            }
        } else if(value < tmp->data){
            if(tmp->left){
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = createNode(value, tmp);
                return;
            }
        } else{
            return;
        }
    }
}

Node* getMaxNode(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node *getNodeByValue(Node *root, int value) {
    while (root) {
        if (root->data > value) {
            root = root->left;
            continue;
        } else if (root->data < value) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}

void removeNodeByPtr(Node *target) {
    if (target->left && target->right) {
        Node *localMax = getMaxNode(target->left);
        target->data = localMax->data;
        removeNodeByPtr(localMax);
        return;
    } else if (target->left) {
        if (target == target->parent->left) {
            target->parent->left = target->left;
        } else {
            target->parent->right = target->left;
        }
    } else if (target->right) {
        if (target == target->parent->right) {
            target->parent->right = target->right;
        } else {
            target->parent->left = target->right;
        }
    } else {
        if (target == target->parent->left) {
            target->parent->left = NULL;
        } else {
            target->parent->right = NULL;
        }
    }
    free(target);
}

void deleteNode(Node *root, int value) {
    Node *target = getNodeByValue(root, value);
    if(target != NULL) {
        removeNodeByPtr(target);
    }
}

void printTree(Node *root, int lvl){
    if(root){
        printTree(root->left,lvl + 1);
        for(int i = 0; i < lvl; i++){
            printf("   ");
        }
        printf("%i\n",root->data);
        printTree(root->right,lvl + 1);
    }
}


int main() {
    Node *root = NULL;
    insertNode(&root, 3);
    insertNode(&root, 4);
    insertNode(&root, 6);
    insertNode(&root, 7);
    insertNode(&root, 22);
    insertNode(&root, 33);
    insertNode(&root, 44);
    deleteNode(root, 7);
    printTree(root, 0);
    return 0;
}