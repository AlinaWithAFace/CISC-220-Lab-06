/*
 * Game.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#include <iostream>
#include "AVLTree.hpp"
#include "Game.hpp"
#include "LL.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Game::Game() {
	Game("dict.txt", false);
}

Game::Game(string filen, bool AVLflag) {
	AVL = AVLflag;
	dictfile = filen;
	readTreeFromFile();
	cout << "\nPrinting In-order: " << endl;
	dict->printIO();
	cout << "\nPrinting Pre-order: " << endl;
	dict->printPre();
	cout << "\nPrinting Post-order: " << endl;
	dict->printPost();
	numletters = 0;
	//numright = 0;
	//totalwords = 0;
//	wordlist = new LL();
}

void Game::startGame() {
	cout << "\nHow many letters do you want?" << endl;
	cin >> numletters;
	currletters = getLetters(numletters);
	cout << "Your letters are: " << endl;
	for (int i = 0; i < numletters; i++) {
		cout << currletters[i] << " ";
	}
	cout << endl;
	cout << "Start generating words: " << endl;
	getWords();
	wordlist.printList();
	checkWordsForScore();
	wordlist.printList();
	wordlist.getScore();
	cout << "Final Score is: " << wordlist.score << endl;

	//int score = numright * 3 - (totalwords-numright) * 6;
	//cout << "Number of valid words: " << numright << " Invalid words: " << (totalwords = numright) << endl;
	//cout << "Final Score is: "  << score << endl;
}


void Game::getWords() {
	string s;
	cin >> s;
	while (s != "-1") {
		wordlist.push(s);
		cin >> s;
		//cout << endl;
	}
}

char *Game::getLetters(int x) {
	char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
	char conso[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	char *curr = new char[x];
	int v = rand() % (x - 1) + 1;

	for (int i = 0; i < v; i++) {
		int y = rand() % 5;
		curr[i] = vowel[y];
	}
	for (int i = v; i < x; i++) {
		int y = rand() % 21;
		curr[i] = conso[y];
	}
	return curr;
}

bool Game::checkWLetters(string s) {
	char tempchar[numletters];
	for (int i = 0; i < numletters; i++) {
		tempchar[i] = currletters[i];
	}
	for (int i = 0; i < s.size(); i++) {
		int j = 0;
		while ((j < numletters) && (tolower(s[i]) != tempchar[j])) {
			j++;
		}
		if (j == numletters) {
			return false;
		}
		tempchar[j] = '1';
	}
	return true;
}

void Game::checkWordsForScore() {
	NodeL *tmp = wordlist.first;
	while (tmp != NULL) {
		if (checkWLetters(tmp->word)) {
			cout << tmp->word << " is okay letter wise" << endl;

			if (dict->findWord(tmp->word, dict->root)) {
				cout << tmp->word << " is in tree" << endl;
				tmp->wscore = 1;
			} else {
				cout << tmp->word << " is NOT in tree" << endl;
				tmp->wscore = -1;
			}
		} else {
			cout << tmp->word << " is NOT okay letter wise" << endl;
			tmp->wscore = -1;
		}
		tmp = tmp->next;
	}
}

void Game::readTreeFromFile() {
	dict = new AVLTree(AVL);
	ifstream file(dictfile.c_str());

	if (!file.is_open()) {
		cout << "Couldn't read " << dictfile << ", aborting..." << endl;
		abort();
	}

	string word;
	while (!file.eof()) {
		file >> word;
		//if (!file.eof()) {
		dict->addNode(word);
		//dict->insert(word);
		//}
	}
	return;
}

/**
 * Figure out the game's score, this is unused?
 */
void Game::getScore() {
	wordlist.getScore();
}

//=



