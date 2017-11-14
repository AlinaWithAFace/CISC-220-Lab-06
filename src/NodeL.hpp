/*
 * NodeL.hpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Debra
 */

#ifndef NodeL_HPP_
#define NodeL_HPP_

#include <string>
#include <iostream>

using namespace std;

class NodeLinkedList {
	friend class LL;
	friend class Game;

	NodeLinkedList *next;
	NodeLinkedList *prev;
	string word;
	int wscore;
	int count; // Depreciated

public:
	NodeLinkedList(string w);

	~NodeLinkedList();

};


#endif /* SNodeL_HPP_ */
