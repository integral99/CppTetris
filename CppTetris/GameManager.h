#pragma once
#include "Tetrimino.h"
#include <queue>
class GameManager {
private:
	
	bool gameBoard[16][10];
	int score;
	void DisplayBoard();
	

public:
	GameManager();
	~GameManager();
	void StartGame();
	void PauseGame();
	void EndGame();
	
};

