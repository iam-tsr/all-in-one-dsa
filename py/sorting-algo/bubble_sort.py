# Bubble Sort Algorithm Implementation in Python

def bubble_sort(arr):
    """
    Time Complexity: O(n^2) in the worst and average case, O(n) in the best case
    Space Complexity: O(1) as it is an in-place sorting algorithm
    """

    n = len(arr)
    # Traverse through all elements in the array
    for i in range(n):
        # Last i elements are already in place, no need to check them
        for j in range(0, n-i-1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

# Example usage
if __name__ == "__main__":
    sample_array = [64, 34, 25, 12, 22, 11, 90]
    print("Original array:", sample_array)
    sorted_array = bubble_sort(sample_array)
    print("Sorted array:", sorted_array)