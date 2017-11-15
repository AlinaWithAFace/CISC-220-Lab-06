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

class NodeL {
	friend class LL;
	friend class Game;
	string word;
	int wscore;
	NodeL *next;
public:
	NodeL(string w);
	~NodeL();

	__attribute__((__deprecated__))
	int count;
};




#endif /* SNodeL_HPP_ */
