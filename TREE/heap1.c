#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task with priority
typedef struct {
    int task_id;
    int priority;
} Task;

// Swap function to swap two tasks
void swap(Task *x, Task *y) {
    Task temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(Task heap[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && heap[left].priority > heap[largest].priority)
        largest = left;

    // If right child is larger than largest so far
    if (right < n && heap[right].priority > heap[largest].priority)
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        // Recursively heapify the affected sub-tree
        heapify(heap, n, largest);
    }
}

// Function to add a task to the heap
void add_task(Task heap[], Task new_task, int *n) {
    (*n)++; // Increase heap size
    int i = *n - 1;
    heap[i] = new_task; // Insert new task at the end

    // Fix the max heap property if it is violated
    while (i != 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to execute and remove the highest priority task
Task execute_next_task(Task heap[], int *n) {
    if (*n <= 0) {
        printf("No tasks to execute.\n");
        Task empty = {-1, -1};
        return empty;
    }

    // Highest priority task is at the root
    Task root = heap[0];

    // Replace root with the last task and reduce heap size
    heap[0] = heap[*n - 1];
    (*n)--;

    // Heapify the root
    heapify(heap, *n, 0);

    return root;
}

// Function to print the task list in the heap
void print_tasks(Task heap[], int n) {
    printf("Tasks in the executor:\n");
    for (int i = 0; i < n; i++) {
        printf("Task ID: %d, Priority: %d\n", heap[i].task_id, heap[i].priority);
    }
}

int main() {
    Task heap[100]; // Task heap (max size of 100)
    int n = 0;      // Current number of tasks in the heap

    // Add tasks with different priorities
    add_task(heap, (Task){1, 5}, &n);  // Task 1 with priority 5
    add_task(heap, (Task){2, 10}, &n); // Task 2 with priority 10
    add_task(heap, (Task){3, 3}, &n);  // Task 3 with priority 3
    add_task(heap, (Task){4, 8}, &n);  // Task 4 with priority 8

    print_tasks(heap, n); // Print all tasks

    // Execute the next task (highest priority)
    Task next_task = execute_next_task(heap, &n);
    printf("\nExecuted Task ID: %d, Priority: %d\n", next_task.task_id, next_task.priority);

    print_tasks(heap, n); // Print remaining tasks

    return 0;
}
