#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
char data[1];
struct node *prev;
};
struct node *top=NULL;
void push(char *item){
struct node *box= (struct node*)malloc(sizeof(struct node));
box->data[0]=item[0];
box->prev=top;
top=box;
}
char pop(){
if(top==NULL)
return '\0';
struct node *temp=top;
top=top->prev;
return temp->data[0];
}
struct intNode{
int data;
struct intNode *prev;
};
struct intNode *intTop=NULL;
void intPush(int item){
struct intNode *box= (struct intNode*)malloc(sizeof(struct intNode));
box->data=item;
box->prev=intTop;
intTop=box;
}
int intPop(){
if(intTop==NULL)
return -1;
else{
int data=intTop->data;
intTop=intTop->prev;
return data;
}
}
char postfix[1000];
void infixToPostfix(char *smth){
int i=0;
postfix[0]='\0';
for(int i=0; i<strlen(smth) ;i++){
struct node *temp=top;
char ne=smth[i];
if(smth[i]=='+' | smth[i]=='-' | smth[i]=='*' | smth[i]=='/' | smth[i]=='(' |
smth[i]==')' | smth[i]=='^'){
if(top==NULL){
push(&ne);
}
if(ne=='('){
push(&ne);
}
if(ne==')'){
do{
if(temp->data[0]!='('){
strcat(postfix,(temp->data));
pop();
temp=temp->prev;
}
else{
pop();
break;
}
}while(1);
}
if(ne=='^'){
do{
if(temp->data[0]=='^'){
strcat(postfix,(temp->data));
pop();
temp=temp->prev;
}
else{
push(&ne);
break;
}
}while(1);
}
if(ne=='*' | ne=='/'){
do{
if(temp->data[0]=='^' | temp->data[0]=='*' | temp->data[0]=='/'){
strcat(postfix,(temp->data));
pop();
temp=temp->prev;
}
else{
push(&ne);
break;
}
}while(1);
}
if(ne=='+' | ne=='-'){
do{
if(temp->data[0]=='^' | temp->data[0]=='*' | temp->data[0]=='/' | temp->data[0]=='+' | temp->data[0]=='-'){
strcat(postfix,temp->data);
pop();
temp=temp->prev;
}
else{
push(&ne);
break;
}
}while(1);
}
}
else{
int len= strlen(postfix);
postfix[len]=ne;
}
}
}
void analyze(){
top=NULL;
for(int i=0; i<strlen(postfix); i++){
if(postfix[i]=='+' | postfix[i]=='-' | postfix[i]=='*' | postfix[i]=='/' |
postfix[i]=='^'){
int num1= intPop();
int num2= intPop();
if(postfix[i]=='+'){
intPush(num1+num2);
}
if(postfix[i]=='-'){
intPush(num2-num1);
}
if(postfix[i]=='*'){
intPush(num1*num2);
}
if(postfix[i]=='/'){
intPush(num2/num1);
}
}
else{
int num= postfix[i]-'0';
intPush(num);
}
}
printf("%d",intPop());
}
int main(){
char smth[100];
int choice;
printf("Enter an equation enclosed in paranthesis and single digits\nEquation: ");
scanf("%[^\n]",smth);
printf("Enter\n1-Postfix equation (for variables)\n2-Answer (for numbers)\n");
scanf("%d", &choice);
if(choice==1){
infixToPostfix(smth);
printf("Postfix equation: %s\n", postfix);
}
if(choice==2){
infixToPostfix(smth);
printf("Postfix equation: %s\n", postfix);
analyze();
}
return 0;
}