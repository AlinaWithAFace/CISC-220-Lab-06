/*
 * NodeL.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: Debra
 */

#include "NodeL.hpp"
#include <string>
#include <iostream>

using namespace std;

NodeL::NodeL(string s) {
	next = NULL;
	prev = NULL;
	word = s;
	wscore = 0;
	count = 0;
}

NodeL::~NodeL() {
	cout << "Deleting " << word << endl;
	if (next != NULL) {
		cout << "Next not null: Memory leak?" << endl;
	}
	if (prev != NULL) {
		cout << "Prev not null: Memory leak?" << endl;
	}
}
