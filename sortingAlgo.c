#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void insertionSort(int arr[], int count){
    for(int i = 1; i <= count - 1; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }

    printf("Sorted list in ascending order: ");
    for(int i = 0; i < count; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int count){
    for(int i =0; i < count - 1; i++){
        for(int j = 0; j< count - i - 1; j++){
            if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
            }
        }
    }

    printf("Array after sorting with bubbleSort is: ");
    for( int i = 0; i < count; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int count){
    for(int i = 0; i < count - 1; i++){
        int temp = i;
        for(int j = i + 1; j < count; j++){
            if(arr[temp] > arr[j]){
                temp = j;
            }
        }
        if(temp != i){
            int var = arr[i];
            arr[i] = arr[temp];
            arr[temp] = arr[i];
        }
    }

    printf("Array after sorting with selectionSort is: ");
    for( int i = 0; i < count; i++){
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
        printf("1.)Insertion Sort\n2.)Bubble Sort\n3.)Selection Sort\n4.)Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                insertionSort(arr, count);
                break;
            case 2:
                bubbleSort(arr, count);
                break;
            case 3:
                selectionSort(arr, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Please select a valid choice!!\n");
                break;
        }
    }

    return 0;

}