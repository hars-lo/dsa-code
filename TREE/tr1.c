#include<stdio.h>
struct root{
    int data;
    struct root* left;
    struct root* right;
};
struct root* create()
{
    struct root*  node = (struct root*)malloc(sizeof(struct root));
    int x=0;
    node->left=NULL;
    node->right=NULL;
    printf("\nEnter data of  node to be inserted: ");
    scanf("%d",&node->data);
    printf("enter left node of %d and -1  if no left node\n",node->data);
    scanf("%d",&x);
    if(x!=-1)
    {
       node->left=create();
    }
    else{
        return 0;
    }
    



}
int main()
{
    struct root* rot=create();
    return 0;
}