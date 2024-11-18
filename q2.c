#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void appendNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* countingSort(struct node* head, int exp) {
    struct node* buckets[10] = {NULL};
    struct node* tail[10] = {NULL};

    struct node* temp = head;
    while (temp != NULL) {
        int index = (temp->data / exp) % 10;
        if (buckets[index] == NULL) {
            buckets[index] = createNode(temp->data);
            tail[index] = buckets[index];
        } else {
            tail[index]->next = createNode(temp->data);
            tail[index] = tail[index]->next;
        }
        temp = temp->next;
        
        
    }

    //printList(head);
    //    printList(buckets);
    //    printList(tail);
    //    printf("\n");
    
    struct node* sorted = NULL;
    struct node* last = NULL;
    for (int i = 0; i < 10; i++) {
        if (buckets[i] != NULL) {
            if (sorted == NULL) {
                sorted = buckets[i];
                last = tail[i];
            } else {
                last->next = buckets[i];
                last = tail[i];
            }
        }
    }
    if (last != NULL) {
        last->next = NULL;
    }

    return sorted;
}

int getMax(struct node* head) {
    int max = head->data;
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}
void radixSort(struct node** head) {
    int max = getMax(*head);
    struct node* sorted = *head;
    for (int exp = 1; max / exp > 0; exp *= 10) {
        sorted = countingSort(sorted, exp);
        printf("\nIteration with exp %d: ", exp);
        printList(sorted);
        printf("\n");
    }
    *head = sorted;
}
int main() {
    struct node* head = NULL;
    appendNode(&head, 86);
    appendNode(&head, 48);
    appendNode(&head, 194);
    appendNode(&head, 75);

    appendNode(&head, 85);
    appendNode(&head, 268);

    printf("\nOriginal list: ");
    printList(head);

    radixSort(&head);

    printf("\nSorted list: ");
    printList(head);

    return 0;
}