#include <iostream>
#include <bits/stdc++.h>

struct node{
	int data;
	struct node *next;
}*tail=NULL,*newnode=NULL,*temp=NULL;
int count=1;

void createCLL(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=0;
	if(tail==NULL){
		tail=newnode;
		tail->next=newnode;
	}else{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	count++;
}

void display(){
	temp=tail->next;
	while(temp->next!=tail->next){
		std::cout<<temp->data<<" ";
		temp=temp->next;
	}
	std::cout<<temp->data<<"\n";
}

void reverse(){
	struct node *prevnode,*currentnode,*nextnode;
	currentnode=tail->next;
	nextnode=currentnode->next;
	while(currentnode!=tail){
		prevnode=currentnode;
		currentnode=nextnode;
		nextnode=nextnode->next;
		currentnode->next=prevnode;
	}
    nextnode->next=tail;
    tail=nextnode;
}

void insertAtBeg(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	if(tail==NULL){
		tail->next=newnode;
		tail=newnode;
	}else{
		newnode->next=tail->next;
		tail->next=newnode;
	}
	count++;
}

void insertAtEnd(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	if(tail==NULL){
		tail->next=newnode;
		tail=newnode;
	}else{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	count++;
}

void insertAtMiddle(){
	int d;
	std::cout<<"Enter the data";
	std::cin>>d;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=NULL;
	int pos;
	int i=0;
	std::cout<<"Enter the position";
	std::cin>>pos;
	if(pos>count || pos<0){
		std::cout<<"Invalid";
	}else if(pos==1){
		insertAtBeg();
	}else{
		temp=tail->next;
     	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
   }
   count++;
}

void deleteAtBeg(){
	temp=tail->next;
	if(tail==NULL){
		std::cout<<"No elements to delete";
	}else if(temp->next==temp){
		tail=0;
		free(temp);
	}else{
		tail->next=temp->next;
		free(temp);
	}
}

void deleteAtEnd(){
	temp=tail;
	if(tail==NULL){
		std::cout<<"No elements to delete";
	}else if(temp->next==temp){
		tail=0;
		free(temp);
	}else{
		struct node *prevnode;
		while(temp->next!=tail->next){
			prevnode=temp;
			temp=temp->next;
		}
		prevnode->next=tail->next;
		tail=prevnode;
		free(temp);
	}
}

void deleteAtMiddle(){
	temp=tail;
	int pos;
	int i=0;
	std::cout<<"Enter the position";
	std::cin>>pos;
	if(pos>count || pos<0){
		std::cout<<"Invalid";
	}else if(pos==1){
		deleteAtBeg();
	}else{
	
	while(i<pos){
		temp=temp->next;
		i++;
	}
    struct node *nextnode;
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
	}

}

int main(){
	int choice;
	int val;
	while(1){
		std::cout<<"Enter your choice:\n1.Create CLL\n2.InsertAtBegin\n3.InsertAtEnd\n4.InsertAtMiddle\n5.DeleteAtBegin\n6.DeleteAtEnd\n7.DeleteAtMiddle\n8.Display\n9.Reverse\n";
		std::cin>>choice;
		switch(choice){
			case 1:createCLL();
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
			case 9:reverse();
			break;
			default:exit(0);
		}
	}
	return 0;
}