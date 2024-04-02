#include <iostream>
#include <bits/stdc++.h>

struct node{
	int data;
	struct node *next,*prev;
}*head=NULL,*tail=NULL,*temp=NULL,*newnode=NULL;

void createDCLL(){
	newnode=(struct node*)malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode->data=d;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
		tail=newnode;
		newnode->prev=tail;
		newnode->next=tail;
	}else{
		newnode->next=head;
		newnode->prev=tail;
		tail->next=newnode;
		head->prev=newnode;
		tail=newnode;
	}
}

void display(){
	temp=head;
	while(temp!=tail){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
	std::cout<<temp->data<<"\n";
}

void insertAtBegin(){
	newnode=(struct node*)malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode->data=d;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		tail=newnode;
		head->prev=tail;
		head->next=tail;
	}else{
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=tail;
		tail->next=newnode;
		head=newnode;
	}
}

void insertAtEnd(){
	newnode=(struct node*)malloc(sizeof(struct node));
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode->data=d;
	newnode->next=NULL;
	if(tail==0){
		tail=newnode;
		head=newnode;
		head->prev=tail;
		head->next=tail;
	}else{
		newnode->prev=tail;
		tail->next=newnode;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
	}
}

void insertAtMiddle(){
	int pos;
	std::cout<<"Enter the position";
	std::cin>>pos;
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	if(pos==1){
		insertAtBegin();
	}else{
		temp=head;
		int i=0;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		newnode->next->prev=newnode;
		temp->next=newnode;
	}
}

void deleteAtBegin(){
	temp=head;
	if(head==NULL){
		std::cout<<"Invalid";
	}else{
		head=head->next;
		head->prev=tail;
		tail->next=head;
		free(temp);
	}
}


void deleteAtEnd(){
	temp=tail;
	if(tail==0){
		std::cout<<"Invalid";
	}else{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		free(temp);
	}
}

void deleteAtMiddle(){
	temp=head;
	int pos;
	std::cout<<"Enter the position";
	std::cin>>pos;
	if(pos==1){
		deleteAtBegin();
	}else{
		int i=0;
		while(i<pos){
			temp=temp->next;
			i++;
		}
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		if(temp->next==head){
			tail=temp->next;
			free(temp);
		}else{
			free(temp);
		}
				
	}
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice:\n1.CreateDCLL\n2.InsertAtBegin\n3.InsertAtEnd\n4.InsertAtMiddle\n5.DeleteAtBegin\n6.DeleteAtEnd\n7.DeleteAtMiddle\n8.Display\n";
		std::cin>>choice;
		switch(choice){
			case 1:createDCLL();
			break;
			case 2:insertAtBegin();
			break;
			case 3:insertAtEnd();
			break;
			case 4:insertAtMiddle();
			break;
			case 5:deleteAtBegin();
			break;
			case 6:deleteAtEnd();
			break;
			case 7:deleteAtMiddle();
			break;
      	    case 8:display();
			break;
			default:exit(0);
		}
	}
	return 0;
}