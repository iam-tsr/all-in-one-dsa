# Selection Sort Algorithm Implementation in Python

def selection_sort(arr):
    """
    Time Complexity: O(n^2) in all cases
    Space Complexity: O(1) as it is an in-place sorting algorithm
    """

    n = len(arr)
    # Traverse through all array elements
    for i in range(n):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        # Swap the found minimum element with the first element of the unsorted array
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

# Example usage
if __name__ == "__main__":
    sample_array = [64, 25, 12, 22, 11]
    print("Original array:", sample_array)
    sorted_array = selection_sort(sample_array)
    print("Sorted array:", sorted_array)