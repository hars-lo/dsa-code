#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int row,column;
    struct node* next;
};

struct node* createNode(int x ,int r , int c){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->row = r;
    newNode->column = c;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct node** start, int data, int r, int c) {
    struct node* newNode = createNode(data, r, c);
    if (*start == NULL) {
        *start = newNode;
    } else {
        struct node* temp = *start;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(struct node *node) {
    while (node != NULL) {
        printf("%d-> %d-> %d \t", node->data , node->row , node->column);
        node = node->next;
    }
    printf("\n");
}

// struct node* sparseAdd(struct node *heada , struct node *headb){
//     struct node *sum =NULL;
//     struct node *tempa = heada ;
//     struct node *tempb = headb ;
//     while(tempa!=NULL && tempb!=NULL){
//         if(tempa->row == tempb->row){
//             if(tempa->column == tempb->column){
//                 int sum = tempa->data + tempb->data ;
//                 tempa=tempa->next;
//                 tempb=tempb->next;
//             }
//             else if(tempa->column < tempb ->column){
//                 insertNode(&sum,tempa->data,tempa->row,tempa->column);
//                 tempa=tempa->next;
//             }
//             else{
//                 insertNode(&sum,tempb->data,tempb->row,tempb->column);
//                 tempb=tempb->next;
//             }
//         }
//         else{
//             if(tempa->row < tempb->row){
//                 insertNode(&sum,tempa->data,tempa->row,tempa->column);
//                 tempa=tempa->next;
//             }
//             else{
//                 insertNode(&sum,tempb->data,tempb->row,tempb->column);
//                 tempb = tempb->next;
//             }
//         }
//     }

//     return sum;
// }

struct node* sparseAdd(struct node *heada , struct node *headb) {
    struct node *sum = NULL;
    struct node *tempa = heada;
    struct node *tempb = headb;

    while (tempa != NULL && tempb != NULL) {
        if (tempa->row == tempb->row) {
            if (tempa->column == tempb->column) {
                int summedValue = tempa->data + tempb->data;
                if (summedValue != 0) {
                    insertNode(&sum, summedValue, tempa->row, tempa->column);
                }
                tempa = tempa->next;
                tempb = tempb->next;
            } else if (tempa->column < tempb->column) {
                insertNode(&sum, tempa->data, tempa->row, tempa->column);
                tempa = tempa->next;
            } else {
                insertNode(&sum, tempb->data, tempb->row, tempb->column);
                tempb = tempb->next;
            }
        } else {
            if (tempa->row < tempb->row) {
                insertNode(&sum, tempa->data, tempa->row, tempa->column);
                tempa = tempa->next;
            } else {
                insertNode(&sum, tempb->data, tempb->row, tempb->column);
                tempb = tempb->next;
            }
        }
    }

    while (tempa != NULL) {
        insertNode(&sum, tempa->data, tempa->row, tempa->column);
        tempa = tempa->next;
    }

    while (tempb != NULL) {
        insertNode(&sum, tempb->data, tempb->row, tempb->column);
        tempb = tempb->next;
    }

    return sum;
}



int main(){
    int a[7][8]={{0,0,0,0,5,0,0,0},
                 {0,0,4,0,0,0,6,0},
                 {1,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,8,0,0,0,3,0,0},
                 {0,0,0,0,0,0,0,2},
                 {0,0,10,0,7,0,0,0}};

    int b[7][8] = {
    {0, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 7, 0, 0, 0, 1, 0},
    {4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 4, 0, 5, 0, 0},
    {0, 6, 0, 0, 0, 2, 0, 0},
    {0, 0, 9, 0, 0, 0, 0, 3},
    {0, 0, 8, 0, 5, 0, 0, 0}
};


    struct node* heada =NULL;
    struct node* headb = NULL;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(a[i][j]!=0){
                insertNode(&heada,a[i][j],i+1,j+1);
                
            }
            if(b[i][j]!=0){
                insertNode(&headb,b[i][j],i+1,j+1);
            }
        }
        
    }
    printList(heada);
    printList(headb);

    struct node* sum = sparseAdd(heada , headb);
    printf("Hello \n");
    printList(sum);
    
}