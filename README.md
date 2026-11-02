# Student Record Search System Using BST

## Objective
Implement a menu-driven student record system in C using a
Binary Search Tree keyed by enrollment ID.

## Record Fields
- Enrollment ID: positive integer
- Student name
- Programme / department

## Features
- Insert student records
- Reject duplicate enrollment IDs
- Search by enrollment ID
- Delete leaf, one-child, and two-child nodes
- Display inorder, preorder, and postorder traversals
- Load 10 sample records
- Compare balanced-looking and sorted insertion orders
- Show record count and tree height
- Release allocated memory on exit

## Compilation
gcc -std=c11 -Wall -Wextra -pedantic student_bst.c -o student_bst

## Running
Linux/macOS: ./student_bst
Windows: .\student_bst.exe

## Comparison Method
Count one comparison per existing node visited.
Build two temporary trees using identical IDs in different orders.
Compare heights, insertion comparisons, and successful-search totals.

## Limitations
- Records are kept in memory only.
- Enrollment IDs must be positive integers.
- The BST does not rebalance automatically.
- Names and departments support at most 99 bytes each.
