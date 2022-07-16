#pragma once
#include <iostream>
#include <glut.h>
#include <time.h>

class Fruit
{
public:


	void FruitNewCoords(int X, int Y);

	void DrawFruit(int SCALE);

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);


private:
	int x, y;

};