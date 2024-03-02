#include <iostream>
#include <bits/stdc++.h>

#define N 5
int queue[N];
int front=-1,rear=-1;

void enqueueFront(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	if((front==rear+1) || (front==0 && rear==N-1)){
		std::cout<<"Queue is Full";
	}else if(front==-1 && rear==-1){
		front=0;
		rear=0;
		queue[front]=d;
	}else if(front==0){
		front=N-1;
		queue[front]=d;
	}else{
		front--;
		queue[front]=d;
	}
}

void enqueueRear(){
	int  d;
	std::cout<<"Enter the data";
	std::cin>>d;
	if((front==rear+1) || (front==0 && rear==N-1)){
		std::cout<<"Queue is Full";
	}else if(front==-1 && rear==-1){
		front=0;
		rear=0;
		queue[rear]=d;
	}else if(rear==N-1){
		rear=0;
		queue[rear]=d;
	}else{
		rear++;
		queue[rear]=d;
	}
}

void dequeueFront(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is Empty";
	}else if(front==rear){
		front=-1;
		rear=-1;
	}else if(front==N-1){
		   front=0;
	}else{
		front++;
	}
}

void dequeueRear(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is Empty";
	}else if(front==rear){
		front=-1;
		rear=-1;
	}else if(rear==0){
		rear=N-1;
	}else{
		rear--;
	}
}

void getFront(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is empty";
	}else{
		std::cout<<queue[front]<<"\n";
	}
}

void getRear(){
	if(front==-1 && rear==-1){
		std::cout<<"Queue is empty";
	}else{
		std::cout<<queue[rear]<<"\n";
	}
}

void display(){
	int i=front;
	while(i!=rear){
		std::cout<<queue[i]<<" ";
		i=(i+1)%N;
	}
	std::cout<<queue[i]<<"\n";
}
int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice: \n1.EnqueueFront\n2.EnqueueRear\n3.DequeueFront\n4.DequeueRear\n5.GetFront\n6.6.GetRear\n7.Display\n";
		std::cin>>choice;
		switch(choice){
			case 1:enqueueFront();
			break;
			case 2:enqueueRear();
			break;
			case 3:dequeueFront();
			break;
			case 4:dequeueRear();
			break;
			case 5:getFront();
			break;
			case 6:getRear();
			break;
			case 7:display();
			break;
			default:exit(0);
		}
	}
	return 0;
}