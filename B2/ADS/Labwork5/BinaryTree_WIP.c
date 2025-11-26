#include <stdio.h>
#include <stdlib.h>
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
// Instead of Binary Search Tree, it's a general binary tree now. The rules are different.
void preOrder (Node *node) { // Pre-order traversal
    if (node == NULL) {
        return;
    }
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder (Node *node) { // In-order traversal
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->val);
    inOrder(node->right);
}
void postOrder (Node *node) { // Post-order traversal
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->val);
}
void insert (Node **node, int val) { // void type because the node is modified directly - no need for a return value.
    Node *newNode = init(val);
    if (*node == NULL) {
        *node = newNode;
        return;
    }
    // Level order traversal to find appropriate place to insert node
    Node *temp;
    Node *queue[100];
    int front = -1, back = -1;
    queue[++back] = *node;
    // If child missing, insert node there. If child already exists, push to queue.
    // Queue keeps track of all nodes level-by-level so that the tree is always complete.
    while (front != back) {
        temp = queue[++front];
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        else {
            queue[++back] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = node;
            return;
        }
        else {
            queue[++back] = temp->right;
        }
    }
}
void delete (Node **node, int val) {
    if (*node == NULL) {
        return;
    }
}
int main() { // For recursive functions, input root node into parameter!
    // create root node
    Node *root = init(0);
    // initialize array with 10 random values between 0 and 100
    int arr[8] = {0};
    int size = 8;
    srand(time(NULL)); // making sure the rand() is actually random by using a seed randomization function
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return 0;
}