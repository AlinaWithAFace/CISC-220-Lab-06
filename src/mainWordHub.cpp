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

	testBst.root->printTNode();

	testBst.addNode("6");
	testBst.addNode("4");
	testBst.addNode("3");
	testBst.addNode("9");
	testBst.addNode("8");
	testBst.addNode("8");

	//Game *game = new Game("commondict.txt", true);
	//game->startGame();

	return 0;
}

