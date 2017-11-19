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
	bool foundWord = false;
	NodeT *aNode = n;
	//cout << "\nFinding " << s << "..." << endl;

	while (aNode != NULL) {

		if (s == aNode->word) {
			foundWord = true;
			aNode = NULL;
		} else if (s < aNode->word) {
			//cout << "Checking left of " << aNode->word << endl;
			aNode = aNode->left;
		} else if (s > aNode->word) {
			//cout << "Checking right of " << aNode->word << endl;
			aNode = aNode->right;
		}
	}
	//cout << (foundWord ? "Found " : "Couldn't find ") << s << endl;

	return foundWord;
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
	NodeT *babyNode = new NodeT(newString);
	if (root == NULL) {
		root = babyNode;
		cout << "Made root" << endl;
	} else if (newString == adoptiveParent->word) {
		//cout << newString << " is equal to " << adoptiveParent->word << endl;
		return;
	} else if (newString > adoptiveParent->word) {
		//cout << newString << " is greater than " << adoptiveParent->word << endl;
		if (adoptiveParent->right == NULL) {
			cout << "Inserting to right of " << adoptiveParent->word << endl;
			adoptiveParent->right = babyNode;
			adoptiveParent->right->parent = adoptiveParent;
		} else {
			cout << "Looking right of " << adoptiveParent->word << endl;
			(addNode(newString, adoptiveParent->right));
		}
	} else if (newString < adoptiveParent->word) {
		//cout << newString << " is less than " << adoptiveParent->word << endl;
		if (adoptiveParent->left == NULL) {
			cout << "Inserting to left of " << adoptiveParent->word << endl;
			adoptiveParent->left = babyNode;
			adoptiveParent->left->parent = adoptiveParent;
		} else {
			cout << "Looking left of " << adoptiveParent->word << endl;
			(addNode(newString, adoptiveParent->left));
		}
	}

	adjustHeights(babyNode); // Set the heights
}

/**
 * Call printIO starting at the root
 */
void AVLTree::printIO() {
	cout << "\nPrinting In-order: " << endl;
	printIO(root);
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
	cout << "\nPrinting Pre-order: " << endl;
	printPre(root);
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
	cout << "\nPrinting Post-order: " << endl;
	printPost(root);
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
//right rotation code taken from powerpoint
NodeT *rightRotate(NodeT *n) {
	NodeT *x = n->left;
	NodeT *tmp = n->right;
	x->right = n;
	n->left = tmp;
	//update height
	if (n->left->height > n->right->height) {
		n->height = n->left->height + 1;
	} else {
		n->height = n->right->height + 1;
	}
	if (x->left->height > x->right->height) {
		x->height = x->left->height + 1;
	} else {
		x->height = x->right->height + 1;
	}
	return x; // new root


}

/**
 * Rotates to the left.
 * @param n
 * @return
 */
NodeT *leftRotate(NodeT *n) {
	NodeT *x = n->right;
	NodeT *tmp = n->left;
	x->left = n;
	n->right = tmp;
	//update height
	if (n->left->height > n->right->height) {
		n->height = n->left->height + 1;
	} else {
		n->height = n->right->height + 1;
	}
	if (x->left->height > x->right->height) {
		x->height = x->left->height + 1;
	} else {
		x->height = x->right->height + 1;
	}
	return x; // new root
}


/**
 * Adjusts the heights of a given NodeT and all of its parents.
 * For example, if a node has just been added:
 * It should have a height of 1, its parents should have a height of 2, its grandparents should have a height of 3, etc.
 * In this case, 0 means a height has been unassigned. Valid heights cannot be below 1.
 * If the parent's height is unchanged, for example if you try to change a grandparent's height to 3, but it's already 3, we can stop
 * (since presumably everything else above it is already set properly)
 * @param n
 */
void AVLTree::adjustHeights(NodeT *n) {
	n->height = 1;
	int childHeights = n->height;

	NodeT *aNode = n->parent;
	while (aNode != NULL) {

		childHeights++;
		//cout << aNode->word << "'s height is currently " << aNode->height << flush;

		if (childHeights == aNode->height) {
			return; // If it's what we were going to change it to anyway, stop, because everything else above it should be okay.
		} else {
			// TODO: this doesn't quite work, it only updates it with the child's height if it's smaller
			// so if something gets deleted this will break


			cout << aNode->word << "'s current height: " << aNode->height << flush;
			cout << ", trying to update height to: " << childHeights << endl;
			int newHeight = childHeights;
			newHeight = 1 + getMaxHeight(aNode);

			cout << "Setting height to " << newHeight << endl;

			aNode->height = newHeight;

			if (avlFlag) {
				// if it's an AVL tree, we need to rotate things to keep it balanced if the balance if off
				//TODO build rotations
				// adjust height of childs
				//check balance
				// if flag is true check balance
				// adjust parent and grandparent node
			}
		}
		aNode = aNode->parent;
	}
}

/**
 * This method is a little helper method that determines the max height between the left child and the right child and returns that height.
 * @param n
 * @return
 */
int AVLTree::getMaxHeight(NodeT *n) {
	int maxHeight;
	//cout << "Checking " << n->word << "'s child nodes for max..." << endl;

	if (n->left == NULL && n->right == NULL) {
		//cout << "Neither left nor right exist. What gives?" << endl;
		maxHeight = 0;
	}
	if (n->right == NULL) {
		//cout << "Right NULL" << endl;
		maxHeight = n->left->height;
	} else {
		//cout << "Right exists: " << flush;
		//n->right->printTNode();
	}

	if (n->left == NULL) {
		//cout << "Left NULL" << endl;
		maxHeight = n->right->height;

	} else {
		//cout << "Left exists: " << flush;
		//n->left->printTNode();
	}

	if (n->left != NULL && n->right != NULL) {
		if (n->left->height >= n->right->height) {
			//cout << "Left is greater than right" << endl;
			maxHeight = n->left->height;
		} else {
			//cout << "Right is greater than left" << endl;
			maxHeight = n->right->height;
		}
	}
	return maxHeight;
}
