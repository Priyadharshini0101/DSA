#include <bits/stdc++.h>
#include  <iostream>

struct node{
	int data;
	struct node *next;
}*top=NULL,*newnode=NULL;

void push(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=d;
	if(top==NULL){
		newnode->next=0;
	}else{
		newnode->next=top;
	}
	top=newnode;
}

void pop(){
	struct node *temp;
	if(top==NULL){
		std::cout<<"Stack is Empty";
	}else{
		temp=top;
		top=temp->next;
		free(temp);
	}
}

void display(){
	struct node *temp=top;
	while(temp->next!=0){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
	std::cout<<temp->data<<"\n";
}

void peek(){
	if(top==NULL){
		std::cout<<"Stack is Empty";
	}else{
		std::cout<<top->data<<"\n";
	}
}

int main(){
	int choice;
	while(1){
    std::cout<<"Enter your choice:\n1.Push\n2.Pop\n3.Display\n4.Peek\n";	
	std::cin>>choice;
	switch(choice){
		case 1:push();
		break;
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:peek();
		break;
		default:exit(0);
	}
  }
  return 0;
}