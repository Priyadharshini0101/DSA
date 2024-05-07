#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key; 
    Node *left, *right;
};

Node* newNode(int key){
    Node* node = new Node();
    node -> key = key;
    node -> left = node -> right = nullptr;
    return node;
}

Node* rightRotate(Node *x){
    Node* y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    return y;
}

Node* leftRotate(Node *x){
    Node* y = x -> right;
    x -> right = y -> left;
    y -> left = x;
    return y;
}

Node* splay(Node* root, int key){
    if(root == nullptr || root -> key == key){
        return root;
    }
    if(root -> key > key){
        if(root -> left == nullptr){
            return root;
        }
        if(root->left->key > key){
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }else if(root->left->key < key){
            root->left->right = splay(root->left->right, key);
            if(root->left->right != nullptr){
              root->left = leftRotate(root->left);
            }
        }
        return (root -> left == nullptr) ? root : rightRotate(root);
    }else{
        if(root -> right == nullptr){
            return root;
        }
        if(root->right->key > key){
            root->right->left = splay(root->right->left,key);
            if(root->right->left != nullptr){
                root->right = rightRotate(root->right);
            }
        }else if(root->right->key < key){
            root->right->right = splay(root->right->right,key);
            root = leftRotate(root);
        }
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}
void preOrder(Node *node){
    if(node != nullptr){
        std::cout<<node -> key <<" ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

Node* insert(Node* root,int key){
    if(root == nullptr){
        return newNode(key);
    }
   
    root = splay(root, key);
    if(root -> key == key){
        return root;
    }

    Node* node = newNode(key);
    if(root -> key > key){
        node -> right = root;
        node -> left = root -> left;
        root -> left = nullptr;
    }else{
        node -> left = root;
        node -> right = root -> right;
        root -> right = nullptr;
    }
    return node;
}


Node* deleteKey(Node* root,int key){
   
     if(root == nullptr){
         return nullptr;
     }
  
    root = splay(root,key);
     Node* root1 = new Node();
     if(key != root -> key){
         root1 = root;
         std::cout<<"Key "<<key<<" not exist"<<"\n";
    }else{ 
        std::cout<<"Key "<<key<<" delete successfully"<<"\n";
        if(root -> left == nullptr){
             root1 = root -> right;
         }else{
             Node* temp = root;
             root1 = splay(root->left, key);
             root1->right = temp -> right;
         }
     }
     return root1;
}

Node* search(Node* root, int key){
    root = splay(root,key);
    if(root->key == key){
        std::cout<<"Key "<<key<<" found"<<"\n";
    }else{
        std::cout<<"Key "<<key<<" not found"<<"\n";
    }
    return root;
}

int main(){
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root,8);
    root = insert(root,14);
    root = insert(root,15);
    root = insert(root,13);
    std::cout<<"Elements in Splay Tree: "; preOrder(root); std::cout<<"\n";
    root = search(root,15);
    root = search(root,6);
    root = deleteKey(root, 14);
    root = deleteKey(root , 5);
    root = deleteKey(root,10);
    std::cout<<"Elements in Splay Tree: "; preOrder(root); std::cout<<"\n";
    return 0;

}

