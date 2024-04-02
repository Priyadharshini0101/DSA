#include <bits/stdc++.h>
#include <iostream>

struct node{
	int data;
	struct node *prev,*next;
}*head=NULL,*newnode=NULL,*temp=NULL;
int count=0;

void createDLL(){
	int d;
	std::cout<<"Enter data:";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=d;
	if(head==NULL){
		head=newnode;
		temp=newnode;
	}else{
		temp->next=newnode;
		newnode->prev=temp;
		temp=newnode;
	}
}

void display(){
	temp=head;
	while(temp!=0){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void numberOfElements(){
	temp=head;
	while(temp!=0){
		count++;
		temp=temp->next;
	}
	std::cout<<count<<"\n";
}

void reverse(){
	struct node *nextnode,*current,*tail;
	current=head;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	tail=temp;
	while(current!=0){
		nextnode=current->next;
		current->next=current->prev;
		current->prev=nextnode;
		current=nextnode;
	}
	current=head;
	head=tail;
	tail=current;
}


void insertAtBeg(){
	int d;
    std::cout<<"Enter data";
    std::cin>>d;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insertAtEnd(){
	int d;
	std::cout<<"Enter data";
    std::cin>>d;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=0){
    	temp=temp->next;
	}
	
	temp->next=newnode;
	newnode->prev=temp;
	temp=newnode;
}

void insertAtMiddle(){
	temp=head;
	int i=0;
	int pos;
	std::cout<<"Enter position";
	std::cin>>pos;
	int d;
	std::cout<<"Enter data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->prev=0;
	newnode->next=0;
	newnode->data=d;
	while(i<pos-1){
		i++;
		temp=temp->next;
	}
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->next->prev=newnode;
}

void deleteAtBeg(){
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}

void deleteAtEnd(){
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}

void deleteAtMiddle(){
	temp=head;
	int pos;
	std::cout<<"Enter position";
	std::cin>>pos;
	int i=0;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}

int main(){
	int choice;
	while(1){
		std::cout<<"Enter the choice:\n1.Create DDL\n2.Insert At Beg\n3.Insert At End\n4.Insert At Middle\n5.Delete At First\n6.Delete At End\n7.Delete At Middle\n8.Display\n9.Number of Elements\n10.Reverse\n";
		std::cin>>choice;
	    switch(choice){
	    	case 1:createDLL();
	    	break;
	    	case 2:insertAtBeg();
	    	break;
	    	case 3:insertAtEnd();
	    	break;
	    	case 4:insertAtMiddle();
	    	break;
	    	case 5:deleteAtBeg();
	    	break;
	    	case 6:deleteAtEnd();
	    	break;
	    	case 7:deleteAtMiddle();
	    	break;
	    	case 8:display();
	    	break;
	    	case 9:numberOfElements();
	    	break;
	    	case 10:reverse();
	    	break;
	    	default:exit(0);
	    }
	  }
	return 0;
}