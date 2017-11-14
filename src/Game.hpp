/*
 * Game.hpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "AvlTree.hpp"
#include "LL.hpp"
#include "AvlTree.hpp"
#include <iostream>
#include <string>

class Game {
	friend class NodeLinkedList;

	bool gameAvlFlag;
	AvlTree *dictionary;
	int numLetters;
	char *currentLetters;
	//int numRight;
	//int totalWords;
	int gameScore;
	LinkedList wordList;
	string dictionaryFilePath;
public:
	Game();

	Game(string filePath, bool avlFlag);

	void startGame();

	void getScore();

	void readTreeFromFile();

	char *getLetters(int x);

	void getWords();

	bool checkWLetters(string s);

	void checkWordsForScore();


};

#endif /* GAME_HPP_ */
