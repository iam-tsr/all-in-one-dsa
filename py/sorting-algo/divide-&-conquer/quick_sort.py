# Quick Sort implementation in Python

def quick_sort(arr):
    """
    Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the smallest or largest element is always chosen as pivot)
    Space Complexity: O(n) due to the recursive calls
    """

    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]  # Choosing the middle element as pivot
        left = [x for x in arr if x < pivot]  # Elements less than pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to pivot
        right = [x for x in arr if x > pivot]  # Elements greater than pivot
        return quick_sort(left) + middle + quick_sort(right)  # Recursively sort and combine
    
# Example usage
if __name__ == "__main__":
    sample_array = [38, 27, 43, 3, 9, 82, 10]
    print("Unsorted array:", sample_array)
    sorted_array = quick_sort(sample_array)
    print("Sorted array:", sorted_array)