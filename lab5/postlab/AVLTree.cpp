// Yu Du, yd2am
// AVLTree.cpp
// 2019.10.16

#include "AVLTree.h"
#include <string>
#include <iostream>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  root = insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if(!find(x))    // there is no such string stored in this AVL tree
    return "";
  else {
    string path = pathTo(root, x);
    int len = path.size();
    return path.substr(1, len-1);
  }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL)
    return 0;
  else
    return numNodes(root);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  int bFactor = balanceFactor(n);
  if(bFactor > 1) {
    if(balanceFactor(n->right) < 0)
      n->right = rotateRight(n->right);
    
    n = rotateLeft(n);
  }
  else if(bFactor < -1) {
    if(balanceFactor(n->left) > 0)
      n->left = rotateLeft(n->left);
    
    n = rotateRight(n);
  }
}

// private helper method to calculate the balance factor
int AVLTree::balanceFactor(AVLNode* n) {
  if(n == NULL)
    return 0;

  return height(n->right) - height(n->left);
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode *node = n->right;
  n->right = node->left;
  node->left = n;

  // update height
  n->height = max(height(n->left), height(n->right)) + 1;
  node->height = max(height(node->left), height(node->right)) + 1;
  balance(n);
  balance(node);
  return node;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode *node = n->left;
  n->left = node->right;
  node->right = n;

  // update height
  n->height = max(height(n->left), height(n->right)) + 1;
  node->height = max(height(node->left), height(node->right)) + 1;
  balance(n);
  balance(node);
  return node;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }

// private helper for insert
AVLNode* AVLTree::insert(AVLNode*& n, const string& x) {
  if(n == NULL) {
    n = new AVLNode();
    n->value = x;
  }
  else if(x < n->value)
    n->left = insert(n->left, x);
  else if(x > n->value)
    n->right = insert(n->right, x);

  // update height
  n->height = max(height(n->left), height(n->right))+1;
  balance(n);
  return n;
}

// private helper for pathTo
string AVLTree::pathTo(AVLNode* n, const string& x) const{
  if(n == NULL)
    return " ";

  string path = "";
  string val = " " + n->value;
  if(x == n->value) {
    path = val;
  }
  else if(x < n->value)
    path = path + val + pathTo(n->left, x);
  else if(x > n->value)
    path = path + val + pathTo(n->right, x);

  return path;
}

// private helper for find
bool AVLTree::find(AVLNode* n, const string& x) const{
  if(n == NULL)
    return false;
  else if(x == n->value)
    return true;
  else if(x < n->value)
    return find(n->left, x);
  else   // x > n->value
    return find(n->right, x);
}

// private helper for numNodes
int AVLTree::numNodes(AVLNode* n) const{
  int num = 1;
  if(n->left != NULL)
    num += numNodes(n->left);
  if(n->right != NULL)
    num += numNodes(n->right);

  return num;
}


