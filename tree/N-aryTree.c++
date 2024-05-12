#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;
    TreeNode(int data){
        this->data = data;
    }
};

void display(TreeNode* root){
    if(root == NULL){
        return;
    }
    std::cout<<root->data<<" ";
    for(int i=0;i< root->children.size();i++){
        std::cout<<root->children[i]->data<<" ";
    }
    std::cout<<"\n";
    for(int i=0;i<root->children.size();i++){
        display(root->children[i]);
    }
}

//Deleting leaf nodes
TreeNode* deleteLeafNodes(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    if(root->children.size() == 0){
        delete root;
        return NULL;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode* child = root->children[i];
        if(child->children.size() == 0){
            delete child;
            for(int j=i;j<root->children.size()-1;j++){
                root->children[j] = root->children[j+1];
            }
            root->children.pop_back();
            i--;
        }
    }
        for(int i=0;i<root->children.size();i++){
            root->children[i] = deleteLeafNodes(root->children[i]);
        }
        return root;
}

int main(){
    TreeNode* root = new TreeNode(11);
    
    TreeNode* child1 = new TreeNode(1);
    root->children.push_back(child1);
    
    TreeNode* child2 = new TreeNode(2);
    root->children.push_back(child2);
    
    TreeNode* child21 = new TreeNode(7);
    child2->children.push_back(child21);
    
     TreeNode* child3 = new TreeNode(3);
    root->children.push_back(child3);
    
    TreeNode* child31 = new TreeNode(8);
    TreeNode* child32 = new TreeNode(9);
    child3->children.push_back(child31);
    child3->children.push_back(child32);
   
    TreeNode* child4 = new TreeNode(4);
    root->children.push_back(child4);
    
    TreeNode* child5 = new TreeNode(5);
    root->children.push_back(child5);
    
    TreeNode* child51 = new TreeNode(10);
    child5->children.push_back(child51);
    display(root);

    TreeNode* temp = deleteLeafNodes(root);
    display(temp);
  
    return 0;
}
