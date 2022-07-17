//snake
#define DEBUG 0
#include "Snake.h"
#include "Fruit.h"

using namespace std;

const int DELAY = 250; // Delay between ticks in milliseconds

const int X = 30, Y = 30; // Amount of cells by x and y
const int SCALE = 25; // Cells scale in pixels

const int WIDTH = SCALE * X; // Width in pixels
const int HEIGHT = SCALE * Y; // Height in pixels

const int FruitAmount = 10;

const int SnakeMinLength = 2;
const int SnakeStartLength = 4;
const int SnakeMaxLength = 100;

Snake snake(SnakeMaxLength, SnakeStartLength);
Fruit Fruits[FruitAmount];

int direction;

void Keys(int key, int a, int b)
{
	switch (key)
	{
	case 100: direction = Snake::Direction::LEFT; break;
	case 101: direction = Snake::Direction::UP; break;
	case 102: direction = Snake::Direction::RIGHT; break;
	case 103: direction = Snake::Direction::DOWN; break;
	}
}

void DrawField()
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINES);

	for (int i = 0; i < WIDTH; i += SCALE) { glVertex2f(i, 0); glVertex2f(i, HEIGHT); }
	for (int i = 0; i < HEIGHT; i += SCALE) { glVertex2f(0, i); glVertex2f(WIDTH, i); }

	glEnd();

}

void OnTick()
{
#if DEBUG 1
	cout << "X: " << snake.cell[0].GetX() << " " << "Y: " << snake.cell[0].GetY() << endl; // show snake coords in cmd
#endif 


	for (int i = snake.SnakeLength; i > 0; --i)
	{
		snake.cell[i].SetX(snake.cell[i - 1].GetX());
		snake.cell[i].SetY(snake.cell[i - 1].GetY());
	}

	snake.SnakeMove(direction, X, Y);
	snake.TransferIfNeeded(X, Y);

	for (int i = 0; i < FruitAmount; i++)
	{
		if ((snake.cell[0].GetX() == Fruits[i].GetX()) && (snake.cell[0].GetY() == Fruits[i].GetY()) && (snake.SnakeLength < SnakeMaxLength))
		{
			snake.SnakeLength++;
			Fruits[i].FruitNewCoords(X, Y);
		}
	}

	for (int i = SnakeMinLength; i < snake.SnakeLength; i++) // makes snake cut itself if collides
	{
		if (snake.cell[0].GetX() == snake.cell[i].GetX() && snake.cell[0].GetY() == snake.cell[i].GetY())
		{
			snake.SnakeLength = i;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 10; i++)
		Fruits[i].DrawFruit(SCALE);

	snake.DrawSnake(SCALE);

#if DEBUG 1
	DrawField();
#endif

	glFlush();
}

void timer(int = 0)
{
	display();

	OnTick();

	glutTimerFunc(DELAY, timer, 0);
}

int main(int argc, char** argv) 
{
	for (int i = 0; i < 10; i++)
	{
		Fruits[i].FruitNewCoords(X - 5,Y - 5);
	}

	snake.cell[0].SetX( X / 2 );
	snake.cell[0].SetY( Y / 2 );

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Snake");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);

	glutDisplayFunc(display);
	glutTimerFunc(DELAY, timer, 0);
	glutSpecialFunc(Keys);

	glutMainLoop();


	return 0;
}