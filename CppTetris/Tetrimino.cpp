#include "Tetrimino.h"
#include <random>


Tetrimino::Tetrimino()
{
	rand();
}


Tetrimino::~Tetrimino()
{
}

std::string Tetrimino::GetTypeInString() {
	std::string strToReturn;

	switch (type) {
	case I:
		strToReturn = "I";
		break;
	case J:
		strToReturn = "J";
		break;
	case L:
		strToReturn = "L";
		break;
	case S:
		strToReturn = "S";
		break;
	case Z:
		strToReturn = "Z";
		break;
	case O:
		strToReturn = "O";
		break;
	case T:
		strToReturn = "T";
		break;

	}
	return strToReturn;
}

void Tetrimino::RotateCW() {
	if (rotation == RotationStatus(NETURAL)) {
		rotation = RotationStatus(CW);
	}
	else if (rotation == RotationStatus(CW)) {
		rotation = RotationStatus(OPPOSITE);
	}
	else if (rotation == RotationStatus(OPPOSITE)) {
		rotation = RotationStatus(CCW);
	}
	else if (rotation == RotationStatus(CCW)) {
		rotation = RotationStatus(NETURAL);
	}
}

void Tetrimino::RotateCCW() {
	if (rotation == RotationStatus(NETURAL)) {
		rotation = RotationStatus(CCW);
	}
	else if (rotation == RotationStatus(CCW)) {
		rotation = RotationStatus(OPPOSITE);
	}
	else if (rotation == RotationStatus(OPPOSITE)) {
		rotation = RotationStatus(CW);
	}
	else if (rotation == RotationStatus(CW)) {
		rotation = RotationStatus(NETURAL);
	}
}

TetriminoType Tetrimino::GetType() {
	return type;
}