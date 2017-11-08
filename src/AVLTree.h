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

	/**
	 * Starting with the node you just inserted, adjust the heights of its parents/grandparents/great… until a great… grandparent node’s height doesn’t change.
	 * If the AVLTree flag is set, this method also checks balances and, if a node is unbalanced, calls the appropriate rotation(s) and re-adjusts heights and checks balances from that node up.
	 * To adjust heights at any moment, you get the max of the height of the left child and the height of the right child, and add 1. MAKE SURE you attach the newly rotated top node to the parent above it.
	 * @param n
	 */
	void adjustHeights(NodeT *n);

	/**
	 * This method is a little helper method that determines the max height between the left child and the right child and returns that height.
	 * @param n
	 * @return
	 */
	int getMax(NodeT *n);

};


#endif //CISC_220_LAB_06_AVLTREE_H
