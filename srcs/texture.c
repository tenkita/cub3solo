
#include "cub3d.h"
#include <mlx.h>

void	load_texture(t_config *config, t_tex *tex, char *path)
{
    (void)path;
	//tex->img = mlx_xpm_file_to_image(config->mlx, path, &tex->width,
			//&tex->height);
            tex->img = mlx_xpm_file_to_image(config->mlx, "textures/simonkraft/wet_sponge.xpm", &tex->width,
                &tex->height);
	if (!tex->img)
	{
		printf("%s", config->texture_no);
		ft_putendl_fd("error: failed to load tex", 2);
		exit(EXIT_FAILURE);
	}
	tex->data = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
}

void	load_textures(t_config *config)
{
	load_texture(config, &config->texture[0], config->texture_no);
	load_texture(config, &config->texture[1], config->texture_so);
	load_texture(config, &config->texture[2], config->texture_we);
	load_texture(config, &config->texture[3], config->texture_ea);
}
