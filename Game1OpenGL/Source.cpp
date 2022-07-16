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

Snake snake(100, 4);
Fruit Fruits[10];

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
	cout << "X: " << snake.cell[0].x << " " << "Y: " << snake.cell[0].y << endl; // show snake coords in cmd
#endif 


	for (int i = snake.SnakeLength; i > 0; --i)
	{
		snake.cell[i].x = snake.cell[i - 1].x;
		snake.cell[i].y = snake.cell[i - 1].y;
	}

	snake.SnakeMove(direction, X, Y);
	snake.TransferIfNeeded(X, Y);

	for (int i = 0; i < 10; i++)
	{
		if ((snake.cell[0].x == Fruits[i].GetX()) && (snake.cell[0].y == Fruits[i].GetY()))
		{
			snake.SnakeLength++;
			Fruits[i].FruitNewCoords(X, Y);
		}
	}

	for (int i = 2; i < snake.SnakeLength; i++) // Code that makes snake cut itself if collides
	{
		if (snake.cell[0].x == snake.cell[i].x && snake.cell[0].y == snake.cell[i].y)
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

#if DEBUG 1
	DrawField();
#endif
	snake.DrawSnake(SCALE);

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

	snake.cell[0].x = X / 2;
	snake.cell[0].y = Y / 2;

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