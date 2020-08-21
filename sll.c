#include<stdio.h>
#include<stdlib.h>

int len=0;

struct node{
	int data;
	struct node* next; 
}*list=NULL;

struct node* createNode(){
	struct node* box= (struct node*)malloc(sizeof(struct node));
	box->data=0;
	box->next=NULL;
	return box;
}

void bInsert(int data){

	struct node* n1=createNode();
	n1->data=data;

	if(list==NULL && len==0){
		list=n1;
	}
	else{
		n1->next=list;
		list=n1;
	}
	len++;
}

void endInsert(int data){

	struct node* n1=createNode(), *n2=list;
	n1->data=data;


	if(list==NULL && len==0){
		list=n1;
	}
	else{
		while(n2->next){
			n2=n2->next;
		}
		n2->next=n1;
	}
	len++;
}

void posInsert(int data,int pos){
	if(len==0 || pos<=0 || pos>=len){printf("Invalid request!\n");return;}

	struct node* n1=createNode(), *n2=list;
	n1->data=data;
	int counter=0;

	while(counter!=pos-1){
		counter++;
		n2=n2->next;
	}
	n1->next=n2->next;
	n2->next=n1;

	len++;
}

void beginDelete(){
	if(len==0 && list==NULL){
		printf("No elements found!\n");
		return;
	}
    printf("%d is deleted!\n",list->data);
	list=list->next;
	len--;
}

void endDelete(){
	if(len==0 && list==NULL){
		printf("No elements found!\n");
		return;
	}
	if(len==1){beginDelete(); return;}

	struct node *temp=list;
	while((temp->next)->next){
		temp=temp->next;
	}
    printf("%d is deleted!\n",(temp->next)->data);
	temp->next=NULL;
	len--;
}

void posDelete(int pos){
	if(len==0 || pos<=0 || pos>=len-1){printf("Invalid request!\n");return;}	

	struct node *n1=list;
	int counter=0;

	while(counter!=pos-1){
		counter++;
		n1=n1->next;
	}
    printf("%d is deleted!\n",(n1->next)->data);
	n1->next=(n1->next)->next;
	len--;
}


void display(){
	if(len==0 && list==NULL){printf("Invalid request!\n");return;}

	struct node* n1=list;
	printf("Start\n");
	while(n1){
		printf("%d ",n1->data);
		n1=n1->next;
	}
	printf("\nEnd\n");
}

void search(int val){

	struct node* n1=list;
	int counter=0;
	while(n1){
		if(n1->data==val){
			printf("Value resides at %d\n", counter);
			return;
		}
		n1=n1->next;
		counter++;
	}
	printf("Element not found!\n");
}


int main(){
    int oper, data, pos;

    while(1){
        printf("-----------Implementation of Singly Linked List using C Language ----------\n");
        printf("1.) Beginning insert\n");
        printf("2.) End insert\n");
        printf("3.) Position insert\n");
        printf("4.) Beginning Deletion\n");
        printf("5.) End Deletion\n");
        printf("6.) Position Deletion\n");
        printf("7.) Search\n");
        printf("8.) Display\n");
        printf("9.) Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &oper);

        switch (oper)
        {
        case 1:
            printf("Enter the integer to be added to the list: \n");
            scanf("%d", &data);
            bInsert(data);
            break;
        
        case 2:
            printf("Enter the integer to be added to the list: \n");
            scanf("%d", &data);
            endInsert(data);
            break;
        case 3:
            printf("Enter the integer to be added to the list: \n");
            scanf("%d", &data);
            printf("Enter the position where the integer is to be added to the list: \n");
            scanf("%d", &pos);
            posInsert(data, pos);
            break;

        case 4:
            beginDelete();
            break;
        
        case 5:
            endDelete();
            break;
        case 6:
            printf("Enter the position where the integer is to be deleted from the list: \n");
            scanf("%d", &pos);
            posDelete(pos);
            break;
                
        case 7:
            printf("Enter the element to be searched in the list: \n");
            scanf("%d", &data);
            search(data);
            break;

        case 8:
            display();
            break;
        
        case 9:
            printf("Exiting from the program!!");
            return 0;
        
        default:
            printf("Invalid choice!");
            break;
        }
    }
}
