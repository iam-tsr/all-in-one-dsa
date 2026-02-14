# Linear Search Algorithm Implementation in Python

def linear_search(arr, target):
    """
    This function performs a linear search on the given array to find the target element.
    
    Parameters:
    arr (list): The list in which to search for the target element.
    target: The element to search for in the list.
    
    Returns:
    int: The index of the target element if found, otherwise -1.

    Time Complexity:
    O(n): In the worst case, the target element is not present in the list or is at the end of the list, requiring a full traversal of the list.
    O(1): In the best case, the target element is at the first position of the list.
    O(n): In the average case, the target element is somewhere in the middle of the list, requiring approximately n/2 comparisons.
    """
    for index in range(len(arr)):
        if arr[index] == target:
            return index  # Target found, return its index
    return -1  # Target not found in the array

# Example usage
if __name__ == "__main__":
    my_list = [5, 3, 2, 8, 1]
    target_value = 2
    
    result = linear_search(my_list, target_value)
    
    if result != -1:
        print(f"Element {target_value} found at index: {result}")
    else:
        print(f"Element {target_value} not found in the list.")