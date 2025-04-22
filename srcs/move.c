
#include "cub3d.h"
#include <math.h>

#define KEY_W 119
#define KEY_A 97
#define KEY_D 100
#define KEY_S 115
#define KEY_ESC 65307
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define ROT_SPEED 0.05

void	move_player(t_config *config, int key)
{
	double new_x, new_y;
	printf("move_player: key=%d\n", key);
	if (key == KEY_W)
	{
		printf("W pressed\n");
		new_x = config->player_x + config->dir_x * MOVE_SPEED;
		new_y = config->player_y + config->dir_y * MOVE_SPEED;
	}
	else if (key == KEY_S)
	{
		printf("S pressed\n");
		new_x = config->player_x - config->dir_x * MOVE_SPEED;
		new_y = config->player_y - config->dir_y * MOVE_SPEED;
	}
	else if (key == KEY_A)
	{
		printf("A pressed\n");
		new_x = config->player_x - config->plane_x * MOVE_SPEED;
		new_y = config->player_y - config->plane_y * MOVE_SPEED;
	}
	else if (KEY_D)
	{
		printf("D pressed\n");
		new_x = config->player_x + config->plane_x * MOVE_SPEED;
		new_y = config->player_y + config->plane_y * MOVE_SPEED;
	}
	else
		return ;
	if (config->map[(int)new_y][(int)new_x] != '1')
	{
		config->player_x = new_x;
		config->player_y = new_y;
	}
}

void	rotate_player(t_config *config, int key)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	if (key == KEY_LEFT)
		rot = -ROT_SPEED;
	else
		rot = ROT_SPEED;
	old_dir_x = config->dir_x;
	old_plane_x = config->plane_x;
	config->dir_x = config->dir_x * cos(rot) - config->dir_y * sin(rot);
	config->dir_y = old_dir_x * sin(rot) + config->dir_y * cos(rot);
	config->plane_x = config->dir_x * cos(rot) - config->plane_y * sin(rot);
	config->plane_y = old_dir_x * sin(rot) + config->plane_y * cos(rot);
}

int	handle_key(int key, t_config *config)
{
	printf("key: %d\n", key);
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate_player(config, key);
	else
		move_player(config, key);
	return (0);
}
