/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"
#include <cstdio>
#include <string>

using namespace std;

// Recursively finds nodes inorder that fall within range
void BSTree::rangeNodeSearch(vector<Customer>& vec, Customer lower, Customer upper, Node* n) {
  if (n == NULL) {
    return;
  }
  if (lower <= n->data) {
    rangeNodeSearch(vec, lower, upper, n->left);
  }
  if (lower <= n->data && upper >= n->data) {
    vec.push_back(n->data);
  }
  if (upper > n->data) {
    rangeNodeSearch(vec, lower, upper, n->right);
  }
}

// Find the smallest node in Node n subtree
Node* BSTree::findSuccessor(Node* n) {
  if (n->left == NULL) {
    return n;
  }
  Node* current = n;
  while (current->left != NULL) {
    current = current->left;
  }
  Node* successor;
  successor->data = current->data;
  delete current;                     // Deleting successor's old position in tree
  return successor;
}

// Recursively prints customers inorder
void BSTree::inOrderTraversal(Node* n) {
	if (n == nullptr) {
    return;
  }
	inOrderTraversal(n->left);
	cout << n->data << endl;
	inOrderTraversal(n->right);
}

// Recursively deletes tree postorder
void BSTree::removeAll(Node* n) {
	if (n == NULL) {
		return;
	}
	removeAll(n->left);
	removeAll(n->right);
	delete n;
}

BSTree::BSTree() {
	root = NULL;
}

BSTree::~BSTree() {
	removeAll(root);
}

bool BSTree::insert(string x, char y, int z) {
  Node* newnode = new Node(x, y, z);
	if (root == NULL) {
		root = newnode;
		return true;
	}
	Node* current = root;
	Node* parent;
	while (current != NULL) {           
		parent = current;
		if (newnode->data <= current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	if (newnode->data <= parent->data) {
		parent->left = newnode;
		return true;
	} else {
		parent->right = newnode;
		return true;
	}
	return false;
}

bool BSTree::remove(string x, char y) {
  if (root == NULL) {
    return false;
  }
  if (search(x, y)) {                 // Searching if node is present in tree
    Customer key = Customer(x, y, 0);
    Node* current = root;
    Node* parent;
    while (current->data != key) {
      parent = current;
      if (key < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    if (current->left == NULL && current->right == NULL) {  // Node has no children
      if (current != root) {
        if (parent->left == current) {
          parent->left = NULL;
          delete current;
          return true;
        } else {
          parent->right = NULL;
          delete current;
          return true;
        }
      } else {                                      // Root is the node to be removed
        root = NULL;
        delete current;
        return true;
      } 
    } else if (current->left && current->right) {      // Node has two children
      Node* successor = findSuccessor(current->right);
      Customer val = successor->data;
      current->data = val;
    } else {                                           // Node has one child
      Node* child = (current->left)? current->left: current->right;     // Determining which is the one child
      if (current != root) {
        if (parent->left == current) {
          parent->left = child;
        } else {
          parent->right = child;
        }
      } else {
        root = child;
      }
      delete current;
    }
  }
  return false;
}

bool BSTree::search(string x, char y) {
	if (root == NULL) {
		return false;
	}
	Node* key = new Node(x, y, 0);
	Node* current = root;
	while (current != NULL) {
		if (current->data == key->data) {
			delete key;
			return true;
		} else {
			if (current->data > key->data) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
	}
	return false;
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	vector<Customer> result;
  // Setting the range bounds
	Customer lowerBound = Customer(x, y, 0);          
	Customer upperBound = Customer(z, a, 0);
  if (lowerBound > upperBound) {
    return result;
  }
  if (root != NULL) {
    rangeNodeSearch(result, lowerBound, upperBound, root);
	}
	return result;
}

void BSTree::inOrderPrint() {
	inOrderTraversal(root);
}
