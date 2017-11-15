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

	if (avlFlag) {
		//TODO: Uh, crap, it's an AVL tree. This could get... complicated.
	} else {
		// Great, it's a normal binary search tree, we don't have to do anything fancy.
		// This is really complicated and nested though, there might be a better way to deal with this mass of nested ifelses.
		if (root == NULL) {
			root = new NodeT(newString);
		} else if (newString == adoptiveParent->word) {
			cout << newString << " is equal to " << adoptiveParent->word << endl;
			return;
		} else if (newString > adoptiveParent->word) {
			cout << newString << " is greater than " << adoptiveParent->word << endl;
			if (adoptiveParent->right == NULL) {
				adoptiveParent->right = new NodeT(newString);
				adoptiveParent->right->parent = adoptiveParent;
				cout << "added " << newString << " with parent " << adoptiveParent->word << " on the right" << endl;
			} else {
				(addNode(newString, adoptiveParent->right));
			}
		} else if (newString < adoptiveParent->word) {
			cout << newString << " is less than " << adoptiveParent->word << endl;
			if (adoptiveParent->left == NULL) {
				adoptiveParent->left = new NodeT(newString);
				adoptiveParent->left->parent = adoptiveParent;
				cout << "added " << newString << " with parent " << adoptiveParent->word << " on the left" << endl;
			} else {
				(addNode(newString, adoptiveParent->left));
			}
		}
	}
}

void AVLTree::printIO(NodeT *root) {
	//TODO

}

void AVLTree::printPre(NodeT *root) {
	//TODO

}

void AVLTree::printPost(NodeT *root) {
	//TODO

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
