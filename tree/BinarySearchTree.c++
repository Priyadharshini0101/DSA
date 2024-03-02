#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
}*temp=NULL;

struct node *createNode(int d){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node *insertNode(struct node* temp,int d){
	if(temp==NULL){
		return createNode(d);
	}
	if(temp->data > d){
		temp->left=insertNode(temp->left,d);
	}
	if(temp->data < d){
		temp->right=insertNode(temp->right,d);
	}
	return temp;
}

void display(struct node* temp){
	if(temp==NULL){
	return;
   }
	display(temp->left);
	cout<<temp->data<<" ";
	display(temp->right);
	
}

bool search(struct node* temp,int key){
	if(temp==NULL){
		return false;
	}else if(temp->data > key){
		search(temp->left,key);
	}else if(temp->data < key){
		search(temp->right,key);
	}else if(temp->data==key){
		return true;
	}
}

struct node *smallestElements(struct node *temp){
	if(temp && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

struct node *largestElements(struct node *temp){
	if(temp && temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}

struct node *deleteNode(struct node *root,int value){
	    if(root == nullptr){
          return root;
      }
      if(value < root->data){
          root->left = deleteNode(root->left,value);
      }else if(value > root->data){
          root->right = deleteNode(root->right, value);
      }else{
          if(root->left == nullptr){
              struct node *temp = root->right;
              delete root;
              return temp;
          }else if(root->right == nullptr){
              struct node *temp = root->left;
              delete root;
              return temp;
          } 
      struct node *temp = smallestElements(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
	struct node* root;
	bool flag;
	int choice,d;
	while(1){
	cout<<"Enter your choice:\n1.Create BST\n2.Insert Node\n3.Delete Node\n4.Display\n5.Search\n6.Smallest Elements\n7.Largest Element\n";
	cin>>choice;
	switch(choice){
		case 1:
		cout<<"Enter the data:";
		cin>>d;
		root=createNode(d);
		break;
		case 2:
		cout<<"Enter the data:";
		cin>>d;
		root=insertNode(root,d);
		break;
		case 3:
		cout<<"Enter the data:";
		cin>>d;
		deleteNode(root,d);
		break;
		case 4:
		display(root);
		break;
		case 5:
		cout<<"Enter the element:";
		cin>>d;
		flag=search(root,d);
		if(flag){
			cout<<"Element Found\n";
		}else{
			cout<<"Element not found\n";
		}
		break;
		case 6:cout<<smallestElements(root)->data<<"\n";
		break;
		case 7:cout<<largestElements(root)->data<<"\n";
		break;
        default:
         	exit(0);
	}
   }
   return 0;
}