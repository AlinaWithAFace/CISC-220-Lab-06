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

	testAVLTree();
	testGame();

	///
    /*
	srand(time(NULL));
	Game *testDictBST = new Game("testdict.txt", false);
	cout << "****************************" << endl;
	Game *commonDictBST = new Game("commondict.txt", false);
	commonDictBST->startGame();
	cout << "****************************" << endl;
	Game *testDictAvl = new Game("testdict.txt", true);
	cout << "****************************" << endl;
    Game *commonDictAvl = new Game("commondict.txt", true);
	commonDictAvl->startGame();
    */
	return 0;
}


void testAVLTree() {

	//AVLTree testBst(false);
//
//	testBst.addNode("32");
//	testBst.addNode("17");
//	testBst.addNode("24");
//	testBst.addNode("12");
//	testBst.addNode("15");
//	testBst.addNode("20");
//	testBst.addNode("19");
//	testBst.addNode("2");
//	testBst.addNode("7");
//
	//testBst.printIO();
	//testBst.printPre();
	//testBst.printPost();

	/// Thanks internet https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct

//	AVLTree rotationTestTreeGoal(true);
//	rotationTestTreeGoal.addNode("b");
//	rotationTestTreeGoal.addNode("a");
//	rotationTestTreeGoal.addNode("c");
//	rotationTestTreeGoal.printIO();

	AVLTree rotationTestTree1L(true);

	rotationTestTree1L.addNode("a");
	rotationTestTree1L.addNode("b");
	rotationTestTree1L.addNode("c");
	rotationTestTree1L.printIO();

	AVLTree rotationTestTree1R(true);

	rotationTestTree1R.addNode("c");
	rotationTestTree1R.addNode("b");
	rotationTestTree1R.addNode("a");
	rotationTestTree1R.printIO();

//	AVLTree rotationTestTree2L(true);
//
//	rotationTestTree2L.addNode("a");
//	rotationTestTree2L.addNode("c");
//	rotationTestTree2L.addNode("b");
//	rotationTestTree2L.printIO();
//
//	AVLTree rotationTestTree2R(true);
//
//	rotationTestTree2R.addNode("c");
//	rotationTestTree2R.addNode("a");
//	rotationTestTree2R.addNode("b");
//	rotationTestTree2R.printIO();

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