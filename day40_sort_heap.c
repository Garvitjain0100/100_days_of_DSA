/* Implement Heap Sort using a Max Heap to sort an array in ascending order. 
First build a max heap, then repeatedly extract the maximum element and place it at the end of the array. */
#include <stdio.h>
#define MAX 1000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice;

    while (1) {
        printf("\n1.Enter Array\n2.Heap Sort\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter elements:\n");
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                break;

            case 2:
                if (n == 0) {
                    printf("Array not initialized\n");
                } else {
                    heapSort(arr, n);
                    printf("Sorted using Heap Sort\n");
                }
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}