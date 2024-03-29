/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include <vector>
#include <string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string x, char y, int z);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string x, char y);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string x, char y);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string x, char y, string z, char a);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

private:
	Node* root;
  
  	// Helper function for rangeSearch
  	void rangeNodeSearch(vector<Customer>& vec, Customer lower, Customer upper, Node* n);
 
  	// Helper function for remove
  	Node* findSuccessor(Node* n);
  
	// Helper function for inOrderPrint
	void inOrderTraversal(Node* n);
 
	// Helper function for ~BSTree
	void removeAll(Node*n);
	
};

#endif /* BSTREE_H_ */
