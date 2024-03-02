#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *create(){
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	int x;
	std::cout<<"Enter data";
	std::cin>>x;
	if (x == -1){
		return NULL;
    }
	newnode->data=x;
	std::cout<<"Enter the left child ";
	newnode->left=create();
	std::cout<<"Enter the right child ";
	newnode->right=create();
	return newnode;
}

void printPostorder(struct Node *node){
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	std::cout << node->data << " ";
}

void printInorder(struct Node *node){
	if (node == NULL)
		return;
	printInorder(node->left);
	std::cout << node->data << " ";
	printInorder(node->right);
}

void printPreorder(struct Node *node){
	if (node == NULL)
		return;
	std::cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

int main(){	
    struct Node *root = NULL;	
	int choice;
	while(1){
		std::cout<<"Enter the choice:\n1.Create Tree\n2.PreOrder\n3.Inorder\n4.PostOrder";
		std::cin>>choice;
		switch(choice){
			case 1:	root=create();
			break;
			case 2:printPreorder(root);
			break;
			case 3:printInorder(root);
			break;
			case 4:printPostorder(root);
			break;
			default:exit(0);
		}
	}
	return 0;
}
