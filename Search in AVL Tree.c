#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int height(struct Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(struct Node* N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

// Insert function (same as before but shortened)
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) { 
        struct Node* y = node->left;
        node->left = y->right; y->right = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    if (balance < -1 && key > node->right->key) {
        struct Node* y = node->right;
        node->right = y->left; y->left = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    return node;
}

// Search function
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);

    struct Node* found = search(root, 20);
    if (found != NULL)
        printf("Found: %d\n", found->key);
    else
        printf("Not Found\n");

    return 0;
}
