 #include <stdio.h>


    int main()
    {
 
        int i, n,oper, temp;
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
 
        printf("Which order do you want the numbers to be in?: \n 1.)Ascending.\n");
        printf("2.)Descending.\n");
        printf("\n--------------------\n");
        scanf("%d", &oper);
        switch (oper)
        {
        case 1:
            for(i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(array[j] <array[i])
                    {
                        array[i] = array[i] + array[j];
                        array[j] = array[i] - array[j];
                        array[i] = array[i] - array[j];
                    }
                }
            }
            printf("\nElements of array in sorted ascending order:\n");
            for(i=0; i<n; i++)
            {
                printf("%d  ", array[i]);
            }
            break;
        case 2:
            for(i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(array[j] > array[i])
                    {
                        array[i] = array[i] + array[j];
                        array[j] = array[i] - array[j];
                        array[i] = array[i] - array[j];
                    }
                }
            }
            printf("\nElements of array in sorted descending order:\n");
            for(i=0; i<n; i++)
            {
                printf("%d  ", array[i]);
            }
        };
        printf("\n--------------------\n");
        printf("\n\n OPTIONS: \n1.)To continue press 1.\n2.)To exit press 2. \n");
        scanf("%d", &oper);
        printf("\n--------------------\n");
        }while(oper < 2);

        }