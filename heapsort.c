#include <stdio.h>
#include <conio.h>
#define MAX 256

void heapify(int heap[], int i){
    int j, copy, num, ref = 1;
    num = heap[0];

    while (2*i <= num && ref == 1){
        j = 2*i;
        if(j + 1 <= num && heap[j + 1] > heap[j]){
            j++;
        }
        if(heap[j] < heap[i]){
            ref = 0;
        }else{
            copy = heap[i];
            heap[i] = heap[j];
            heap[j] = copy;
            i = j;
        }
    }
}

void makeHeap(int heap[]){
    int i, ele;
    ele = heap[0];

    for(i = ele/2; i>= 1; i--){
        heapify(heap, i);
    }
}

int main(){
    int heap[MAX], numOfElements, i, lastElement, temp;

    printf("Enter the number of elements to be sorted:");
    scanf("%d", &numOfElements);
    printf("Enter the the elements:\n");
    for( i = 1; i <= numOfElements; i++){
        scanf("%d", &heap[i]);
    }
    heap[0] = numOfElements;

    makeHeap(heap);

    while(heap[0] > 1){
        lastElement = heap[0];
        temp = heap[1];
        heap[1] = heap[lastElement];
        heap[lastElement] = temp;
        heap[0]--;
        heapify(heap, 1);
    }

    printf("Sorted numbers are:\n");
    for(i = 1; i <= numOfElements; i++){
        printf("%d \t", heap[i]);
    }

    return 0;
}