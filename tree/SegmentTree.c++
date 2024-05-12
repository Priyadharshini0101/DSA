#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int startInterval;
    int endInterval;
    Node *left,*right;
    
    Node(int startInterval,int endInterval){
        this->startInterval = startInterval;
        this->endInterval = endInterval;
    }
};

class SegmentTree{
    Node* constructSegmentTree(int arr[],int start,int end){
        if(start == end){
            Node *leaf = new Node(start,end);
            leaf->data = arr[start];
            return leaf;
        }
        
        Node *node = new Node(start,end);
        int mid = (start + end ) / 2;
        node->left = this->constructSegmentTree(arr,start,mid);
        node->right = this->constructSegmentTree(arr,mid+1, end);
        node->data = node->left->data + node->right->data;
        return node;
    }
    
    public:
    Node* createSegmentTree(int arr[],int n){
        return constructSegmentTree(arr,0,n - 1);
    }
    
    void display(Node* node){
        if(node != NULL){
            std::cout<<"[";
            std::cout<< node->startInterval;
            std::cout<<",";
            std::cout<< node->endInterval;
            std::cout<<"]";
            std::cout<< " :";
            std::cout<<node->data;
            std::cout<<"\n";
            display(node->left);
            display(node->right);
        }
    }
    
    int query(Node* root,int start,int end){
        if(root->startInterval >= start && root->endInterval <= end){
            return root->data;
        }else if(root->startInterval > end || root->endInterval < start){
            return 0;
        }else{
            return query(root->left,start,end) + query( root->right,start, end);
        }
    }
    
    int update(Node* node, int index,int value){
        if(index >= node->startInterval && index <= node->endInterval){
            if(index == node->startInterval && index <= node->endInterval){
                node->data = value;
                return node->data;
            }else{
                int leftAns = update(node->left,index,value);
                int rightAns = update(node->right,index,value);
                node->data = leftAns + rightAns;
                return node->data;
            }
        }
        return node->data;
    }
    
    
};

int main()
{
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    SegmentTree s;
    Node *root = s.createSegmentTree(arr,n);
    s.display(root);
    std::cout<<s.query(root,2,6)<<"\n";
    std::cout<<s.query(root,2,3)<<"\n";
    std::cout<<s.query(root,3,7)<<"\n";
    s.update(root,3,14);
    s.display(root);
    return 0;
}
