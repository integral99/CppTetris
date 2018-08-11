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
	ios_base::sync_with_stdio(false);
	system("cls");
	cout << "Next is : " << nextQueue.front()->GetTypeInString() << "\n";
	cout << "----------------------\n";
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
		cout << "|\n";
	}
	cout << "----------------------\n";

	cout.flush();
	return;
}

void GameManager::MainLogicLoop() {
	while (true) {
		currentMino = nextQueue.front();
		nextQueue.pop();
		nextQueue.push(Tetrimino::GetNewRandomTetrimino());
		
		DisplayBoard();

		std::cout << GetUserInput();
	}
}

void GameManager::StartGame() {
	std::srand(std::time(nullptr));

	for (int iter0 = 0; iter0 < 5; iter0++) {
		this->nextQueue.push(Tetrimino::GetNewRandomTetrimino());
	}

	MainLogicLoop();
}

UserInput GameManager::GetUserInput() {
	UserInput toReturnInput = UserInput(EMPTY);

	if(GetAsyncKeyState(VK_UP)) {
		toReturnInput = UserInput(UP);
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		toReturnInput = UserInput(DOWN);
	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		toReturnInput = UserInput(LEFT);
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		toReturnInput = UserInput(RIGHT);
	}
	else if (GetAsyncKeyState('Z')) {
		toReturnInput = UserInput(COUNTERCLOCEWISEROT);
	}
	else if (GetAsyncKeyState('X')) {
		toReturnInput = UserInput(CLOCKWISEROT);
	}

	return toReturnInput;
}