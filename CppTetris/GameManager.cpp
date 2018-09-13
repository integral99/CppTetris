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
	cout << "Next is : " << nextQueue.front()->GetTypeInString() << "\n";
	cout << "----------------------\n";
	for (int i = 0; i < 16; i++) {
		cout << "|";
		for (int j = 0; j < 10; j++) {
			if (gameBoard[i][j] ) {
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
	clock_t frameTimeChecker;
	clock_t minoDescendChecker = clock();


	currentMino = nextQueue.front();
	nextQueue.pop();
	nextQueue.push(Tetrimino::GetNewRandomTetrimino());
	currentMino->xCoordinate = 4;
	currentMino->yCoordinate = 0;
	while (true) {
		frameTimeChecker = clock();
		

		DisplayBoard();

		std::cout << GetUserInput() << "\n";

		if ((double)(clock() - minoDescendChecker) / CLOCKS_PER_SEC > minoDescendingInterval) {
			minoDescendChecker = clock();
			currentMino->yCoordinate--;
			std::cout << "descend!\n";
		}
		while ((double)(clock() - frameTimeChecker) / CLOCKS_PER_SEC < 0.016) {

		}
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

void GameManager::HandleUserInput(UserInput input) {
	if (input == UserInput(LEFT)) {
		
	}
}

//bool GameManager::EvaluateCurrentMino(int x, int y) {
//	switch (currentMino->GetType) {
//	case TetriminoType(I):
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(J):
//
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(L):
//
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(S):
//		
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(Z):
//
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(O):
//
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	case TetriminoType(T):
//
//		switch (currentMino->GetRotation) {
//		case RotationStatus(NETURAL):
//		case RotationStatus(CW):
//		case RotationStatus(CCW):
//		case RotationStatus(OPPOSITE):
//		}
//	}
//}