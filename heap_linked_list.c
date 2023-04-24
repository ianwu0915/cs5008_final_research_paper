#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void heapify(struct Node* root) {
    if(root == NULL)
        return;

    int largest = root->data;
    struct Node* maxNode = root;

    if(root->left != NULL && root->left->data > largest) {
        largest = root->left->data;
        maxNode = root->left;
    }

    if(root->right != NULL && root->right->data > largest) {
        largest = root->right->data;
        maxNode = root->right;
    }

    if(maxNode != root) {
        int temp = root->data;
        root->data = maxNode->data;
        maxNode->data = temp;

        heapify(maxNode);
    }
}

void insert(struct Node** root, int value) {
    if(*root == NULL) {
        *root = createNode(value);
        return;
    }

    struct Node* newNode = createNode(value);

    if((*root)->left == NULL) {
        (*root)->left = newNode;
        heapify(*root);
    }
    else if((*root)->right == NULL) {
        (*root)->right = newNode;
         heapify(*root);
    }
    else {
        if((*root)->left->left == NULL || (*root)->left->right == NULL)
            insert(&(*root)->left, value);
        else
            insert(&(*root)->right, value);
    }
}

int getHeight(struct Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int removeMax(struct Node** root) {
    if(*root == NULL) {
        printf("Heap is empty.\n");
        return -1;
    }

    // Find the rightmost node in the deepest level of the heap
    struct Node* parent = NULL;
    struct Node* current = *root;
    while(current->right != NULL) {
        parent = current;
        if(getHeight(current->left) == getHeight(current->right)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    int maxVal = current->data;
    if(parent != NULL) {
        if(parent->right == current) {
            parent->right = NULL;
        } else {
            parent->left = NULL;
        }
    }


    // Move the value of the rightmost node to the root
    (*root)->data = maxVal;

    if(parent != NULL) {
        heapify(parent);
    } else {
        heapify(*root);
    }

    heapify(*root);
    free(current);

    return maxVal;
}


void freeHeap(struct Node* root) {
    if(root == NULL) {
        return;
    }

    freeHeap(root->left);
    freeHeap(root->right);
    free(root);
}



void BFS_traverse(struct Node* root) {
    if(root == NULL)
        return;

    // Initialize a queue for the nodes in the heap
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear] = root;
    rear++;

    // Traverse the heap in level-order (BFS) and print out the node values
    while(front != rear) {
        struct Node* current = queue[front];
        printf("%d ", current->data);
        front++;

        if(current->left != NULL) {
            queue[rear] = current->left;
            rear++;
        }

        if(current->right != NULL) {
            queue[rear] = current->right;
            rear++;
        }
    }
    printf("\n");
}



int main() {
    struct Node* root = NULL;

    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 20);

    printf("Max heap: ");
    BFS_traverse(root);

    removeMax(&root);
    BFS_traverse(root);
    // removeMax(&root);
    // BFS_traverse(root);

    return 0;
}
