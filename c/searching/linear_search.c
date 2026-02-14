// Linear Search
#include <stdio.h>

int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (array[i] == x)
            return i; // Element found, return its index
    }
    return -1; // Element not found
}

int main(void) {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 9;
    int result = linearSearch(array, n, x);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index: %d", result);
    return 0;
}