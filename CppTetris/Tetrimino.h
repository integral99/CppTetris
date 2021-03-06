#pragma once

#include <random>
#include <ctime>
#include <string>
enum TetriminoType {
	I,
	J,
	L,
	S,
	Z,
	O,
	T
};

enum RotationStatus {
	NETURAL,
	CW,
	CCW,
	OPPOSITE
};
class Tetrimino
{
private:

	RotationStatus rotation;

	TetriminoType type;
public:

	int xCoordinate;
	int yCoordinate;
	Tetrimino();
	~Tetrimino();

	static Tetrimino* GetNewRandomTetrimino() {
		Tetrimino* toReturnTetrimino = new Tetrimino();

		toReturnTetrimino->type = TetriminoType(rand() % 7);
		toReturnTetrimino->xCoordinate = 0;
		toReturnTetrimino->yCoordinate = 0;

		return toReturnTetrimino;
	}

	std::string GetTypeInString();
	void RotateCW();
	void RotateCCW();
	RotationStatus GetRotation();
	TetriminoType GetType();
};

