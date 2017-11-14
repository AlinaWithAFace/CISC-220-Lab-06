//
// Created by Alina on 2017-11-14.
//

#ifndef CISC_220_LAB_06_AVLTREE_H
#define CISC_220_LAB_06_AVLTREE_H


#include <string>

using namespace std;

class AVLTree {

public:
	AVLTree(bool i);

	bool findWord(string basic_string, int param);

	int root;

	void printIO(int i);

	void printPre(int i);

	void printPost(int i);

	void addNode(string basic_string, int i);
};


#endif //CISC_220_LAB_06_AVLTREE_H
