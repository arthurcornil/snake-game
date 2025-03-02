#include "../includes/snake.h"

t_snake	init_snake()
{
	t_snake snake;

	snake.direction = RIGHT;
	snake.positions[0] = (t_point){20, 20};
	snake.positions[1] = (t_point){19, 20};
	snake.positions[2] = (t_point){18, 20};
	snake.length = 3;
	return (snake);
}

void	grow(t_snake *snake)
{
	snake->length ++;
	snake->positions[snake->length - 1] = snake->positions[snake->length - 2];
}

#include <stdio.h>

void	update_snake(t_snake *snake)
{
	Color green = {50, 168, 82, 255};

	for(int i = snake->length - 1; i > 0; i--)
	{
		snake->positions[i] = snake->positions[i - 1];
		DrawRectangle(snake->positions[i].x * 20, snake->positions[i].y * 20, 20, 20, green);
	}

	switch(snake->direction)
	{
		case UP:
			snake->positions[0].y --;
			break ;
		case DOWN:
			snake->positions[0].y ++;
			break ;
		case RIGHT:
			snake->positions[0].x ++;
			break ;
		case LEFT:
			snake->positions[0].x --;
	}
	DrawRectangle(snake->positions[0].x * 20, snake->positions[0].y * 20, 20, 20, green);
	if (snake->positions[0].x == 0)
		snake->positions[0].x = 40;
	else if (snake->positions[0].x == 40)
		snake->positions[0].x = 0;
	else if (snake->positions[0].y == 40)
		snake->positions[0].y = 0;
	else if (snake->positions[0].y == 0)
		snake->positions[0].y = 40;
}

t_point	get_random_point()
{
	t_point rand_point;

	rand_point.x = rand() % 40;
	rand_point.y = rand() % 40;
	return (rand_point);
}

double get_distance(unsigned int x, unsigned int y) {
    double z = sqrt((double)(x * x + y * y));
    return z;
}

bool is_snake_eating(t_snake *snake, t_point food_position) 
{
    t_point head = snake->positions[0];
	double distance = get_distance(abs((int)(head.x - food_position.x) * 20), abs((int)(head.y - food_position.y) * 20));

	return (distance < 40);
}

int main(void)
{
	t_snake snake = init_snake();
	t_point food_position = get_random_point();
	Color red = {212, 38, 30, 255};

	InitWindow(800, 800, "Snake game");
	SetTargetFPS(20);

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_UP) && snake.direction != DOWN)
				snake.direction = UP;
		else if (IsKeyDown(KEY_RIGHT) && snake.direction != LEFT)
			snake.direction = RIGHT;
		else if (IsKeyDown(KEY_DOWN) && snake.direction != UP)
			snake.direction = DOWN;
		else if (IsKeyDown(KEY_LEFT) && snake.direction != RIGHT)
			snake.direction = LEFT;
		if (is_snake_eating(&snake, food_position))
		{
			grow(&snake);
			food_position = get_random_point();
		}
		BeginDrawing();
		DrawCircle(food_position.x * 20, food_position.y * 20, 20, red);
		update_snake(&snake);
		ClearBackground(WHITE);
		EndDrawing();
	}

	CloseWindow();
    return (0);
}
