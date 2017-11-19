/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


//#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"

void testAVLTree();

void testGame();

void testLL();

using namespace std;

int main() {

	//testLL();

	//testAVLTree();
	testGame();

	///

	srand(time(NULL));

	//Game *game = new Game("commondict.txt", true);
	//game->startGame();

	return 0;
}


void testAVLTree() {

	AVLTree testBst(false);

	testBst.addNode("5");

	//testBst.root->printTNode();
    NodeT *testrotate;

	testBst.addNode("6");
	testBst.addNode("4");
	testBst.addNode("3");
	testBst.addNode("9");
	testBst.addNode("8");
	testBst.addNode("8");
	NodeT *testNode = new NodeT("david");
	// single node return 0 so this mean the method work.
	cout << testBst.getMax(testNode) << endl;
	//return 0
	NodeT *testNode2 = new NodeT("bill");
	cout << testBst.getMax(testNode2) << endl;

	string testString = "7";

//	if (testBst.findWord(testString)) {
//		cout << "Found " << testString << endl;
//	} else {
//		cout << "Couldn't find " << testString << endl;
//	}

	testBst.printIO();
	testBst.printPre();
	testBst.printPost();
};

void testGame() {
	Game *testGame = new Game("testdict.txt", false);
	testGame->startGame();
}

void testLL() {
	LL *testLL = new LL();
	testLL->push("fly", 1);
	testLL->push("so", 1);
	testLL->push("of", 1);
	testLL->push("fool", 1);
	testLL->push("soy", 1);
	testLL->push("sly", 1);
	testLL->push("joy", 1);
	cout << endl;
	testLL->printList();
}