# Student Record Search System using Trees - Project Report

## 1. Problem Statement

The project develops a Student Record Search System using a Binary Search
Tree. Each student has a unique enrolment ID, name, and department. The
enrolment ID is used as the BST key.

## 2. Data Structure Design

Each BST node contains:

- A student record
- A pointer to the left child
- A pointer to the right child

The BST ordering property is maintained as follows:

- Enrolment IDs smaller than the current node go to the left subtree.
- Enrolment IDs larger than the current node go to the right subtree.
- Duplicate enrolment IDs are rejected.

## 3. Insertion

Insertion begins at the root. The new enrolment ID is compared with the
current node:

- If smaller, move to the left subtree.
- If larger, move to the right subtree.
- If equal, display a duplicate-record message and do not insert.

A new node is inserted when an empty left or right pointer is found.

## 4. Search

Search follows the same comparison process as insertion. If the enrolment ID
matches a node, the student details are displayed. If the search reaches a
NULL pointer, the record does not exist.

## 5. Deletion

The program handles all three deletion cases:

| Case | Description | Action |
|---|---|---|
| Leaf node | Node has no children | Remove the node directly |
| One-child node | Node has one child | Replace node with its child |
| Two-child node | Node has two children | Replace node with inorder successor and delete successor |

For a two-child deletion, the inorder successor is the smallest enrolment ID
in the right subtree.

## 6. Tree Traversals

- Inorder: Left -> Root -> Right; gives sorted enrolment IDs.
- Preorder: Root -> Left -> Right.
- Postorder: Left -> Right -> Root.

## 7. Time Complexity

| Operation | Average case | Worst case |
|---|---:|---:|
| Insertion | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |
| Traversal | O(n) | O(n) |
| Space complexity | O(n) | O(n) |

For a balanced BST, each comparison removes about half of the remaining
search space, giving O(log n) performance. In the worst case, the BST becomes
a skewed tree and behaves like a linked list, so operations take O(n) time.
[31][33][40]

## 8. Effect of Tree Shape

If records are inserted in a balanced-looking order, the tree remains short
and searches require fewer comparisons.

If records are inserted in sorted order, every new record becomes the right
child of the previous record. This creates a right-skewed tree with height
n - 1, making insertion and search O(n).

Example:

```text
10
  \
   20
     \
      30
        \
         40
```

## 9. AVL Tree Improvement

An AVL tree is a self-balancing binary search tree. After every insertion or
deletion, it checks the balance factor of nodes and performs rotations when
required.

This keeps the tree height close to O(log n), ensuring that insertion, search,
and deletion remain O(log n) even if records are inserted in sorted order.
[32][36]

## 10. Test Cases

### Test Case 1: Successful Search

Input: Enrolment ID 105  
Expected: Student details displayed  
Actual: Diya Patel, Electronics  

### Test Case 2: Duplicate Insertion

Input: Enrolment ID 102  
Expected: Duplicate message  
Actual: Duplicate enrolment ID 102 found. Record not inserted.  

### Test Case 3: Leaf Deletion

Input: Delete enrolment ID 110  
Expected: Record removed without affecting other nodes  
Actual: Leaf node deleted successfully.  

### Test Case 4: Two-Child Deletion

Input: Delete enrolment ID 102  
Expected: Inorder successor replaces the deleted node  
Actual: BST remains valid and inorder output remains sorted.  
