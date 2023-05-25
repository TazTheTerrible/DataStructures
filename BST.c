#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct bstNode {
    int data;
    struct bstNode *parent;
    struct bstNode *left;
    struct bstNode *right;
} bstNode;

bstNode* GetNewNode(int data){
    bstNode* newNode = malloc(sizeof(bstNode));
    newNode->data = data;
    newNode->parent = newNode->right = newNode->left = NULL;
    return newNode;
}

bool Search(bstNode* root, int data){
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data < root->data){
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

bstNode* Insert(bstNode** root, int data){
    if (*root == NULL){
        *root = GetNewNode(data);
    } else if (data < (*root)->data){
        (*root)->left = Insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        (*root)->right = Insert(&(*root)->right, data);
    } else {
        printf("Data already exists in the tree\n");
        return *root;
    }
    return *root;
}
int CountNodes(bstNode* root, int* count){
    if (root == NULL){
        return 0;
    }
    (*count)++;
    CountNodes(root->left, count);
    CountNodes(root->right, count);
    return *count;
}

bool IsInTree(bstNode* root, int data){
    if (root == NULL){
        return false;
    } else if (data == root->data){
        return true;
    } else if (data < root->data){
        return IsInTree(root->left, data);
    } else {
        return IsInTree(root->right, data);
    }
}

void DeleteTree(bstNode* root){
    if (root == NULL){
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    free(root);
    return;
}

void PrintMinToMax(bstNode* root){
    if (root == NULL){
        return;
    }
    PrintMinToMax(root->left);
    printf("%d", root->data);
    PrintMinToMax(root->right);
}

int GetHeight(bstNode* root){
    if (root == NULL){
        return -1;
    }
    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);
    int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return maxHeight + 1;
}

