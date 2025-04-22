
#include "cub3d.h"
#include <math.h>

void	init_ray_dir_map_dis(t_config *config, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = config->dir_x + config->plane_x * ray->camera_x;
	ray->ray_dir_y = config->dir_y + config->plane_y * ray->camera_x;
	ray->map_x = (int)config->player_x;
	ray->map_y = (int)config->player_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	init_ray_step_sidedist(t_config *config, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (config->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - config->player_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (config->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - config->player_y)
			* ray->delta_dist_y;
	}
}

void	init_ray(t_config *config, t_ray *ray, int x)
{
	init_ray_dir_map_dis(config, ray, x);
	init_ray_step_sidedist(config, ray);
}
