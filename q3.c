// #include <stdio.h>
// #include <stdlib.h>

// // Define the node structure for the linked list
// typedef struct Node {
//     int data;
//     int priority;
//     struct Node* next;
// } Node;

// // Function to create a new node
// Node* newNode(int d, int p) {
//     Node* temp = (Node*)malloc(sizeof(Node));
//     temp->data = d;
//     temp->priority = p;
//     temp->next = NULL;
//     return temp;
// }

// // Function to check if the queue is empty
// int isEmpty(Node* head) {
//     return head == NULL;
// }

// // Function to insert a new node according to its priority
// void push(Node** head, int d, int p) {
//     Node* start = *head;
//     Node* temp = newNode(d, p);

//     // Special case: The head node has a lower priority than the new node
//     if (isEmpty(*head) || (*head)->priority > p) {
//         temp->next = *head;
//         *head = temp;
//     } else {
//         // Traverse the list to find the correct position to insert the new node
//         while (start->next != NULL && start->next->priority <= p) {
//             start = start->next;
//         }
//         temp->next = start->next;
//         start->next = temp;
//     }
// }

// // Function to remove the highest priority node
// void pop(Node** head) {
//     if (!isEmpty(*head)) {
//         Node* temp = *head;
//         *head = (*head)->next;
//         free(temp);
//     }
// }

// // Function to return the value at the head of the queue
// int peek(Node* head) {
//     if (!isEmpty(head)) {
//         return head->data;
//     } else {
//         return -1; // Queue is empty
//     }
// }

// // Function to display the queue
// void display(Node* head) {
//     while (head != NULL) {
//         printf("Data: %d, Priority: %d\n", head->data, head->priority);
//         head = head->next;
//     }
// }

// int main() {
//     Node* pq = NULL;

//     // Adding elements to the priority queue
//     push(&pq, 10, 2);
//     push(&pq, 14, 4);
//     push(&pq, 16, 1);
//     push(&pq, 12, 3);

//     // Display the priority queue
//     printf("Priority Queue:\n");
//     display(pq);

//     // Remove the highest priority element
//     pop(&pq);
    
//     // Display the priority queue after pop
//     printf("\nPriority Queue after popping the highest priority element:\n");
//     display(pq);

//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int pri;
    struct node* next;
}node;
node* create(int d,int p)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->pri=p;
    temp->next=NULL;
    return temp;
}
int peek(node* head)
{
    return head->data;
}
node* pop(node* q)
{
    node* t=q;
    q=q->next;
    free(t);
    return q;
}
node* push(node* q,int d,int p)
{
    node* pt=q;
    node* t=create(d,p);
    if(q->pri > p)
    {
        t->next=q;
        q=t;
    }
     else {
        while (pt->next != NULL &&   pt->next->pri < p) {
            pt = pt->next;
        }
        t->next = pt->next; //insertion b/w two elements
        pt->next = t;
    }
    return q;
   
   
}
int isEmpty(node* head)
{
    return (head == NULL);
}
int main()
{
   node* q = create(4, 1);
    q = push(q, 5, 2);
    q = push(q, 6, 3);
    q = push(q, 7, 0);

    while (!isEmpty(q)) {
        printf("%d ", peek(q));
        q = pop(q);
    }
    return 0;
}
