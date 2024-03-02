#include <iostream>
#include <bits/stdc++.h>
#define N 5

int queue[N];
int front=-1,rear=-1;

void enqueue(){
	int data;
	std::cout<<"Enter the data to be inserted";
    std::cin>>data;
    if(rear==N-1){
    	std::cout<<"Overflow";
	}else if(front==-1 && rear==-1){
		front=0;
		rear=0;
		queue[rear]=data;
	}else{
	rear++; 
    queue[rear]=data;
   }
}

void dequeue(){
	if(front==-1 && rear==-1){
		std::cout<<"Underflow";
	}else if(front==0 && rear==0){
		front=-1;
		rear=-1;
	}else{
		front++;
	}
}

void peek(){
	if(front==-1 && rear==-1){
            std::cout<<"Underflow";
	}else{
	std::cout<<"Top element is "<<queue[front]<<"\n";
	}
}

void display(){
	for(int i=front;i<=rear;i++){
		std::cout<<queue[i]<<" ";
	}
	std::cout<<"\n";
}
int main(){
	int choice;
	while(1){
	std::cout<<"Enter your choice:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display";
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