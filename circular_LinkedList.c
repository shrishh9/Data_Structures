#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the circular linked list
struct node {
    int data;
    struct node *next;
};

// Head of the circular linked list
struct node *head = NULL;

// Function prototypes
void insertAtBeg();
void insertAtEnd();
void beginDelete();
void lastDelete();
void search();
void display();

int main() {
    int choice = 0;

    while (choice != 7) {
        printf("\n\n********* Main Menu *********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert in beginning\n");
        printf("2. Insert at last\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from last\n");
        printf("5. Search for an element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtBeg();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                beginDelete();
                break;
            case 4:
                lastDelete();
                break;
            case 5:
                search();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeg() {
    struct node *ptr, *temp;
    int data;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nMemory allocation failed.\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &data);
        ptr->data = data;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            ptr->next = head;
            head = ptr;
            temp->next = head;
        }

        printf("\nNode inserted.\n");
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd() {
    struct node *ptr, *temp;
    int data;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nMemory allocation failed.\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &data);
        ptr->data = data;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }

        printf("\nNode inserted.\n");
    }
}

// Function to delete a node from the beginning of the circular linked list
void beginDelete() {
    struct node *ptr;

    if (head == NULL) {
        printf("\nList is empty\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted from the beginning.\n");
    } else {
        ptr = head;
        struct node *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        head = head->next;
        temp->next = head;
        free(ptr);

        printf("\nNode deleted from the beginning.\n");
    }
}

// Function to delete a node from the end of the circular linked list
void lastDelete() {
    struct node *ptr, *preptr;

    if (head == NULL) {
        printf("\nList is empty\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted from the last.\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        free(ptr);

        printf("\nNode deleted from the last.\n");
    }
}

// Function to search for an element in the circular linked list
void search() {
    struct node *ptr;
    int item, flag = 0, pos = 0;

    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        printf("\nEnter value to search: ");
        scanf("%d", &item);

        ptr = head;
        do {
            pos++;
            if (ptr->data == item) {
                printf("\nItem found at position %d\n", pos);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != head);

        if (flag == 0) {
            printf("\nItem not found in the list\n");
        }
    }
}

// Function to display the elements of the circular linked list
void display() {
    struct node *ptr;

    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        ptr = head;
        printf("\nThe list is:\n");

        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);

        printf("\n");
    }
}
