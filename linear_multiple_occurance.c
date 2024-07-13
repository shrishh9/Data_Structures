#include <stdio.h>
void linearSearchMultiple(int arr[], int n, int x) {
    int occurrences = 0;
    printf("Indices with occurrence of %d: ", x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            occurrences++;
        }
    }    
    if (occurrences == 0) {
        printf("None\n");
    } else {
        printf("\nTotal occurrences: %d\n", occurrences);
    }
}
int main() {
    int arr[100], n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    linearSearchMultiple(arr, n, x);
    return 0;
}
