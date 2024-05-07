#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

Node* newNode(int key){
    Node* node = new Node();
    node -> key = key;
    node -> left = node -> right = nullptr;
    node -> height = 1;
    return node;
}

void preOrder(Node *root){
    if(root != nullptr){
        std::cout<<root -> key<<" ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

int height(Node *N){
    if(N == nullptr){
        return 0;
    }
    return N -> height;
}

int max(int a,int b){
    return (a > b)? a : b;
}

int getBalance(Node *N){
    if(N == nullptr){
        return 0;
    }
    return height(N -> left) - height(N -> right);
}

Node *rightRotate(Node *y){
    Node *x = y -> left;
    Node *T2 = x->right;
    x->right= y;
    y ->left = T2;
    
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x ->right = T2;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y->left),height(y->right)) + 1;
    return y;
}

Node* balance(Node* node,int key){
    node -> height = 1 + max(height(node -> left) , height(node -> right));
    int balance = getBalance(node);
    if(balance > 1){
        if(key > node->left->key){
          node->left = leftRotate(node->left);
       }
       return rightRotate(node);
    }
   
    if(balance < -1){
        if(key < node->right->key){
        node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
   
    return node;
}

Node* insert(Node* root,int key){
       if(root == nullptr){
        return newNode(key);
    }
    if(key < root->key){
        root->left = insert(root -> left, key);
    }else if(key > root->key){
        root -> right = insert(root -> right, key);
    }else{
        return root;
    }
    return balance(root,key);
}

Node* inorderSuccessor(Node* temp,int key){
    while(temp && temp-> left != NULL){
        temp = temp -> left;
    }
   return temp;
}
Node* deleteKey(Node* root,int key){
    if(root == nullptr){
        return root;
    }
    if(key < root -> key){
        root -> left = deleteKey(root -> left, key);
    }else if(key > root -> key){
        root -> right = deleteKey(root -> right, key);
    }else{
         if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }

        if(root -> left == nullptr){
            Node* temp = root -> right;
            delete root;
            return temp;
        }else if(root -> right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = inorderSuccessor(root-> right , key);
        
        root -> key = temp -> key;
         root -> right = deleteKey(root -> right, temp -> key);
   
    }
    return balance(root,key);
}

void search(Node *temp,int key){
    if(temp == NULL){
        std::cout<<"Key "<<key<<" not found\n";
    }else if(temp -> key > key){
        search(temp -> left, key);
    }else if(temp -> key < key){
        search(temp -> right, key);
    }else{
        std::cout<<"Key "<<key<<" found\n";
    }
}


int main(){
    Node *root = nullptr;
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 11);
    root = insert(root, 7);
    root = insert(root, 53);
    root = insert(root, 4);
    root = insert(root,13);
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 60);
    root = insert(root, 19);
    root = insert(root, 16);
    root = insert(root, 20);
      
    root = deleteKey(root,8);
    root = deleteKey(root, 7);
    root = deleteKey(root, 11);
    root = deleteKey(root, 14);
    root = deleteKey(root , 17);
    
    search(root,10);
    search(root,13);
    search(root,12);
 
    preOrder(root);
    return 0;
}