#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void quickSort(int arr[], int low, int high){
    int pivot, temp;

    if(low < high){
        pivot = low;
        int i = low;
        int j = high;

         while (i < j) 
        {
            while (arr[i] <= arr[pivot] && i <= high)
            {
                i++;
            }
            while (arr[j] > arr[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }

    printf("Array after sorting with quick Sort is: ");
    for( int i = 0; i < high + 1; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
    printf("Array after sorting with merge Sort is: ");
    for( int i = 0; i < r + 1; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
} 
  
int main(){
    int arr[MAX], count, opt;
    printf("How many numbers are to be sorted?\n");
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        scanf("%d", &arr[i]);
    }

    while(1 == 1){
        printf("----------Sorting Algorithm Implementation----------\n");
        printf("1.)Merge Sort\n2.)Quick Sort\n3.)Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                mergeSort(arr, 0, count-1);
                break;
            case 2:
                quickSort(arr, 0, count-1);
                break;
            case 3:
                exit(0);
            default:
                printf("Please select a valid choice!!\n");
                break;
        }
    }

}