/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"
#include <cstdio>

// Default Constructor
Node::Node() {
    right = NULL;
    left = NULL;
}

// Augmented Constructor
Node::Node(string x, char y, int z) {
    data = Customer (x, y , z);
    right = NULL;
    left = NULL;
}
