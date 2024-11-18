#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list                     
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct node* insertNode(struct node* head, int data) {
    struct node* nn = createNode(data);
    if (head == NULL) {
        return nn;
    }
    
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
    return head;
}

// Function to find the maximum value in the linked list
int findMax(struct node* head) {
    int max = head->data;
    struct node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

// Function to get the digit at a specific place value
int getDigit(int number, int place) {
    return ((number / place) % 10);
}

// Function to append one list to another and return the head of the merged list
struct node* appendLists(struct node* list1, struct node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

// Function to perform radix sort on a linked list
struct node* radixSort(struct node* head) {
    if (head == NULL) {
        return head;
    }

    // Find the maximum number to know the number of digits
    int max = findMax(head);

    // Start from the least significant digit (LSD)
    int place = 1;
    while (max / place > 0) {                      
        // Create buckets (linked lists for digits 0-9)
        struct node* buckets[10] = {NULL};

        // Distribute elements into buckets based on current digit
        struct node* temp = head;
        while (temp != NULL) {
        int digit = getDigit(temp->data, place);
            buckets[digit] = insertNode(buckets[digit], temp->data);
            temp = temp->next;
            }
        // Collect elements back into the original list
        head = NULL;
        for (int i = 0; i < 10; i++) {
            head = appendLists(head, buckets[i]);
           // head=buckets[i];
        }

        // Move to the next digit place
        place *= 10;
    }
    
    return head;
}

// Function to display the linked list
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Inserting elements into the linked list
    head = insertNode(head, 170);
    head = insertNode(head, 45);
    head = insertNode(head, 75);
    head = insertNode(head, 90);
    head = insertNode(head, 802);
    head = insertNode(head, 24);
    head = insertNode(head, 2);
    head = insertNode(head, 66);

    printf("Original List: \n");
    display(head);

    // Performing radix sort on the linked list
    head = radixSort(head);

    printf("\nSorted List: \n");
    display(head);

    return 0;
}