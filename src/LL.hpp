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

class LinkedList {
	friend class Game;
	friend class Document;

	NodeLinkedList *first;
	NodeLinkedList *last;
	int size;
	int wordcount; // Depreciated

public:
	int score;   // This field is for the game’s gameScore, and will be set using a getScore method, below.  It should be initialized in the constructor to 0.

	LinkedList();

	~LinkedList();

	void printList();

	void addFirst(string x);

	void addAtFirst(string x);

	void push(string x);

	NodeLinkedList *findInsert(string x);

	void insertUnique(string x);

	void normalizeCounts();

	string remFirst();

	string pop();

	string remNext(NodeLinkedList *n);

	void eliminateLowWords();

	void getScore();
};


#endif /* LLSE_HPP_ */
