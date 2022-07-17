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
	Snake(int SnakeMaxLength, int SnakeLength);
	~Snake();

	void SnakeMove(int direction, int CELLSX, int CELLSY);
	void TransferIfNeeded(int CELLSX, int CELLSY);
	void DrawSnake(int SCALE);

	class Cell
	{
	public:

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

		int GetX(){return this->x;}
		int GetY(){return this->y;}

		void SetX(int x) { this->x = x; }
		void SetY(int y) { this->y = y; }

		void IncreaseX() { this->x++; }
		void IncreaseY() { this->y++; }
		void DecreaseX() { this->x--; }
		void DecreaseY() { this->y--; }

	private:
		int x, y;
	};

	Cell* cell;
	int SnakeLength;
};