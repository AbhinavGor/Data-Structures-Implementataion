#include<stdio.h>
#include<stdlib.h>

void quickSort(int[], int, int);
void mergeSort(int, int);
void merge(int, int, int, int);
int partition (int[], int, int);
void display(int);
void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int arr[100];
int main(){
    int i, num, ch;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    while(1) {
        printf("----------Sorting Algorithms Implementation----------\n");
        printf("1.)Quick sort\n2.)Merge Sort\n3.)Exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            quickSort(arr, 0, num - 1);
            printf("\nArray after sorting using Quick Sort: ");
            display(num);        
            break;
        case 2:
            mergeSort(0, num - 1);
            printf("\nArray after sorting using Merge Sort: ");
            display(num);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice, enter correct choice...");
        }
    }
    return 0;
}

void display(int num) {
    for(int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void mergeSort(int i,int j) {
    int mid;
    if(i < j) {
        mid = ( i + j ) / 2;
        mergeSort(i, mid); 
        mergeSort(mid + 1, j); 
        merge(i, mid, mid + 1, j); 
    }
}

void merge(int i1, int j1, int i2, int j2) {
    int temp[100]; 
    int i, j, k;
    i = i1; 
    j = i2; 
    k = 0;
    while(i <= j1 && j <= j2) { 
        if(arr[i] < arr[j])
        temp[k++] = arr[i++];
        else
        temp[k++] = arr[j++];
    }
    while(i <= j1) 
        temp[k++] = arr[i++];
    while(j <= j2) 
        temp[k++] = arr[j++];
    for(i = i1, j = 0; i <= j2; i++, j++)
        arr[i] = temp[j];
}