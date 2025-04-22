
#include "cub3d.h"
#include <mlx.h>

void	init_mlx(t_config *config)
{
	config->mlx = mlx_init();
	if (!config->mlx)
		exit(EXIT_FAILURE);
	config->win = mlx_new_window(config->mlx, WIDTH, HEIGHT, "cub3d");
	if (!config->win)
		exit(EXIT_FAILURE);
	config->img = mlx_new_image(config->mlx, WIDTH, HEIGHT);
	if (!config->img)
		exit(EXIT_FAILURE);
	config->img_data = mlx_get_data_addr(config->img, &config->bpp,
			&config->line_len, &config->endian);
}
