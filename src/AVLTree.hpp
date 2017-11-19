//
// Created by Alina on 2017-11-04.
//

#ifndef CISC_220_LAB_06_AVLTREE_H
#define CISC_220_LAB_06_AVLTREE_H


#include "NodeT.hpp"

class AVLTree {

	friend class Game;

	NodeT *root;  // holds the root of the bst

	bool avlFlag; // flag for whether to adjust bst to be an avl tree

	///

	bool findWord(string s, NodeT *n);

	void addNode(string newString, NodeT *adoptiveParent);

	///

	void printIO(NodeT *aNode);

	void printPre(NodeT *aNode);

	void printPost(NodeT *aNode);

public:

	int getMax(NodeT *n);

    NodeT *rightRotate(NodeT *n);

    NodeT *leftRotate(NodeT *n);

	explicit AVLTree(bool flag);

	bool findWord(string s);

	void addNode(string newString);

	void printIO();

	void printPre();

	void printPost();

	void adjustHeights(NodeT *n);


};


#endif //CISC_220_LAB_06_AVLTREE_H
