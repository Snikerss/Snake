#include "Snake.h"

Snake::Snake(int SnakeMaxLength, int SnakeLength)
{
	this->cell = new Cell[SnakeMaxLength];
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
		this->cell[0].DecreaseX();
		break;
	
	case UP:
		this->cell[0].IncreaseY();
		break;

	case RIGHT:
		this->cell[0].IncreaseX();
		break;

	case DOWN:
		this->cell[0].DecreaseY();
		break;

	default:
		break;
	}
}

void Snake::TransferIfNeeded(int CELLSX, int CELLSY)
{
	if (this->cell[0].GetY() == CELLSY - 4) this->cell[0].SetY(0);
	if (this->cell[0].GetY() == -1) this->cell[0].SetY(CELLSY - 5);

	if (this->cell[0].GetX() == CELLSX - 4) this->cell[0].SetX(0);
	if (this->cell[0].GetX() == -1) this->cell[0].SetX(CELLSX - 5);
}

void Snake::DrawSnake(int SCALE)
{
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < this->SnakeLength; i++)
	{
		glRectf(this->cell[i].GetX() * SCALE, this->cell[i].GetY() * SCALE, (this->cell[i].GetX() + 1) * SCALE, (this->cell[i].GetY() + 1) * SCALE);
	}
}
