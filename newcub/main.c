
#include "cub3d.h"
#include <string.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_config(t_config *config)
{
	free(config->texture_no);
	free(config->texture_so);
	free(config->texture_we);
	free(config->texture_ea);
    free_map(config->map);
}

int	main(int ac, char *av[])
{
	t_config	config;

	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage:./cub3D map.cub\n", 23);
		return (1);
	}
	config = parse_map(av[1]);
	clean_config(&config);
}
