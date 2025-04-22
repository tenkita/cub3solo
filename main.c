
#include "cub3d.h"
#include <mlx.h>

int	main(int ac, char *av[])
{
	t_config	config;
	
	// configの初期化
	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: ./cub3D map.cub\n", 24);
		return (1);
	}
	config = parse_map(av[1]);
	init_mlx(&config);
	load_textures(&config);
    mlx_loop_hook(config.mlx, render_frame, &config);
    mlx_hook(config.win, 2, 1L << 0, handle_key, &config);
	mlx_loop(config.mlx);
	return (0);
}
