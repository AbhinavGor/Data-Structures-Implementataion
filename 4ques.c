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

void beginInsert(int num){

	struct node* temp1=createNode();
	temp1->data=num;

	if(list==NULL && len==0){
		list=temp1;
	}
	else{
		temp1->next=list;
		list=temp1;
	}
	len++;
}

void endInsert(int num){

	struct node* temp1=createNode(), *temp2=list;
	temp1->data=num;


	if(list==NULL && len==0){
		list=temp1;
	}
	else{
		while(temp2->next){
			temp2=temp2->next;
		}
		temp2->next=temp1;
	}
	len++;
}

void middleInsert(int num,int pos){
	if(len==0 || pos<=0 || pos>=len){printf("Invalid request!\n");return;}

	struct node* temp1=createNode(), *temp2=list;
	temp1->data=num;
	int counter=0;

	while(counter!=pos-1){
		counter++;
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;

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

void middleDelete(int pos){
	if(len==0 || pos<=0 || pos>=len-1){printf("Invalid request!\n");return;}	

	struct node *temp1=list;
	int counter=0;

	while(counter!=pos-1){
		counter++;
		temp1=temp1->next;
	}
    printf("%d is deleted!\n",(temp1->next)->data);
	temp1->next=(temp1->next)->next;
	len--;
}


void display(){
	if(len==0 && list==NULL){printf("Invalid request!\n");return;}

	struct node* temp1=list;
	printf("Start\n");
	while(temp1){
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
	printf("\nEnd\n");
}

void search(int val){

	struct node* temp1=list;
	int counter=0;
	while(temp1){
		if(temp1->data==val){
			printf("Value resides at %d\n", counter);
			return;
		}
		temp1=temp1->next;
		counter++;
	}
	printf("Element not found!\n");
}


int main(){

	while(1){
		int choice;
		printf("1-Search\n2-Insert\n3-Delete\n4-Display\nAnything else to exit\n");
		scanf("%d",&choice);

		if(choice==1){
			int item;
			scanf("%d", &item);
			search(item);
		}

		else if(choice==2){
			printf("1-Begin\n2-End\n3-Middle\n");
			scanf("%d",&choice);
			int item;
			printf("Item: ");
			scanf("%d", &item);
			if(choice==1){
				beginInsert(item);
			}
			else if(choice==2){
				endInsert(item);
			}
			else if(choice==3){
				printf("Position: ");
				int pos;
				scanf("%d",&pos);
				middleInsert(item, pos);
			}
		}


		else if(choice==3){
			printf("1-Begin\n2-End\n3-Middle\n");
			scanf("%d",&choice);
			if(choice==1){
				beginDelete();
			}
			else if(choice==2){
				endDelete();
			}
			else if(choice==3){
				printf("Position: ");
				int pos;
				scanf("%d",&pos);
				middleDelete(pos);
			}
		}

		else if(choice==4){
			display();
		}
		else{
			break;
		}
	}
}
