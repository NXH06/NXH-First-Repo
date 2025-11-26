#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
// Important: tree with only root counts as height 0
// both height and depth starts from 0
Node *buildCompleteTree (int height) { // each node is the root of a complete subtree, hence the recursion
    if (height < 0) {
        return NULL;
    }
    Node *root = init(0); // placeholder value
    if (height == 0) { // if height = 0, don't create subtrees on either side of the node
        return root;
    }
    root->left = buildCompleteTree(height - 1);
    root->right = buildCompleteTree(height - 1);
    return root;
}
void fillLeaves (Node *node, int *arr, int size, int *index, int E, int depth, int height) {
    // *arr: the array of values
    // index must be passed as pointer to be updated through recursions
    if (node == NULL) {
        return;
    }
    if (depth == height) {
        if (*index < size) {
            node->val = arr[*index];
            (*index)++;
        }
        else {
            node->val = E;
        }
        return;
    }
    fillLeaves(node->left, arr, size, index, E, depth + 1, height);
    fillLeaves(node->right, arr, size, index, E, depth + 1, height);
}
int assignMinVal (Node *node) {
    if (node->left == NULL && node->right == NULL) {
        return node->val;
    }
    int lmin = assignMinVal(node->left);
    int rmin = assignMinVal(node->right);
    if (lmin < rmin) {
        node->val = lmin;
    }
    else {
        node->val = rmin;
    }
    return node->val;
}
void replace (Node *node, int val, int parentVal) { // "deletes" leaf and replaces it with parent's value
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL && node->val == val) {
        node->val = parentVal;
        return;
    }
    replace(node->left, val, node->val);
    replace(node->right, val, node->val);
}
void printInOrder (Node *node, int depth) { // in-order traversal
    if (node == NULL) {
        return;
    }
    printInOrder(node->left, depth + 1);
    printf("%*s%d\n", depth * 4, "", node->val); // indents printed val depending on depth to create a tree-shape
    printInOrder(node->right, depth + 1);
}
int search (Node *node, int val, int depth) {
    if (node == NULL) {
        return 0; // leaf node reached, search continues
    }
    if (node->val == val) {
        printInOrder (node, depth);
        return 1;
    }
    // if the value is already found, all recursions return 1 immediately
    int isFound;
    isFound = search(node->left, val, depth + 1);
    if (isFound == 1) return 1;
    isFound = search(node->right, val, depth + 1);
    if (isFound == 1) return 1;
    // If all search functions have been executed without finding value:
    return -1;
}
int main() {
    int arr[13] = {0};
    int size = 13;
    srand(time(NULL)); // making sure the rand() is actually random by using a seed randomization function
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    int E = 101;
    int height = (int)(log2(size)) + 1;
    Node *root = buildCompleteTree(height);
    int index = 0;
    fillLeaves(root, arr, size, &index, E, 0, height);
    printf("\nTree before filling in internal nodes: \n");
    printInOrder(root, 0);
    assignMinVal(root);
    printf("Finished tree:\n");
    printInOrder(root, 0);
    printf("\nReplace 9th leaf:\n"); // might not produce visible result if arr[8] < arr[9]
    replace(root, arr[8], root->val);
    assignMinVal(root); // updates tree according to the rules
    printInOrder(root, 0);
    printf("\nReplace first leaf E found:\n");
    replace(root, E, root->val); // note: only replaces the first E found, since there are several
    assignMinVal(root);
    printInOrder(root, 0);
    int searchVal;
    printf("\nSearch for which value?: ");
    scanf("%d", &searchVal);
    printf("\nSearching for the value %d...\n", searchVal);
    int searchResult = search(root, searchVal, 0);
    if (searchResult == 1) {
        printf("\nValue found!");
    }
    else if (searchResult == -1) {
        printf("\nValue not found.");
    }
    return 0;
}
