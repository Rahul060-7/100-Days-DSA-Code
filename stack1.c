#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
  int data;
  struct Node*next;
}Node;

Node*top=NULL;
void push(int value){
  Node*newNode=(Node*)malloc(sizeof(Node));
  if(newNode==NULL){
    printf("Stack overflow\n");
    return;
  }
  newNode->data=value;
  newNode->next=top;
  top=newNode;
  printf("%d pushed value to stack \n",value);
}
void pop(){
  if(top=NULL){
    printf("Stack underflow\n");
    return;
  }
  Node*temp=top;
  printf("The element popped from stack is %d\n",top->data);
  top=top->next;
  free(temp);
}
void peek(){
  if(top==NULL){
    printf("Stack is empty\n");
  }
  else{
    printf("First element in stack is %d",top->data);
  }
  }
void display(){

  
}