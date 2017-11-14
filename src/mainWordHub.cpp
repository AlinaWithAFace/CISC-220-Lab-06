/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


////#include "AvlTree.hpp"
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <fstream>
//#include "Game.hpp"

#include <iostream>
#include <time.h>
#include <fstream>
#include "Game.hpp"

using namespace std;

int main() {

	srand(time(NULL));

	Game *game;
	string dictionaryPath = "resources/commondict.txt";

	ifstream file(dictionaryPath.c_str());
	if (file.is_open()) {
		cout << "Reading succeeded: " << dictionaryPath << endl;
	} else {
		cout << "Reading failed: " << dictionaryPath << endl;
	}

	game = new Game(dictionaryPath, true);
	//game->startGame();





	return 0;
}

