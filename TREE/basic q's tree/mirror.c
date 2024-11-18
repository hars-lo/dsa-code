/*
#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    int x;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("  Enter Data (enter -1 for no node): ");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    new->data=x;
    printf("\nEnter the left child of %d",x);
    new->left=create();
    printf("\nEnter right side of %d",x);
    new->right=create();
    return new;
}
struct node* mirror(struct node* root)
{
    struct node* ans=root;
    if(root==NULL)
    {
        return NULL;
    }
    struct node* mirrorleft=mirror(root->left);
    struct node* mirrorright=mirror(root->right);
    root->left=mirrorright;
    root->right=mirrorleft;
    
    return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d\t",root->data);
    inorder(root->right);
}
main()
{
    struct node* root1=create();
   struct node* root2;
   root2= mirror(root1);
   inorder(root1);
   printf("\n");
   inorder(root2);
} */
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* mirrorTree(struct node* root) {
    if (root == NULL) {
        return NULL; 
    }
    struct node* mirroredLeft = mirrorTree(root->left);
    struct node* mirroredRight = mirrorTree(root->right);
    root->left = mirroredRight;
    root->right = mirroredLeft;
    return root;
}
void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Original tree (inorder traversal): ");
    inorderTraversal(root);
    printf("\n");
    struct node* mirroredRoot = mirrorTree(root);
    printf("Mirrored tree (inorder traversal): ");
    inorderTraversal(mirroredRoot);
    printf("\n");
    return 0;
}
