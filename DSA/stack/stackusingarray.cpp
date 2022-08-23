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

//Insert a value into a stack - insert condition (stack is not full)
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

//Delete a value from a stack - delete condition (stack is not empty)
void pop(){
    int item;
    if(top==-1){
        std::cout<<"Underflow condition";
    }else{
        std::cout<<st[top]<<"\n";
        top--;
    }
}

//Peek the top of the element from the stack - peek condition (stack is not empty)
void peek(){
      if(top==-1){
          std::cout<<"Stack is empty";
      }else{
          std::cout<<st[top]<<"\n";
      }
}

//Display the elements in the stack - LIFO
void display(){
    for(int i=top;i>=0;i--){
        std::cout<<st[top]<<"\n";
    }
}

//empty
void isEmpty(){
    if(top==-1){
        std::cout<<"Stack is empty";
    }
}

//Full
void isFull(){
    if(top==N-1){
        std::cout<<"Stack is full";
    }
}

