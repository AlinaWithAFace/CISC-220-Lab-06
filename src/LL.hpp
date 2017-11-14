//
// Created by Alina on 2017-11-14.
//

#ifndef CISC_220_LAB_06_LL_H
#define CISC_220_LAB_06_LL_H


#include <string>
#include "NodeL.hpp"

using namespace std;

class LL {

public:
	void printList();

	void getScore();

	int score;

	void push(string basic_string);

	NodeL *first;
};


#endif //CISC_220_LAB_06_LL_H
