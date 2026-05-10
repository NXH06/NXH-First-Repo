// Note: since a stack follows the FILO principle, in order to traverse left-right, the right child must be pushed before the left child
// push 10
// pop 10
// push 31, 6
// pop 6
// push 1
// pop 1
// pop 31
// push 110, 17
// pop 17
// push 22, 14
// pop 14
// pop 22
// pop 110
// final result: 10, 6, 1, 31, 17, 14, 22, 110
//
// Since this is already a BST, reverse-order traversal (RNL) will have the result sorted from largest to smallest
// RNL: like LNR, but traversing to the right is prioritized over traversing to the left instead of the opposite