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
	const double minoDescendingInterval = 0.7;
	bool gameBoard[16][10] = { 1, 1, 1, 1,};
	Tetrimino* currentMino;
	std::queue<Tetrimino*> nextQueue;
	int score;
	void DisplayBoard();
	//bool EvaluateCurrentMino(int, int);
	void MainLogicLoop();
	UserInput GetUserInput();
	void HandleUserInput(UserInput);

public:
	GameManager();
	~GameManager();
	void StartGame();
	void PauseGame();
	void EndGame();
	
};

