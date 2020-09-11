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
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 
  
void polyAdd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
while(poly1->next && poly2->next) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
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

void removeDup(struct Node* start){
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while(ptr1 != NULL && ptr1->next != NULL ){
        ptr2 = ptr1;

        while(ptr2->next != NULL){
            if(ptr2->pow == ptr2->next->pow){
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
            }else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void polyMul(struct Node *poly1, struct Node *poly2){
    struct Node *ptr1, *ptr2;

    ptr1 = poly1;
    ptr2 = poly2;

    while(ptr1->next != NULL){
        // printf("Poly 1 coeff: %d, pow: %d\n", ptr1->coeff, ptr1->pow);
        while(ptr2->next != NULL){
            int coe, power;

            coe = ptr1->coeff * ptr2->coeff;
            power = ptr1->pow + ptr2->pow;

            printf("%dx^%d + ", coe, power);

            // printf("Poly 1 coeff: %d, pow: %d\n", ptr1->coeff, ptr1->pow);
            // printf("Poly 2 coeff: %d, pow: %d\n", ptr2->coeff, ptr2->pow);

            // createNode(coe, power, &res);

            ptr2 = ptr2->next;
        }

        ptr2 = poly2;
        ptr1 = ptr1->next;
        // if(ptr2->next == NULL && ptr1->next == NULL){
        //     exit(1);
        // }
    }
    printf("0");
    // removeDup(poly);

}
  
// Display Linked list 
void show(struct Node *node) 
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

    // Create first list of 5x^2 + 4x^1 + 2x^0 
    createNode(5,2,&poly1); 
    createNode(4,1,&poly1); 
    createNode(2,0,&poly1); 
      
    // Create second list of 5x^1 + 5x^0 
    createNode(5,1,&poly2); 
    createNode(5,0,&poly2); 
      
    printf("1st Number: ");  
    show(poly1); 
      
    printf("\n2nd Number: "); 
    show(poly2); 
      
    poly = (struct Node *)malloc(sizeof(struct Node)); 
      
    // Function add two polynomial numbers 
    polyAdd(poly1, poly2, poly); 
      
    // Display resultant List 
    printf("\nAdded polynomial: "); 
    show(poly); 

    printf("\nMultiplied polynomial: "); 
    polyMul(poly1, poly2); 
    
    return 0; 
}