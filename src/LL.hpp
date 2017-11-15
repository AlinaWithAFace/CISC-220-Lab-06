/*
 * LLSE.hpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */

#ifndef LLSE_HPP_
#define LLSE_HPP_


#include "NodeL.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class LL {
	friend class Game;

	friend class Document;

	NodeL *first;
	NodeL *last;
	int size;

	__attribute__((__deprecated__))
	int wordcount;

public:
	int score;   // This field is for the game’s gameScore, and will be set using a getScore method, below.  It should be initialized in the constructor to 0.

	__attribute__((__deprecated__))
	LL();

	__attribute__((__deprecated__))
	~LL();

	__attribute__((__deprecated__))
	void printList();

	__attribute__((__deprecated__))
	void addFirst(string x);

	__attribute__((__deprecated__))
	void addAtFirst(string x);

	__attribute__((__deprecated__))
	void push(string x);

	__attribute__((__deprecated__))
	NodeL *findInsert(string x);

	__attribute__((__deprecated__))
	void insertUnique(string x);

	__attribute__((__deprecated__))
	void normalizeCounts();

	__attribute__((__deprecated__))
	string remFirst();

	__attribute__((__deprecated__))
	string pop();

	__attribute__((__deprecated__))
	string remNext(NodeL *n);

	__attribute__((__deprecated__))
	void eliminateLowWords();

	__attribute__((__deprecated__))
	void getScore();
};


#endif /* LLSE_HPP_ */
