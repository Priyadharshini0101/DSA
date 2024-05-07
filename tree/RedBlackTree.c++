#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RedBlackTree
{
private:
  struct Node
  {
    int data;
    Node *left;
    Node *right;
    char colour;
    Node *parent;
    Node(int data) : data(data), left(nullptr), right(nullptr), colour('R'), parent(nullptr) {}
  };

  bool ll;
  bool rr;
  bool lr;
  bool rl;

  Node *rotateLeft(Node *node){
    Node *x = node->right;
    Node *y = x->left;
    x->left = node;
    node->right = y;
    node->parent = x;
    if (y != nullptr){
      y->parent = node;
    }
    return x;
  }

  Node *rotateRight(Node *node){
    Node *x = node->left;
    Node *y = x->right;
    x->right = node;
    node->left = y;
    node->parent = x;
    if (y != nullptr){
      y->parent = node;
    }
    return x;
  }

  Node *insertHelp(Node *root, int data){
    bool f = false;

    if (root == NULL){
      return new Node(data);
    }else if (data < root->data){
      root->left = insertHelp(root->left, data);
      root->left->parent = root;
      if (root != this->root){
        if (root->colour == 'R' && root->left->colour == 'R'){
          f = true;
        }
      }
    }else if (data > root->data){
      root->right = insertHelp(root->right, data);
      root->right->parent = root;
      if (root != this->root){
        if (root->colour == 'R' && root->right->colour == 'R'){
          f = true;
        }
      }
    }

    if (ll){
      root = rotateLeft(root);
      root->colour = 'B';
      root->left->colour = 'R';
      ll = false;
    }
    else if (rr){
      root = rotateRight(root);
      root->colour = 'B';
      root->right->colour = 'R';
      rr = false;
    }else if (rl){
      root->right = rotateRight(root->right);
      root->right->parent = root;
      root = rotateLeft(root);
      root->colour = 'B';
      root->left->colour = 'R';
      rl = false;
    }else if (lr){
      root->left = rotateLeft(root->left);
      root->left->parent = root;
      root = rotateRight(root);
      root->colour = 'B';
      root->right->colour = 'R';
      lr = false;
    }

    if (f){
      if (root->parent->right == root){
        if (root->parent->left == NULL || root->parent->left->colour == 'B'){
          if (root->left != nullptr && root->left->colour == 'R'){
            rl = true;
          }
          else{
            ll = true;
          }
        }
        else{
          root->parent->left->colour = 'B';
          root->colour = 'B';
          if (root->parent != this->root){
            root->parent->colour = 'R';
          }
        }
      }
      else{
        if (root->parent->right == nullptr || root->parent->right->colour == 'B'){
          if (root->left != NULL && root->left->colour == 'R'){
            rr = true;
          }
          else if (root->right != NULL && root->right->colour == 'R'){
            lr = true;
          }
        }else{
          root->parent->right->colour = 'B';
          root->colour = 'B';
          if (root->parent != this->root){
            root->parent->colour = 'R';
          }
        }
      }
      f = false;
    }
    return root;
  }
  void moveDown(Node *x, Node *nParent){
    Node *parent = x->parent;
    if (parent != NULL){
      if (parent->left == x){
        parent->left = nParent;
      }else{
        parent->right = nParent;
      }
    }
    nParent->parent = parent;
    x->parent = nParent;
  }

  void rotateLeft1(Node *x){
    Node *nParent = x->right;
    
    if (x == root){
      root = nParent;
    }

    moveDown(x, nParent);

    x->right = nParent->left;

    if (nParent->left != NULL){
      nParent->left->parent = x;
    }

    nParent->left = x;
  }

  void rotateRight1(Node *x){
    Node *nParent = x->left;

    if (x == root){
      root = nParent;
    }

    moveDown(x, nParent);

    x->left = nParent->right;

    if (nParent->right != NULL){
      nParent->right->parent = x;
    }

    nParent->right = x;
  }

  void fixDoubleBlack(Node *x){
    if (x == root){
      return;
    }

    Node *sibling = NULL;
    if (x->parent != NULL){
      if (x->parent->left == x){
        sibling = x->parent->right;
      }else{
        sibling = x->parent->left;
      }
    }

    Node *parent = x->parent;
    if (sibling == NULL){
     // No sibling,  push double  black up
      fixDoubleBlack(parent);
    }else{
      if (sibling->colour == 'R'){
        // Sibling red
        parent->colour = 'R';
        sibling->colour = 'B';
        if (parent->left == sibling){
          // left case
          rotateRight1(parent);
        }else{
          // right case
          rotateLeft1(parent);
        }
        fixDoubleBlack(x);
      }
      else{
         // Sibling black
        if ((sibling->left != NULL && sibling->left->colour == 'R') || (sibling->right != NULL && sibling->right->colour == 'R')){
          // When sibling has at least one child red
          if (sibling->left != NULL && sibling->left->colour == 'R'){
             // Sibling black
            if (parent->left == sibling){
              sibling->left->colour = sibling->colour;
              sibling->colour = parent->colour;
              rotateRight1(parent);
            }else{
              // Sibling black
              sibling->left->colour = parent->colour;
              rotateRight1(sibling);
              rotateLeft1(parent);
            }
          }else{
             // Sibling black
            if (parent->left == sibling){
              sibling->right->colour = parent->colour;
              rotateLeft1(sibling);
              rotateRight1(parent);
            }else{
              // Sibling black
              sibling->right->colour = sibling->colour;
              sibling->colour = parent->colour;
              rotateLeft1(parent);
            }
          }
          parent->colour = 'B';
        }
        else{
          // Sibling black
          sibling->colour = 'R';
          if (parent->colour == 'B'){
            // u or v is red and v is leaf
            fixDoubleBlack(parent);
          }
          else{
            // u or v is red and v is leaf
            parent->colour = 'B';
          }
        }
      }
    }
  }

  void deleteKey(Node *v){
    Node *u;
    if (v->left != NULL && v->right != NULL){
      Node *temp = v;
      while (temp->left != NULL){
        temp = temp->left;
      }
      u = temp;
    }
    else if (v->left == NULL && v->right == NULL){
      u = NULL;
    }
    else if (v->left != NULL){
      u = v->left;
    }
    else{
      u = v->right;
    }

    bool uvBlack = ((u == NULL || u->colour == 'B') && (v->colour == 'B'));
    Node *parent = v->parent;
    // single
    if (u == NULL){
      if (v == root){
        // u is null and v is leaf and root
        root = NULL;
      }else{
        if (uvBlack){
          // u and v both black and v is leaf not root
          fixDoubleBlack(v);
        }else{
          // u or v is red and v is leaf
          if (parent != NULL){
            if (parent->left == v){
              if (parent->right != nullptr){
                parent->right->colour = 'R';
              }
            }else{
              if (parent->left != nullptr){
                parent->left->colour = 'R';
              }
            }
          }
        }

        // delete v from the tree
        if (parent->left == v){
          parent->left = NULL;
        }else{
          parent->right = NULL;
        }
      }
      delete v;
      return;
    }

    // has child
    if (v->left == NULL || v->right == NULL){
      // v has 1 child
      if (v == root){
        v->data = u->data;
        v->left = v->right = NULL;
        delete u;
      }else{
        // Detach v from tree and move up u
        if (parent != NULL){
          if (parent->left == v){
            parent->left = u;
          }
          else{
            parent->right = u;
          }
        }
        delete v;
        u->parent = parent;
        // After moving up u
        if (uvBlack){
          // u and v both black, fix double black at u
          fixDoubleBlack(u);
        }else{
          // u or v red, colour u black
          u->colour = 'B';
        }
      }
      return;
    }
    int temp;
    temp = u->data;
    u->data = v->data;
    v->data = temp;
    deleteKey(u);
  }

public:
  Node *root;
  void preOrderTraversal(Node *root){
    if (root != NULL){
      std::cout<<root->data<<root->colour<<" ";
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);
    }
  }

  void insert(int data){
    if (root == NULL) {
      root = new Node(data);
      root->colour = 'B';
    }else{
      root = insertHelp(root, data);
    }
  }

  Node *search(Node *temp, int data){
    if (temp == NULL){
      std::cout << "Data " << data << " not found\n";
      return NULL;
    }else if (temp->data > data){
      search(temp->left, data);
    }else if (temp->data < data){
      search(temp->right, data);
    }else if (temp->data == data){
      std::cout << "Data " << data << " found\n";
      return temp;
    }
  }

  void deleteValue(int data){
    Node *temp = search(root, data);
    if (root == NULL){
      return;
    }
    if (temp->data != data){
      return;
    }
    deleteKey(temp);
  }
};

int main(){
  RedBlackTree rbt;

  rbt.insert(50);
  rbt.insert(20);
  rbt.insert(15);
  rbt.insert(30);
  rbt.insert(55);
  rbt.insert(70);
  rbt.insert(65);
  rbt.insert(68);
  rbt.insert(80);
  rbt.insert(90);

  rbt.preOrderTraversal(rbt.root);
  std::cout << "\n";

  rbt.deleteValue(55);
  rbt.deleteValue(30);
  rbt.deleteValue(90);
  rbt.deleteValue(80);
  rbt.deleteValue(50);
  rbt.deleteValue(15);
  rbt.deleteValue(65);
  rbt.deleteValue(68);
  rbt.deleteValue(70);
  rbt.deleteValue(20);

  rbt.search(rbt.root,51);
  rbt.search(rbt.root,65);

  rbt.preOrderTraversal(rbt.root);

  return 0;
}