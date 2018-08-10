#pragma once

#include "Tetrimino.h"
#include <queue>
class GameManager {
private:
	
	bool gameBoard[16][10];
	std::queue<Tetrimino*> nextQueue;
	int score;
	void DisplayBoard();
	void MainLogicLoop();

public:
	GameManager();
	~GameManager();
	void StartGame();
	void PauseGame();
	void EndGame();
	
};

