#include <iostream>
#include <bits/stdc++.h>
#define N 5

int queue[N];
int rear=-1,front=-1;

void enqueue(){
	std::cout<<"Enter the data";
	int d;
	std::cin>>d;
	if(front==-1 && rear==-1){
		front=0;
		rear=0;
		queue[rear]=d;
	}else if((rear+1)%N==front){
		std::cout<<"Queue is Full";
	}else{
		rear=(rear+1)%N;
		queue[rear]=d;
	}
}

void dequeue(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is Empty";
	}else if(front==rear){
		front=-1;
		rear=-1;
	}else{
		front=(front+1)%N;
	}
}

void peek(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is empty";
	}else{
		std::cout<<queue[front]<<"\n";
	}
}

void display(){
	int i=front;
	while(i<(rear+1)){
		std::cout<<queue[i]<<" ";
		i=(i+1)%N;
	}
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n";
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
		}
	}
	return 0;
}