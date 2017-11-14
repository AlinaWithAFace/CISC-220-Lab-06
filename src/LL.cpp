/*
 * LLSE.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: alinac
 */

#include <math.h>
#include <iomanip>
#include "LL.hpp"

using namespace std;

/**
 * (3 pts)
 * Constructor - sets to NULL and 0, respectively
 */
LL::LL() {
	first = NULL;
	last = NULL;
	size = 0;
	wordcount = 0;
	score = 0;
}

/**
 * (6 pts)
 * Destructor - goes through whole list and deletes
 */
LL::~LL() {
	NodeLinkedList *aNode;
	while (first != NULL) {
		aNode = first->next;
		first->next = NULL;
		delete first;
		size--;
		first = aNode;

	}
}


/**
 * (5 pts)
 * For each node, prints word, and count
 */
void LL::printList() {
	NodeLinkedList *aNode = first;
	int printWordCount = 0;

	std::cout << std::fixed;
	std::cout << std::setprecision(4);

	while (aNode != NULL) {
		cout << aNode->word;
		cout << ":";
		cout << aNode->count << ", ";
		aNode = aNode->next;

		if (printWordCount > 4) {
			cout << endl;
			printWordCount = 0;
		} else {
			printWordCount++;
		}
	}
	cout << endl;
	cout << endl;
	cout << "first is " << first->word << ", last is " << last->word << endl;
	cout << "size is now " << size << endl;
	cout << "wordcount is now " << wordcount << endl;
}

/**
 * (5 pts)
 * Adds very first node to list
 */
void LL::addFirst(string x) {
	if (first == NULL) {
		first = new NodeLinkedList(x);
		first->next = NULL;
		last = first;
		size++;
	}
}

/**
 * (6 pts)
 * Adds new node to beginning of list
 */
void LL::addAtFirst(string x) {
	if (first != NULL) {
		NodeLinkedList *newNode = new NodeLinkedList(x);
		newNode->next = first;
		first = newNode;
		size++;
	}
}

/**
 * (6 pts)
 * Adds node to end of list
 */
void LL::push(string x) {
	NodeLinkedList *newNode = new NodeLinkedList(x);
	last->next = newNode;
	last = newNode;
	size++;
}

/**
 * (7 pts)
 * This method finds and returns the node right before where you should insert the new word into the list.
 * If the word is already in the list, it increases that word's count and returns NULL.
 */
NodeLinkedList *LL::findInsert(string x) {
	NodeLinkedList *momNode = first; // Find the node address that x could be inserted after this node
	while (momNode != NULL) {
		if (x == momNode->word) { // If the word is already in the list, increase that word's count and return NULL
			//cout << x << " is already in list, increasing count." << endl;
			momNode->count++;
			return NULL;

		}
		if (x > momNode->word) { // If the word is "greater than" the current word...
			//cout << x << " is greater than " << momNode->word << endl;
			if (momNode->next == NULL) {
				//cout << momNode->word << " is last, inserting " << x << endl;
				return momNode; // Or if it's the last one in the list, then it doesn't have anywhere else to go but the end.
			}
			if (x < momNode->next->word) {
				//cout << x << " is less than " << momNode->next->word << endl;
				return momNode; // And "less than" the next word, we have our node! Probably.
			}
		}
		momNode = momNode->next;

	}
}

/**
 * (12 pts)
 * This method is the heart of the linked list class.
 * It inserts each word alphabetically into the linked list as follows:
 * If the word is the first in the list, it calls addFirst to create the very first node for the list
 * If the word occurs alphabetically before the first word in the list, it calls addAtFirst to add a new node to the beginning of the list.
 * Otherwise it calls the findInsert method (below), which should return the address of the Node that occurs alphabetically right BEFORE where you will be inserting your new node.
 *
 * Note: if findInsert finds that the word already exists in the list, it increases the count of that word's node, and returns NULL.
 * If the word occurs alphabetically at the end of the list (the Node returned from findInsert is equal to the last node in the list), this calls the push method to insert the new node at the end of the list.
 */
void LL::insertUnique(string x) {
	if (size == 0 | first == NULL) {
		addFirst(x);
		wordcount++;
	} else if (x < first->word) {
		addAtFirst(x);
		wordcount++;
	} else {
		NodeLinkedList *momNode = findInsert(x);
		NodeLinkedList *newNode = new NodeLinkedList(x);
		if (momNode == NULL) {
			// amazing, it's already in the list, we don't need to do anything from here
			wordcount++;
		} else if (momNode == last) {
			push(x);
			wordcount++;
		} else {
			NodeLinkedList *babyNode = momNode->next;
			momNode->next = newNode;
			newNode->next = babyNode;
			size++;
			wordcount++;
		}
	}
}

/**
 * (6 pts)
 * Traverses list and normalizes counts by dividing by the total wordcount
 */
void LL::normalizeCounts() {
	NodeLinkedList *aNode = first;
	while (aNode != NULL) {
		aNode->count = (aNode->count / wordcount);
		aNode = aNode->next;
	}
}

/**
 * (6 pts)
 * Removes the very first node in the list
 */
string LL::remFirst() {
	NodeLinkedList *aNode = first;
	string aString = aNode->word;

	first = aNode->next;
	aNode->next = NULL;

	delete aNode;
	size--;

	return aString;
}

/**
 * (5 pts)
 * Removes the last node in the list
 */
string LL::pop() {
	string aString;
	NodeLinkedList *beforeLast = first;
	for (int i = 0; i < size - 2; i++) {
		beforeLast = beforeLast->next; // Iterate through to find the node right before the last node
	}
	aString = beforeLast->next->word;

	cout << "removing " << beforeLast->next->word << endl;
	delete beforeLast->next;
	size--;

	last = beforeLast;
	last->next = NULL;

	return aString;
}

/**
 * (8 pts)
 * Removes the node after n in the list
 */
string LL::remNext(NodeLinkedList *n) {
	string aString = n->next->word;

	NodeLinkedList *aNode = n->next;
	n->next = aNode->next;
	aNode->next = NULL;

	delete aNode;
	size--;
	return aString;
}

/**
 * (10 pts)
 * Traverses the list and removes every node whose normalized count is below .4%.
 * This method should call the above remNext method();
 */
void LL::eliminateLowWords() {
	NodeLinkedList *aNode = first;

	int threshold = 4;

	while (aNode != NULL) {
		bool atFirst = aNode == first;
		bool nextExists = aNode->next != NULL;

//		cout << "aNode: " << aNode->word << ", count: " << (int) ((aNode->count) * 10000) << ", ";
//		if (nextExists) {
//			cout << "next: " << aNode->next->word << ", count: " << (int) ((aNode->next->count) * 10000) << ", " << endl;
//		}

		if (atFirst && (threshold > (int) (aNode->count * 1000))) {
			remFirst();
			aNode = first;
		} else {
			if (nextExists && (threshold > (int) (aNode->next->count * 1000))) {
				remNext(aNode);
			} else if (nextExists) {
				aNode = aNode->next;
			} else {
				aNode = NULL;
			}
		}

	}
}

/**
 * This is the new method – each word already has a score.
 * This method just traverses the linked list from the first to the last node and keeps a running total of the wscore of each node.
 * Then the score field is set to that total.
 */
void LL::getScore() {

}

