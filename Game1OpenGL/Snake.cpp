#include "Snake.h"

Snake::Snake(int amount, int SnakeLength)
{
	this->cell = new Cell[amount];
	this->SnakeLength = SnakeLength;
}

Snake::~Snake()
{
	delete this->cell;
}

void Snake::SnakeMove(int direction, int CELLSX, int CELLSY)
{
	switch (direction)
	{
	case LEFT:
		this->cell[0].x = this->cell[0].x - 1;
		break;
	
	case UP:
		this->cell[0].y = this->cell[0].y + 1;
		break;

	case RIGHT:
		this->cell[0].x = this->cell[0].x + 1;
		break;

	case DOWN:
		this->cell[0].y = this->cell[0].y - 1;
		break;

	default:
		break;
	}
}

void Snake::DrawSnake(int SCALE)
{
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < this->SnakeLength; i++)
	{
		glRectf(this->cell[i].x * SCALE, this->cell[i].y * SCALE, (this->cell[i].x + 1) * SCALE, (this->cell[i].y + 1) * SCALE);
	}
}
