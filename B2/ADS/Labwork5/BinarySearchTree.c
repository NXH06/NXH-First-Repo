#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;
Node *init (int val) { // creates new node
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// REMEMBER: (all lefts < node) and (all rights > node)
Node *search (Node *node, int val) {
    if (node == NULL || val == node->val) {
        return node;
    }
    else if (val < node->val) {
        return search (node->left, val);
    }
    else {
        return search (node->right, val);
    }
}
void preOrder (Node *node) { // Pre-order traversal
    if (node != NULL) {
        printf("%d ", node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
}
void inOrder (Node *node) { // In-order traversal
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->val);
        inOrder(node->right);
    }
}
void postOrder (Node *node) { // Post-order traversal
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->val);
    }
}
Node *insert (Node *node, int val) {
    if (node == NULL) {
        return init(val);
    }
    if (val < node->val) {
        node->left = insert(node->left, val);
    }
    else if (val > node->val) {
        node->right = insert(node->right, val);
    }
    return node;
}
Node *findMin (Node *node) {
    if (node == NULL) {
        return NULL;
    }
    else if (node->left != NULL) {
        return findMin(node->left);
    }
    return node;
}
Node *findMax (Node *node) {
    if (node == NULL) {
        return NULL;
    }
    else if (node->right != NULL) {
        return findMax(node->right);
    }
    return node;
}
Node *delete (Node *node, int val) {
    if (node == NULL) {
        return NULL;
    }
    if (val < node->val) {
        node->left = delete(node->left, val);
    }
    else if (val > node->val) {
        node->right = delete(node->right, val);
    }
    else { // val == node->val: delete cases in this clause
        if (node->left == NULL && node->right == NULL) { // no children: just delete node
            free(node);
            return NULL;
        }
        else if (node->left == NULL || node->right == NULL) { // 1 child: replace node with its child
            Node *child = init(0);
            if (node->left == NULL) child = node->right;
            if (node->right == NULL) child = node->left;
            free(node);
            return child;
        }
        else { // 2 children
            Node *successor = findMin(node->right);
            node->val = successor->val;
            node->right = delete(node->right, successor->val);
        }
    }
    return node;
}
int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 80);
    insert(root, 80);
    // Search for node with value 60
    if (search(root, 60) != NULL) {
        printf("60 found");
    }
    else {
        printf("60 not found");
    }
    printf("\n");
    if (search(root, 100) != NULL) {
        printf("100 found");
    }
    else {
        printf("100 not found");
    }
    printf("\n");
    postOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    // Delete the node with value 70 (will replace it with 60)
    Node* temp = delete(root, 70);
    printf("After delete: \n");
    inOrder(root);
    return 0;
}