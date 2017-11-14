/*
 * Game.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Debra
 */

#include <iostream>
#include "AvlTree.hpp"
#include "Game.hpp"
#include "LL.hpp"
#include "NodeL.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Game::Game() {
	Game("dictionary.txt", false);
}

Game::Game(string filePath, bool avlFlag) {
	gameAvlFlag = avlFlag;
	dictionaryFilePath = filePath;

	readTreeFromFile();

	cout << "Printing in order: " << endl;
	dictionary->printIO(dictionary->root);
	cout << endl << "Printing Preorder: " << endl;
	dictionary->printPre(dictionary->root);
	cout << endl << "Printing Postorder: " << endl;
	dictionary->printPost(dictionary->root);
	numLetters = 0;
	gameScore = 0;
	//numRight = 0;
	//totalWords = 0;
	wordList = new LinkedList();

}

void Game::startGame() {
	cout << "How many letters do you want?" << endl;
	cin >> numLetters;
	currentLetters = getLetters(numLetters);
	cout << "Your letters are: " << endl;
	for (int i = 0; i < numLetters; i++) {
		cout << currentLetters[i] << " ";
	}
	cout << endl;
	cout << "Start generating words: " << endl;
	getWords();
	wordList.printList();
	checkWordsForScore();
	wordList.printList();
	wordList.getScore();
	cout << "Final Score is: " << wordList.score << endl;

	//int gameScore = numRight * 3 - (totalWords-numRight) * 6;
	//cout << "Number of valid words: " << numRight << " Invalid words: " << (totalWords = numRight) << endl;
	//cout << "Final Score is: "  << gameScore << endl;
}


void Game::getWords() {
	string s;
	cin >> s;
	while (s != "-1") {
		wordList.push(s);
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
	char tempchar[numLetters];
	for (int i = 0; i < numLetters; i++) {
		tempchar[i] = currentLetters[i];
	}
	for (int i = 0; i < s.size(); i++) {
		int j = 0;
		while ((j < numLetters) && (tolower(s[i]) != tempchar[j])) {
			j++;
		}
		if (j == numLetters) {
			return false;
		}
		tempchar[j] = '1';
	}
	return true;
}

void Game::checkWordsForScore() {
	NodeLinkedList *tmp = wordList.first;
	while (tmp != NULL) {
		if (checkWLetters(tmp->word)) {
			cout << tmp->word << " is okay  letterwise" << endl;

			if (dictionary->findWord(tmp->word, dictionary->root)) {
				cout << tmp->word << " is in tree " << endl;
				tmp->wscore = 1;
			} else {
				cout << tmp->word << " NOT in tree " << endl;
				tmp->wscore = -1;
			}
		} else {
			cout << tmp->word << " is invalid letterwise" << endl;
			tmp->wscore = -1;
		}
		tmp = tmp->next;
	}
}

void Game::readTreeFromFile() {
	dictionary = new AvlTree(gameAvlFlag);
	ifstream file(dictionaryFilePath.c_str());
	cout << (file.is_open() ? "Reading succeeded: " : "Reading failed: ") << dictionaryFilePath << endl;
	string word;
	while (!file.eof()) {
		file >> word;
		//if (!file.eof()) {
		cout << "Adding: " << word << endl;
		dictionary->addNode(word, dictionary->root);
		//dictionary->insert(word);
		//}
	}
}

void Game::getScore() {
//TODO
}



