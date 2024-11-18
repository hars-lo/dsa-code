#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node {
    int key;
    struct node* l;
    struct node* r;
    int height;
};
                                   
// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of a node
int getheight(struct node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Function to create a new node
struct node* create(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->l = NULL;
    node->r = NULL;
    node->height = 1;  // New node is initially added at leaf
    return node;
}
// Function to get balance factor of node n
int getbalancefactor(struct node* n) {
    if (n == NULL)
        return 0;
    return getheight(n->l) - getheight(n->r);
}

// Right rotate the subtree rooted with y
struct node* rightrotate(struct node* y) {
    struct node* x = y->l;
    struct node* t2 = x->r;

    // Perform rotation
    x->r = y;
    y->l = t2;

    // Update heights
    y->height = max(getheight(y->l), getheight(y->r)) + 1;
    x->height = max(getheight(x->l), getheight(x->r)) + 1;

    // Return new root
    return x;
}

// Left rotate the subtree rooted with y
struct node* leftrotate(struct node* y) {
    struct node* x = y->r;
    struct node* t1 = x->l;

    // Perform rotation
    x->l = y;
    y->r = t1;

    // Update heights
    y->height = max(getheight(y->l), getheight(y->r)) + 1;
    x->height = max(getheight(x->l), getheight(x->r)) + 1;

    // Return new root
    return x;
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree
struct node* insert(struct node* n, int key) {
    // Perform the normal BST insertion
    if (n == NULL)
        return create(key);

    if (key < n->key)
        n->l = insert(n->l, key);
    else if (key > n->key)
        n->r = insert(n->r, key);
    else  // Equal keys are not allowed in BST
        return n;

    // Update the height of this ancestor node
    n->height = 1 + max(getheight(n->l), getheight(n->r));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf = getbalancefactor(n);

    // Left Left Case
    if (bf > 1 && key < n->l->key)
        return rightrotate(n);

    // Right Right Case
    if (bf < -1 && key > n->r->key)
        return leftrotate(n);

    // Left Right Case
    if (bf > 1 && key > n->l->key) {
        n->l = leftrotate(n->l);
        return rightrotate(n);
    }

    // Right Left Case
    if (bf < -1 && key < n->r->key) {
        n->r = rightrotate(n->r);
        return leftrotate(n);
    }

    // Return the (unchanged) node pointer
    return n;
}

// Function to print the tree (in-order traversal)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->key);
        inorder(root->r);
    }
}

int main() {
    struct node* root = NULL;

    // Inserting nodes into the AVL tree
    root = insert(root, 45);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 55);
    root = insert(root, 65);

    // Print in-order traversal of the AVL tree
    printf("In-order traversal of the constructed AVL tree is:\n");
    inorder(root);
    printf("\n");

    return 0;
}
