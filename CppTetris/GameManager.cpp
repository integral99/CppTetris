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
void GameManager::MainLogicLoop() {
	while (true) {
		std::cout << "This is Looping" << std::endl;
		std::cout << "The next Tetrimino is " << nextQueue.front()->GetTypeInString() << "mino!" << std::endl;
		nextQueue.pop();
		nextQueue.push(Tetrimino::GetNewRandomTetrimino());
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

