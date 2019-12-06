/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
    Customer data;
    Node* left;
    Node* right;
   
    // Default Constructor
    Node();

    // Augmented Constructor
    Node(string x, char y, int z);
};

#endif /* NODE_H_ */
