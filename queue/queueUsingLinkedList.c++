#include <iostream>
#include <bits/stdc++.h>

struct node{
	int data;
	struct node *next;
}*front=0,*rear=0,*temp=0;

void enqueue(){
	temp=(struct node*)malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	temp->data=d;
	temp->next=0;
	if(front==0 && rear==0){
		front=temp;
		rear=temp;
	}else{
		rear->next=temp;
		rear=temp;
	}
}

void peek(){
	if(front==0 && rear==0){
		std::cout<<"Underflow";
	}else{
	std::cout<<"Top element is "<<front->data<<"\n";
    }
}

void display(){
	temp=front;
	while(temp!=0){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void dequeue(){
	temp=front;
	if(front==0 || rear==0){
		std::cout<<"Underflow";
	}else{
		front=front->next;
		free(temp);
	}
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display";
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