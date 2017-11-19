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
	//testGame();

	///

//	srand(time(NULL));
//
	Game *testDictBST = new Game("testdict.txt", false);
//
//	cout << "****************************" << endl;
//
//	Game *commonDictBST = new Game("commondict.txt", false);
//	commonDictBST->startGame();
//
//	cout << "****************************" << endl;
//
//	Game *testDictAvl = new Game("testdict.txt", true);
//
//	cout << "****************************" << endl;
//
//	Game *commonDictAvl = new Game("commondict.txt", true);
//	commonDictAvl->startGame();

	return 0;
}


void testAVLTree() {

	AVLTree testBst(false);

	testBst.addNode("32");
	testBst.addNode("17");
	testBst.addNode("24");
	testBst.addNode("12");
	testBst.addNode("15");
	testBst.addNode("20");
	testBst.addNode("19");
	testBst.addNode("2");
	testBst.addNode("7");

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