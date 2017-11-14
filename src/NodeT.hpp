/*
 * NodeT.hpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Debra
 */

#ifndef NodeT_HPP_
#define NodeT_HPP_

#include <string>

using namespace std;

class NodeTree {
	friend class AvlTree;

public:
	string word;
	int height;
	NodeTree *left;
	NodeTree *right;
	NodeTree *parent;


	NodeTree(string aWord);

	~NodeTree();

	void printTreeNode();
};


#endif /* NodeT_HPP_ */
