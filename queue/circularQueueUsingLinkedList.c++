#include <iostream>
#include <bits/stdc++.h>

struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*newnode=NULL,*temp=NULL;

void enqueue(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	if(rear==NULL){
		front=newnode;
		rear=newnode;
	}else{
		rear->next=newnode;
		rear=newnode;
	}
	rear->next=front;
}

void dequeue(){
	temp=front;
	if(rear==NULL && front==NULL){
		std::cout<<"Queue is Empty";
	}else if(front==rear){
	 front=NULL;
	 rear=NULL;
	 free(temp);
	}else{
		front=front->next;
		rear->next=front;
		free(temp);
	}
}


void peek(){
	if(front==NULL && rear==NULL){
		std::cout<<"Queue is Empty";
	}else{
		std::cout<<front->data<<"\n";
	}
}

void display(){
	temp=front;
	while(temp->next!=front){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
	std::cout<<temp->data<<"\n";
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice: \n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display";
		std::cin>>choice;
		switch(choice){
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:peek();
			break;
			case 4:display();
			break;
			default:exit(0);
		}
	}
	return 0;
}