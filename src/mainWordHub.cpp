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

using namespace std;

int main() {

	srand(time(NULL));

	AVLTree testBst(false);

	testBst.addNode("5");

	//testBst.root->printTNode();

	testBst.addNode("6");
	testBst.addNode("4");
	testBst.addNode("3");
	testBst.addNode("9");
	testBst.addNode("8");
	testBst.addNode("8");
    NodeT *testNode = new NodeT("david");
    // single node return 0 so this mean the method work.
    cout<<testBst.getMax(testNode) <<endl;
    //return 0
    NodeT *testNode2 = new NodeT("bill");
    cout<<testBst.getMax(testNode2) <<endl;


	cout << (testBst.findWord("4")) << endl;
	cout << (testBst.findWord("7")) << endl;
	//cout << (testBst.findWord("3")) << endl;

	//Game *game = new Game("commondict.txt", true);
	//game->startGame();

	Game *testGame = new Game("testdict.txt", false);
	testGame->startGame();
    testGame->startGame();



	return 0;
}

