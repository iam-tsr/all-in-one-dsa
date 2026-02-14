# Insertion Sort Algorithm Implementation in Python

def insertion_sort(arr):
    """
    Time Complexity: O(n^2) in the worst and average case, O(n) in the best case
    Space Complexity: O(1) as it is an in-place sorting algorithm
    """

    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Example usage
if __name__ == "__main__":
    sample_array = [12, 11, 13, 5, 6]
    print("Original array:", sample_array)
    sorted_array = insertion_sort(sample_array)
    print("Sorted array:", sorted_array)