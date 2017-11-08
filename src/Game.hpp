/*
 * Game.hpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "AVLTree.h"
#include "LL.hpp"
#include "AVLTree.h"
#include <iostream>
#include <string>

class Game {
	friend class NodeL;
	bool AVL;
	AVLTree *dict;
	int numletters;
	char *currletters;
	//int numright;
	//int totalwords;
	int score;
	LL wordlist;
	string dictfile;
public:
	Game();

	Game(string filePath, bool AVLflag);

	void startGame();

	void getScore();

	void readTreeFromFile();

	char *getLetters(int x);

	void getWords();

	bool checkWLetters(string s);

	void checkWordsForScore();
};

#endif /* GAME_HPP_ */
