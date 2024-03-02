#include <iostream>
#include <bits/stdc++.h>
#define N 5

int count=0;
int s1[N],s2[N];
int top1=-1,top2=-1;

int pop1(){
	int d =s1[top1];
	top1--;
	return d;
}

int pop2(){
	int d=s2[top2];
	top2--;
	return d;
}

void push1(int data){
	if(top1==N-1){
		std::cout<<"Overflow";
	}else{
		top1++;
		s1[top1]=data;
	}
}

void push2(int data){
	if(top2==N-1){
		std::cout<<"Overflow";
	}else{
		top2++;
		s2[top2]=data;
	}
}

void enqueue(){
	int data;
	std::cout<<"Enter the data";
	std::cin>>data;
   push1(data);	
   count++;
}

void dequeue(){
	if(top1==-1){
		std::cout<<"Underflow";
	}else{
		for(int i=0;i<count;i++){
			push2(pop1());
		}    
		top2--;
		count--;
		for(int i=0;i<count;i++){
			push1(pop2());
		}
	}
}

void display(){
	for(int i=0;i<=top1;i++){
		std::cout<<s1[i]<<" ";
	}
	std::cout<<"\n";
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice:\n1.Enqueue\n2.Dequeue\n3.Display\n";
		std::cin>>choice;
		switch(choice){
			case 1:enqueue();
			        break;
		    case 2:dequeue();
		            break;
		     case 3:display();
		            break;
		     default:exit(0);
		}
	}
	return 0;
}
