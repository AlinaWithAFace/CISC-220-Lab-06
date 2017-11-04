//
// Created by Alina on 2017-11-04.
//

#ifndef CISC_220_LAB_06_AVLTREE_H
#define CISC_220_LAB_06_AVLTREE_H


#include "NodeT.hpp"

class AVLTree {

public:

	NodeT *root;  // holds the root of the bst
	bool AVLflag; // flag for whether to adjust bst to be an avl tree

	/**
	 * constructor
	 * @param flag
	 */
	AVLTree(bool flag);

	/**
	 * Finds whether s is in the bst.
	 * Returns true (if found) and false otherwise.
	 * Note:  I called this with the root so that this method could be recursive.
	 * It doesn’t have to be.
	 * If you prefer to write this iteratively, you won’t need the NodeT pointer as a parameter.
	 * @param s
	 * @param n
	 * @return
	 */
	bool findWord(string s, NodeT *n);

	/**
	 * Adding s to the tree.
	 * Again, if done recursively, you’ll need a NodeT address as a parameter.
	 * If not, you won’t.
	 * @param s
	 * @param r
	 */
	void addNode(string s, NodeT *r);

	void printIO(NodeT *root);

	void printPre(NodeT *root);

	void printPost(NodeT *root);

};


#endif //CISC_220_LAB_06_AVLTREE_H
