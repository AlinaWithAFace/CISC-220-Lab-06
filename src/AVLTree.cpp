//
// Created by Alina on 2017-11-04.
//

#include <iostream>
#include "AVLTree.hpp"

using namespace std;


/**
 * constructor
 * @param flag
 */
AVLTree::AVLTree(bool flag) {
	root = NULL;
	avlFlag = flag;
}

/**
 * Calls findWord using the NodeT root
 * @param s
 * @return Whether or not the string is in the binary search tree.
 */
bool AVLTree::findWord(string s) {
	findWord(s, root);
}

/**
 * Finds whether s is in the binary search tree.
 * Returns true (if found) and false otherwise.
 * Note: I called this with the root so that this method could be recursive.
 * It doesn't have to be.
 * If you prefer to write this iteratively, you won’t need the NodeT pointer as a parameter.
 * @param s
 * @param n
 * @return
 */
bool AVLTree::findWord(string s, NodeT *n) {
	//TODO: this is broken, it has an infinite loop somewhere, probably when it tries to call itself.
	if (s == n->word) {
		cout << s << " found" << endl;
		return true;
	} else if (s == n->left->word) {
		cout << s << " found with parent " << n->word << endl;
		return true;
	} else if (s == n->right->word) {
		cout << s << " found with parent " << n->word << endl;
		return true;
	} else if (findWord(s, n->left)) {
		return true;
	} else if (findWord(s, n->right)) {
		return true;
	} else {
		cout << s << " not found" << endl;
		return false;
	}
}

/**
 * Calls addNode starting at the root NodeT
 * @param newString
 */
void AVLTree::addNode(string newString) {
	cout << endl;
	cout << "Adding: " << newString << endl;
	addNode(newString, root);
}

/**
 * Adding newString to the tree.
 * Again, if done recursively, you’ll need a NodeT address as a parameter.
 * If not, you won’t.
 * @param newString The string to add to the tree
 * @param adoptiveParent The potential parent node for the newString.
 */
void AVLTree::addNode(string newString, NodeT *adoptiveParent) {
	//TODO: Uh, crap, it's a toggleable AVL tree. This could get... complicated.
	// Great, it's a normal binary search tree, we don't have to do anything fancy.
	// This is really complicated and nested though, there might be a better way to deal with this mass of nested ifelses.
	// TODO: the heights are all wrong, fix it
	if (root == NULL) {
		root = new NodeT(newString);
		cout << "Made root" << endl;
	} else if (newString == adoptiveParent->word) {
		//cout << newString << " is equal to " << adoptiveParent->word << endl;
		return;
	} else if (newString > adoptiveParent->word) {
		//cout << newString << " is greater than " << adoptiveParent->word << endl;
		if (adoptiveParent->right == NULL) {
			cout << "Inserting to right of " << adoptiveParent->word << endl;
			adoptiveParent->right = new NodeT(newString);
			adoptiveParent->right->parent = adoptiveParent;
		} else {
			cout << "Looking right of " << adoptiveParent->word << endl;
			(addNode(newString, adoptiveParent->right));
		}
	} else if (newString < adoptiveParent->word) {
		//cout << newString << " is less than " << adoptiveParent->word << endl;
		if (adoptiveParent->left == NULL) {
			cout << "Inserting to left of " << adoptiveParent->word << endl;
			adoptiveParent->left = new NodeT(newString);
			adoptiveParent->left->parent = adoptiveParent;
		} else {
			cout << "Looking left of " << adoptiveParent->word << endl;
			(addNode(newString, adoptiveParent->left));
		}
	}
}

/**
 * Call printIO starting at the root
 */
void AVLTree::printIO() {
	printIO(root);
	cout << endl;
}


/**
 * Print the tree in order recursively
 * @param aNode
 */
void AVLTree::printIO(NodeT *aNode) {
	if (aNode == NULL) { return; }
	printIO(aNode->left);
	aNode->printTNode();
	printIO(aNode->right);
}

/**
 * Call printPre starting at the root
 */
void AVLTree::printPre() {
	printPre(root);
	cout << endl;
}

/**
 * Print the tree in pre order recursively
 * @param aNode
 */
void AVLTree::printPre(NodeT *aNode) {
	if (aNode == NULL) { return; }
	aNode->printTNode();
	printPre(aNode->left);
	printPre(aNode->right);
}

/**
 * Call printPost starting at the root
 */
void AVLTree::printPost() {
	printPost(root);
	cout << endl;
}

/**
 * Print the tree in post order recursively
 * @param aNode
 */
void AVLTree::printPost(NodeT *aNode) {
	if (aNode == NULL) { return; }
	printPost(aNode->left);
	printPost(aNode->right);
	aNode->printTNode();
}


/**
 * Starting with the node you just inserted, adjust the heights of its parents/grandparents/great… until a great… grandparent node’s height doesn’t change.
 * If the AVLTree flag is set, this method also checks balances and, if a node is unbalanced, calls the appropriate rotation(s) and re-adjusts heights and checks balances from that node up.
 * To adjust heights at any moment, you get the max of the height of the left child and the height of the right child, and add 1.
 * MAKE SURE you attach the newly rotated top node to the parent above it.
 * @param n
 */
void AVLTree::adjustHeights(NodeT *n) {
//TODO
}


/**
 * This method is a little helper method that determines the max height between the left child and the right child and returns that height.
 * @param n
 * @return
 */
int AVLTree::getMax(NodeT *n) {
	//TODO
	return 0;
}
