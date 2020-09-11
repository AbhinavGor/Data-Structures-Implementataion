#include <stdio.h>
#include <stdlib.h>

struct Node 
{ 
    int coeff; 
    int pow; 
    struct Node *next; 
}; 
              
void createNode(int x, int y, struct Node **temp) 
{ 
    struct Node *r, *z; 
    z = *temp; 
    if(z == NULL) 
    { 
        r =(struct Node*)malloc(sizeof(struct Node)); 
        r->coeff = x; 
        r->pow = y; 
        *temp = r; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coeff = x; 
        r->pow = y; 
        // *temp = r; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 
  
void polyAdd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
while(poly1->next && poly2->next) 
    { 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
} 

void polyMul(struct Node *poly1, struct Node *poly2){
    struct Node *ptr1, *ptr2;

    ptr1 = poly1;
    ptr2 = poly2;

    while(ptr1->next != NULL){
        while(ptr2->next != NULL){
            int coe, power;

            coe = ptr1->coeff * ptr2->coeff;
            power = ptr1->pow + ptr2->pow;

            printf("%dx^%d + ", coe, power);

            ptr2 = ptr2->next;
        }

        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    printf("0");

}
  
// Display Linked list 
void display(struct Node *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coeff, node->pow); 
    node = node->next; 
    if(node->next != NULL) 
        printf(" + "); 
    } 
} 

int main(){
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    int opt, data, ord;

    while(1){

        printf("----------Implementation of Polynomial Addition and Multiplication using SLL----------");
        printf("\n1.)Define polynomial A\n2.)Define polynomial B\n3.)Multiply\n4.)Add\n5.)Exit");
        
        printf("\nEnter your choice:\n");
        scanf("%d", &opt);

        if(opt == 1){
            int op;
        
            printf("Highest order\n");
            scanf("%d", &op);
            int arr[op + 1];
            for(int i = 0; i < op + 1; i++){
                printf("Coeff of term with order %d:\t", op - i);
                scanf("%d", &arr[i]);
            }

            for(int i = 0; i < op + 1; i++){
                createNode(arr[i], op-i, &poly1);
            }
            
            printf("1st Polynomial: ");  
            display(poly1); 
            printf("\n");
            
        }else if(opt == 2){
            int op;
        
            printf("Highest order\n");
            scanf("%d", &op);
            int arr[op + 1];
            for(int i = 0; i < op + 1; i++){
                printf("Coeff of term with order %d:\t", op - i);
                scanf("%d", &arr[i]);
            }

            for(int i = 0; i < op + 1; i++){
                createNode(arr[i], op-i, &poly2);
            }
            printf("2nd Polynomial: ");  
            display(poly2); 
            printf("\n");
            
        }else if(opt == 3){
            polyMul(poly1, poly2);
            printf("\n");
            
        }else if(opt == 4){
            poly = (struct Node *)malloc(sizeof(struct Node)); 
            polyAdd(poly1, poly2, poly); 
            printf("\nMultiplied polynomial: "); 
            display(poly); 
            printf("\n");
        }else if(opt == 5){
            exit(0);
        }else{
            printf("Please select a valid choice!!");
        }
            
        }
            return 0; 
    }

