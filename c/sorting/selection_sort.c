#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            
        }
        
    }
}

void print(int arr[], int size)
{

    for(int i = 0; i<size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void main(){
    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data)/sizeof(data[0]);

    BubbleSort(data, size);
    print(data, size);
}