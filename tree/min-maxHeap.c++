#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
}*temp = NULL; 

struct node* createNode(int d){
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insertNode(struct node* temp,int d){
    if(temp == NULL){
        return createNode(d);
    }
    if(d > temp->data){
        swap(d,temp->data);
    }
    if(d > temp->data){
        temp->right = insertNode(temp->right , d);
    }else{
        temp->left = insertNode(temp->left, d);
    }
    return temp;
}

struct node* deleteNode(struct node* temp){
    if(temp == NULL){
        return NULL;
    }
    if(temp->left == NULL && temp->right == NULL){
        delete temp;
        return NULL;
    }
    if(temp->left && temp->right){
        if(temp->left->data > temp->right->data){
            swap(temp->data, temp->left->data);
            temp->left = deleteNode(temp->left);
        }else{
            swap(temp->data,temp->right->data);
            temp->right = deleteNode(temp->right);
        }
    }else{
        if(temp->left){
            swap(temp->data,temp->left->data);
            temp->left = deleteNode(temp->left);
        }else{
            swap(temp->data,temp->right->data);
            temp->right = deleteNode(temp->right);
        }
    }
    return temp;
}

void display(struct node* temp){
    if(temp == NULL){
        return;
    }
    display(temp->left);
    cout<<temp->data<<" ";
    display(temp->right);
}

int main()
{
    struct node *root;
    bool flag;
    int choice,d;
    while(1){
        std::cout<<"Enter your choice:\n1.Create Heap\n2.Insert Node\n3.Delete Node\n4.Display\n";
        std::cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the data:";
            cin>>d;
            root = createNode(d);
            break;
            case 2:
            cout<<"Enter the data";
            cin>>d;
            root =insertNode(root,d);
            break;
            case 3:deleteNode(root);
            break;
            case 4:display(root);
            break;
            default:
                exit(0);
        }
    }
    return 0;
}