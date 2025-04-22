#include "cub3d.h"
#include <math.h>

void	draw_ceiling(t_config *config, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		put_mlx_pixel(config, x, y, config->ceiling_color);
		y++;
	}
}

void	draw_floor(t_config *config, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_end + 1;
	while (y < HEIGHT)
	{
		put_mlx_pixel(config, x, y, config->floor_color);
		y++;
	}
}

t_tex	*select_texture(t_config *config, t_ray *ray)
{
	if (ray->side == 0)
		if (ray->ray_dir_x < 0)
			return (&config->texture[3]);
		else
			return (&config->texture[2]);
	else
	{
		if (ray->ray_dir_y < 0)
			return (&config->texture[1]);
		else
			return (&config->texture[0]);
	}
}

int	calculate_wall_texture_x(t_config *config, t_ray *ray, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == NEXT_REACH_X)
		wall_x = config->player_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = config->player_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((ray->side == NEXT_REACH_X && ray->ray_dir_x > 0)
		|| (ray->side == NEXT_REACH_Y && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
//tex_x:壁の中のどこに当たったか（0.0〜1.0）をテクスチャの横幅にスケーリングした値
void	draw_wall_stripe(t_config *config, t_ray *ray, t_tex *tex, int tex_x,
		int x)
{
	double	step;
	double	tex_pos;

	int tex_y, y, color;
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		color = tex->data[tex->width * tex_y + tex_x];
		put_mlx_pixel(config, x, y, color);
		y++;
	}
}

void	draw_wall_texture(t_config *config, t_ray *ray, int x)
{
	t_tex	*tex;
	int		tex_x;

	tex = select_texture(config, ray);
	tex_x = calculate_wall_texture_x(config, ray, tex);
	draw_wall_stripe(config, ray, tex, tex_x, x);
}

void	draw_column(t_config *config, t_ray *ray, int x)
{
	draw_ceiling(config, ray, x);
	draw_wall_texture(config, ray, x);
	draw_floor(config, ray, x);
}