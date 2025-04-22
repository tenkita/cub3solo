
#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define NEXT_REACH_X 0
# define NEXT_REACH_Y 1
# define MOVE_SPEED 0.05
# define LINE_IS_EMPTY 1
# define LINE_HAS_CHAR 0
# define MAP_IS_VALID 1
# define MAP_IS_INVALID 0
# define THIS_IS_MAP 1
# define THIS_IS_NOT_MAP 0
# define MAP_IS_CLOSED 1
# define MAP_IS_UNCLOSED 0
# define SURROUNDED_WALL 1
# define UNSURROUNDED_WALL 0
# define INVALID_NUM_PLAYER 0
# define CHAR_IS_VALID 1
# define CHAR_IS_INVALID 0

typedef struct s_tex
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_tex;

typedef struct s_config
{
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_height;

	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;

	t_tex texture[4]; // 0=NO 1=SA 2=WE
}			t_config;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double side_dist_x; //今の位置から次のxマスの壁に当たるまでの距離
	double	side_dist_y;
	double delta_dist_x; // x方向にマス1つ進んだ時、rayが進む直線距離
	double	delta_dist_y;

	int		step_x;
	int		step_y;

	int side; // 0=x面,y=1面
	double	perp_wall_dist;

	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

// free.c
void		free_2d(char **str);
// texture

void		load_textures(t_config *config);
// move
int			handle_key(int key, t_config *config);
// parse
t_config	parse_map(char *file);
int			line_is_empty(char *line);
// render
int			render_frame(void *param);
void		draw_column(t_config *config, t_ray *ray, int x);
void		put_mlx_pixel(t_config *config, int x, int y, int color);
// map.c
int			is_map_line(char *line);
void		normalize_map(t_config *config);
void		parse_map_line(t_config *config, int fd, char *first_line);
// valid.c
int			valid_map(char **map);
// utils.c
char		**realloc_2d(char **old, int size, int new_capa);
int			put_error(const char *msg);
// init
void		init_player(t_config *config);
void		init_mlx(t_config *config);
void		init_ray(t_config *config, t_ray *ray, int x);

#endif