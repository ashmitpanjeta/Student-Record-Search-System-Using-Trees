
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    char dept[50];
    struct Student *left, *right;
};

// Create a new student node
struct Student* create(int id, char name[], char dept[]) {
    struct Student *newNode = malloc(sizeof(struct Student));

    newNode->id = id;
    snprintf(newNode->name, 50, "%s", name);
    snprintf(newNode->dept, 50, "%s", dept);
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Insert student
struct Student* insert(struct Student *root, int id,
                       char name[], char dept[]) {
    if (root == NULL)
        return create(id, name, dept);

    if (id < root->id)
        root->left = insert(root->left, id, name, dept);
    else if (id > root->id)
        root->right = insert(root->right, id, name, dept);
    else
        printf("Duplicate ID not allowed!\n");

    return root;
}

// Search student
void search(struct Student *root, int id) {
    if (root == NULL) {
        printf("Student not found!\n");
        return;
    }

    if (id == root->id) {
        printf("ID: %d\n", root->id);
        printf("Name: %s\n", root->name);
        printf("Department: %s\n", root->dept);
    }
    else if (id < root->id)
        search(root->left, id);
    else
        search(root->right, id);
}

// Find minimum node
struct Student* findMin(struct Student *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete student
struct Student* deleteNode(struct Student *root, int id) {
    if (root == NULL)
        return NULL;

    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else {
        // No child or one child
        if (root->left == NULL) {
            struct Student *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Student *temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        struct Student *temp = findMin(root->right);

        root->id = temp->id;
        snprintf(root->name, 50, "%s", temp->name);
        snprintf(root->dept, 50, "%s", temp->dept);

        root->right = deleteNode(root->right, temp->id);
    }

    return root;
}

// Inorder traversal
void inorder(struct Student *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d %s %s\n", root->id, root->name, root->dept);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct Student *root) {
    if (root != NULL) {
        printf("%d %s %s\n", root->id, root->name, root->dept);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Student *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d %s %s\n", root->id, root->name, root->dept);
    }
}

int main() {
    struct Student *root = NULL;
    int choice, id;
    char name[50], dept[50];

    while (1) {
        printf("\n--- STUDENT RECORD SYSTEM ---\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 1) {
            printf("Enter ID: ");
            scanf("%d", &id);

            printf("Enter Name: ");
            scanf("%49s", name);

            printf("Enter Department: ");
            scanf("%49s", dept);

            root = insert(root, id, name, dept);
        }
        else if (choice == 2) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            search(root, id);
        }
        else if (choice == 3) {
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            root = deleteNode(root, id);
            printf("Deletion completed.\n");
        }
        else if (choice == 4) {
            printf("\nInorder Traversal:\n");
            inorder(root);
        }
        else if (choice == 5) {
            printf("\nPreorder Traversal:\n");
            preorder(root);
        }
        else if (choice == 6) {
            printf("\nPostorder Traversal:\n");
            postorder(root);
        }
        else if (choice == 7) {
            printf("Program ended.\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
