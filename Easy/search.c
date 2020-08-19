 #include <stdio.h>


    int main()
    {
 
        int i, n, key, res;
        do{        
        printf("Enter the size of an array\n");
        scanf("%d", &n);

        int array[n];
 
        printf("Enter the array elements: \n");
        for (i = 0; i < n; i++) 
        {
            printf("Enter element %d:\n", i + 1);
            scanf("%d", &array[i]);
        }
 
        printf("Enter the key\n");
        scanf("%d", &key);

        for(int i=0; i<n; i++){
            if(array[i] == key){
                res = 1;
                break;
            }else{
                res = 0;
            }
        }

        if(res){
            printf("The key %d is in the array.", key);
        }else{
            printf("The key %d is not in the array.", key);
            printf("%d", res);
        }
        printf("\n--------------------\n");
        printf("\n\n OPTIONS: \n1.)To continue press 1.\n2.)To exit press 2. \n");
        scanf("%d", &key);
        printf("\n--------------------\n");
        }while(key < 2);

        }