#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

struct node *new_node(int item){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = item;
    temp->leftchild = NULL;
    temp->rightchild = NULL;
    return temp;
}

struct node *insert(struct node *rootnode, int item){
    if(rootnode==NULL){
        return new_node(item);
    }else if(item < rootnode->data ){
        rootnode->leftchild = insert(rootnode->leftchild,item);
    }else{
        rootnode->rightchild = insert(rootnode->rightchild,item);
    }
    return rootnode;
}


struct node *search(struct node *rootnode,int item){
    if(rootnode==NULL || rootnode->data == item){
        return rootnode;
    }else if(rootnode->data > item){
        return search(rootnode->leftchild,item);
    }else{
        return search(rootnode->rightchild, item);
    }
}

struct node* find_minimum(struct node *root){
    if(root==NULL){
        return NULL;
    }else if(root->leftchild!=NULL){
        return find_minimum(root->leftchild);
    }
    return root;
}

struct node *delete(struct node *rootnode,int item){
    if(rootnode==NULL){
        return rootnode;
    }

    if(rootnode->data > item){
        rootnode->leftchild = delete(rootnode->leftchild,item);
    }else if(rootnode->data < item){
        rootnode->rightchild = delete(rootnode->rightchild,item);
    }else{
        // No children 
        if(rootnode->leftchild == NULL && rootnode->rightchild == NULL){
            free(rootnode);
            return NULL;
        }else if(rootnode->leftchild == NULL || rootnode->rightchild == NULL){
            struct node *temp;
            if(rootnode->leftchild == NULL){
                temp = rootnode->rightchild;
            }else{
                temp = rootnode->leftchild;
            }
             free(rootnode);
            return temp;
        }
        else{
            struct node *temp =    find_minimum(rootnode->rightchild);
            rootnode->data = temp->data;
            rootnode->rightchild =delete(rootnode->rightchild,temp->data);
        }
    }
    return rootnode;
}



void inorder_traversal(struct node *root){
    if(root!=NULL){
        inorder_traversal(root->leftchild);
        printf("%d ",root->data);
        inorder_traversal(root->rightchild);
    }
}

void preorder_traversal(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder_traversal(root->leftchild);
        preorder_traversal(root->rightchild);
    }
}

void post_traversal(struct node *root){
    if(root!=NULL){
        post_traversal(root->leftchild);
        post_traversal(root->rightchild);
        printf("%d ",root->data);
    }
}



int main(){
   struct node* rootnode = NULL;
   rootnode = insert(rootnode,10);
   insert(rootnode,20);
   insert(rootnode,15);
   insert(rootnode,23);
   insert(rootnode,25);
   insert(rootnode,30);
   insert(rootnode,38);

   printf("inorder :\n");
   inorder_traversal(rootnode);
   printf("\n");

   printf("preoder :\n");
   preorder_traversal(rootnode);
   printf("\n");

   printf("postorder :\n");
   post_traversal(rootnode);
   printf("\n");
 
  struct node* val = search(rootnode, 23);
  if(val!=NULL){
  printf("Founded : %d\n",val->data);
  }else{
    printf("Not founded");
  }

  struct node* new_rootnode = delete(rootnode,30);
  printf("inorder :\n");
   inorder_traversal(new_rootnode);
   printf("\n");

}