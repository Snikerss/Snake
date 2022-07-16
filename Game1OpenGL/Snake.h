#pragma once
#include <glut.h>

class Snake
{
public:

	enum Direction
	{
		LEFT,
		UP,
		RIGHT,
		DOWN
	};

	Snake();
	Snake(int amount, int SnakeLength);
	~Snake();

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);

	void SnakeMove(int direction, int CELLSX, int CELLSY);
	void TransferIfNeeded(int CELLSX, int CELLSY);
	void DrawSnake(int SCALE);

	class Cell
	{
	public:
		int x, y;

		Cell()
		{
			this->x = -1;
			this->y = -1;
		}
		Cell(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	Cell* cell;
	int SnakeLength;
};