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