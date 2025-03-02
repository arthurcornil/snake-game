#ifndef SNAKE_H
# define SNAKE_H

# include "raylib.h"
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_point
{
	unsigned int x;
	unsigned int y;
}	t_point;

typedef struct s_snake
{
	t_direction		direction;
	t_point			positions[1600];
	unsigned int	length;
}	t_snake;

#endif
