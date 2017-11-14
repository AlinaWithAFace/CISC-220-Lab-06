/*
 * NodeT.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Debra
 */

#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

NodeTree::NodeTree(string aWord) {
	word = aWord;
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 0;
}

NodeTree::~NodeTree() {
	if ((left != NULL) || (right != NULL)) {
		cout << "deleting may leave dangling Tree Nodes" << endl;
	}
}

void NodeTree::printTreeNode() {
	cout << "|" << height << ":" << word << "| " << endl;
}


