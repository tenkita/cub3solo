
#include "cub3d.h"
#include <math.h>
#include <mlx.h>

void	put_mlx_pixel(t_config *config, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y > +HEIGHT)
		return ;
	dst = config->img_data + (y * config->line_len + x * (config->bpp / 8));
	*(unsigned int *)dst = color;
}

void	perform_dda(t_config *config, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= config->map_height || ray->map_x < 0
			|| ray->map_x >= (int)ft_strlen(config->map[ray->map_y]))
			break ;
		if (config->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	compute_wall_params(t_ray *ray)
{
	if (!ray->side)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	render(t_config *config)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(config, &ray, x);
		perform_dda(config, &ray);
		compute_wall_params(&ray);
		draw_column(config, &ray, x);
		x++;
	}
	mlx_put_image_to_window(config->mlx, config->win, config->img, 0, 0);
}

int	render_frame(void *param)
{
	render((t_config *)param);
	return (0);
}

// void	draw_column(t_config *config, t_ray *ray, int x)
// {
// 	t_tex	*tex;
// 	int		color;
// 	double	step;
// 	double	tex_pos;
// 	int		dir;
// 	double	wall_x;
// 	int		tex_x;
// 	int		tex_y;
// 	int		y;

// 	y = 0;
// 	while (y < ray->draw_start)
// 	{
// 		put_mlx_pixel(config, x, y, config->ceiling_color);
// 		y++;
// 	}
// 	dir = 0;
// 	if (ray->side == 0)
// 		if (ray->ray_dir_x < 0)
// 			dir = 0;
// 		else
// 			dir = 1;
// 	else if (ray->ray_dir_y < 0)
// 		dir = 2;
// 	else
// 		dir = 3;
// 	tex = &config->texture[dir];
// 	if (ray->side == 0)
// 		wall_x = config->player_y + ray->perp_wall_dist * ray->ray_dir_y;
// 	else
// 		wall_x = config->player_x + ray->perp_wall_dist * ray->ray_dir_x;
// 	wall_x -= floor(wall_x);
// 	tex_x = (int)(wall_x * tex->width);
// 	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
// 			&& ray->ray_dir_y < 0))
// 		tex_x = tex->width - tex_x - 1;
// 	step = 1.0 * tex->height / ray->line_height;
// 	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
// 	y = ray->draw_start;
// 	while (y <= ray->draw_end)
// 	{
// 		tex_y = (int)tex_pos & (tex->height - 1);
// 		tex_pos += step;
// 		color = tex->data[tex->width * tex_y + tex_x];
// 		put_mlx_pixel(config, x, y, color);
// 		y++;
// 	}
// 	y = ray->draw_end + 1;
// 	while (y < HEIGHT)
// 	{
// 		put_mlx_pixel(config, x, y, config->floor_color);
// 		y++;
// 	}
// }

// void	render(t_config *config)
// {
// 	int		x;
// 	t_ray	ray;
// 	int		hit;
// 	int		color;
// 	int		y;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		ray.camera_x = 2 * x / (double)WIDTH - 1;
// 		ray.ray_dir_x = config->dir_x + config->plane_x * ray.camera_x;
// 		ray.ray_dir_y = config->dir_y + config->plane_y * ray.camera_x;
// 		ray.map_x = (int)config->player_x;
// 		ray.map_y = (int)config->player_y;
// 		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
// 		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
// 		if (ray.ray_dir_x < 0)
// 		{
// 			ray.step_x = -1;
// 			ray.side_dist_x = (config->player_x - ray.map_x) * ray.delta_dist_x;
// 		}
// 		else
// 		{
// 			ray.step_x = 1;
// 			ray.side_dist_x = (ray.map_x + 1 - config->player_x)
// 				* ray.delta_dist_x;
// 		}
// 		if (ray.ray_dir_y < 0)
// 		{
// 			ray.step_y = -1;
// 			ray.side_dist_y = (config->player_y - ray.map_y) * ray.delta_dist_y;
// 		}
// 		else
// 		{
// 			ray.step_y = 1;
// 			ray.side_dist_y = (ray.map_y + 1 - config->player_y)
// 				* ray.delta_dist_y;
// 		}
// 		hit = 0;
// 		while (!hit)
// 		{
// 			if (ray.side_dist_x < ray.side_dist_y)
// 			{
// 				ray.side_dist_x += ray.delta_dist_x; //理屈はわかるけどなんで
// 				ray.map_x += ray.step_x;
// 				ray.side = 0;
// 			}
// 			else
// 			{
// 				ray.side_dist_y += ray.delta_dist_y;
// 				ray.map_y += ray.step_y;
// 				ray.side = 1;
// 			}
// 			if (ray.map_y < 0 || ray.map_y >= config->map_height
// 				|| ray.map_x < 0
// 				|| ray.map_x >= (int)ft_strlen(config->map[ray.map_y]))
// 				break ;
// 			if (config->map[ray.map_y][ray.map_x] == '1')
// 				hit = 1;
// 		}
// 		if (!ray.side)
// 			ray.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
// 		else
// 			ray.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;
// 		ray.line_height = (int)(HEIGHT / ray.perp_wall_dist);
// 		ray.draw_start = -ray.line_height / 2 + HEIGHT / 2; //どこから書いている？
// 		ray.draw_end = ray.line_height / 2 + HEIGHT / 2;
// 		if (ray.draw_start < 0)
// 			ray.draw_start = 0;
// 		if (ray.draw_end >= HEIGHT)
// 			ray.draw_end = HEIGHT - 1;
// 		if (ray.side)
// 			color = 0xAAAAAA;
// 		else
// 			color = 0xFFFFFF;
// 		y = ray.draw_start;
// 		while (y <= ray.draw_end)
// 		{
// 			put_mlx_pixel(config, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(config->mlx, config->win, config->img, 0, 0);
// }