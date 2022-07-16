#include "Fruit.h"

	void Fruit::FruitNewCoords(int X, int Y)
	{
		x = rand() % (X - 5);
		y = rand() % (Y - 5);
	}

	void Fruit::DrawFruit(int SCALE)
	{
		glColor3f(1.0, 0.0, 0.0);
		glRectf(x * SCALE, y * SCALE, (x + 1) * SCALE, (y + 1) * SCALE);
	}

	int Fruit::GetX()
	{
		return x;
	}
	int Fruit::GetY()
	{
		return y;
	}

	void Fruit::SetX(int x)
	{
		this->x = x;
	}
	void Fruit::SetY(int y)
	{
		this->y = y;
	}