#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the doubly linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Head of the doubly linked list
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

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeg() {
    struct node *ptr;
    int data;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nMemory allocation failed.\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &data);
        ptr->data = data;
        ptr->next = head;
        ptr->prev = NULL;

        if (head != NULL) {
            head->prev = ptr;
        }
        head = ptr;
        printf("\nNode inserted.\n");
    }
}

// Function to insert a node at the end of the doubly linked list
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
        ptr->next = NULL;

        if (head == NULL) {
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }

        printf("\nNode inserted.\n");
    }
}

// Function to delete a node from the beginning of the doubly linked list
void beginDelete() {
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node *ptr = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(ptr);
        printf("\nNode deleted from the beginning.\n");
    }
}

// Function to delete a node from the end of the doubly linked list
void lastDelete() {
    if (head == NULL) {
        printf("\nList is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nNode deleted.\n");
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("\nNode deleted from the last.\n");
    }
}

// Function to search for an element in the doubly linked list
void search() {
    if (head == NULL) {
        printf("\nEmpty List\n");
    } else {
        int data, flag = 0, position = 0;
        printf("\nEnter data to search: ");
        scanf("%d", &data);
        struct node *temp = head;
        while (temp != NULL) {
            position++;
            if (temp->data == data) {
                printf("Data found at location %d\n", position);
                flag = 1;
            }
            temp = temp->next;
        }
        if (flag == 0) {
            printf("Data not found\n");
        }
    }
}

// Function to display the elements of the doubly linked list
void display() {
    if (head == NULL) {
        printf("\nNothing to print\n");
    } else {
        printf("\nPrinting values:\n");
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
