//Stack using array
#include <bits/stdc++.h>
#include <iostream>
#define N 5

int st[N];
int top=-1;
using namespace std;

int main(){
    int choice;
    std::cout<<"Enter your choice:\n7.Exit\n1.Insert\n2.Delete\n3.Top\n4.Display\n5.IsEmpty\n6.IsFull\n";
    std::cin>>choice;
    switch(choice){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:peek();
        break;
        case 4:display();
        break;
        case 5:isEmpty();
        break;
        case 6:isFull();
        break;
        default:
        cout<<"Invalid Operation";
     }
    return 0;
}

void push(){
      int data;
      std::cout<<"Enter the data";
      std::cin>>data; 
      if(top==N-1){
          std::cout<<"Overflow Condition!";
      }else{
          top++;
          st[top]=data;
      }
}

void pop(){
    int item;
    if(top==-1){
        std::cout<<"Underflow condition";
    }else{
        std::cout<<st[top]<<"\n";
        top--;
    }
}

void peek(){
      if(top==-1){
          std::cout<<"Stack is empty";
      }else{
          std::cout<<st[top]<<"\n";
      }
}

void display(){
    for(int i=top;i>=0;i--){
        std::cout<<st[top]<<"\n";
    }
}

void isEmpty(){
    if(top==-1){
        std::cout<<"Stack is empty";
    }
}

void isFull(){
    if(top==N-1){
        std::cout<<"Stack is full";
    }
}

