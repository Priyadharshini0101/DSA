#include <bits/stdc++.h>
#include <iostream>

struct node{
    int data;
    struct node *next;
}*head=NULL,*temp=NULL,*newnode=NULL;
int count=0;

void createLL(){
   newnode=(struct node*)malloc(sizeof(struct node));
   int d;
   std::cout<<"Enter data:";
   std::cin>>d;
   newnode->data=d;
   newnode->next=NULL;
   if(head==NULL){
    head=newnode;
    temp=newnode;
   }else{
      temp->next=newnode;
      temp=newnode;
   }
}

void display(){
    temp=head;
    while(temp!=0){
        std::cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    std::cout<<"\n";
}

void numberOfElements(){
     temp=head;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    std::cout<<count<<"\n";
}

void insertAtBeg(){
	std::cout<<"To enter data at the beginning\n";
	newnode=(struct node*) malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter data";
	std::cin>>d;
	newnode->data=d;
	newnode->next=head;
	head=newnode;
}

void insertAtEnd(){
	temp=head;
	std::cout<<"To enter data at the end\n";
	newnode=(struct node*) malloc(sizeof(struct node));
	int d;
	std::cin>>d;
	newnode->data=d;
	newnode->next=NULL;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=newnode;
}

void insertAtMiddle(){
	std::cout<<"To enter data in middle of a list\n";
	newnode=(struct node*)malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter data";
	std::cin>>d;
	newnode->data=d;
	std::cout<<"Enter the position";
	int pos;
	std::cin>>pos;
	int i=1;
	temp=head;
	while(i<pos){
		i++;
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}

void deleteAtBeg(){
	std::cout<<"To delete data from the beginning\n";
	temp=head;
	head=head->next;
	free(temp);
}

void deleteAtEnd(){
	std::cout<<"To delete data from the end\n";
	temp=head;
	struct node *prevnode;
	while(temp->next!=0){
		prevnode=temp;
		temp=temp->next;
	}
	prevnode->next=0;
	free(temp);	
}

void deleteAtMiddle(){
	std::cout<<"To delete data from the Middle\n";
	temp=head;
	int pos;
	std::cout<<"Enter position";
	std::cin>>pos;
	int i=0;
	struct node *nextnode;
	while(i<pos-1){
		temp=temp->next;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}

void reverse(){
	struct node *prevnode=NULL,*nextnode,*currnode;
	nextnode=head;
	currnode=head;
	while(nextnode!=0){
		nextnode=nextnode->next;
		currnode->next=prevnode;
		prevnode=currnode;
		currnode=nextnode;
	}
	head=prevnode;
}

int main(){
    int choice;
    while(1){
    std::cout<<"Enter your choice\n";
    std::cout<<"\n1.To Create a Linked List\n2.Insert at beg\n3.Insert at middle\n4.Insert at End\n5.Delete at Beg\n6.Delete at Middle\n7.Delete at End\n8.Reverse list\n9.Display\n10.Number if Elements\n";  
    std::cin>>choice;
    switch(choice){
      case 1:createLL();
      break;
      case 2:insertAtBeg();
      break;
      case 3:insertAtMiddle();
      break;
      case 4:insertAtEnd();
      break;
      case 5:deleteAtBeg();
      break;
      case 6:deleteAtMiddle();
      break;
      case 7:deleteAtEnd();
      break;
      case 8:reverse();
      break;
      case 9:display();
      break;
      case 10:numberOfElements();
      break;
      default:exit(0);
    }
}
    return 0;
}