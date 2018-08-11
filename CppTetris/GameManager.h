#pragma once

#include "Tetrimino.h"
#include <queue>

enum UserInput {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CLOCKWISEROT,
	COUNTERCLOCEWISEROT,
	EMPTY
};

class GameManager {
private:
	
	bool gameBoard[16][10] = { 0 };
	Tetrimino* currentMino;
	std::queue<Tetrimino*> nextQueue;
	int score;
	void DisplayBoard();
	void MainLogicLoop();
	UserInput GetUserInput();

public:
	GameManager();
	~GameManager();
	void StartGame();
	void PauseGame();
	void EndGame();
	
};

