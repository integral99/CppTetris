#include "GameManager.h"
#include <thread>
#include <queue>
#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>

GameManager::GameManager() {
	
}
GameManager::~GameManager() {

}

void GameManager::DisplayBoard() {
	using namespace std;
	system("cls");
	cout << "Next is : " << nextQueue.front()->GetTypeInString() << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < 16; i++) {
		cout << "|";
		for (int j = 0; j < 10; j++) {
			if (gameBoard[i][j]) {
				cout << "[]";
			}
			else {
				cout << "  ";
			}
		}
		cout << "|" << endl;
	}
	cout << "----------------------" << endl;

	return;
}
void GameManager::MainLogicLoop() {
	while (true) {
		
		nextQueue.pop();
		nextQueue.push(Tetrimino::GetNewRandomTetrimino());
		
		DisplayBoard();

		Sleep(1000);
	}
}

void GameManager::StartGame() {
	std::srand(std::time(nullptr));

	for (int iter0 = 0; iter0 < 5; iter0++) {
		this->nextQueue.push(Tetrimino::GetNewRandomTetrimino());
	}

	MainLogicLoop();
}

