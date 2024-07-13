#include <stdio.h>
int binarySearchIterative(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return binarySearchRecursive(arr, mid + 1, right, x);
        return binarySearchRecursive(arr, left, mid - 1, x);
    }
    return -1;
}
int main() {
    int arr[100], n, x, choice, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    printf("Choose the search algorithm:\n");
    printf("1. Binary search with iteration\n");
    printf("2. Binary search with recursion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            result = binarySearchIterative(arr, n, x);
            break;
        case 2:
            result = binarySearchRecursive(arr, 0, n - 1, x);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    if (result == -1) {
        printf("Element is not present in the array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}
