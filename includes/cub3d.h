#ifndef CUB3D_H
#define CUB3D_H
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_player {
	double dirX;
	double dirY;
	double planeY;
	double planeX;
	int		pos_X;
	int		pos_Y;
	char	player_dir;

}				t_player;

typedef struct s_ray {
	double dirX;
	double dirY;
	double cameraX;
	double planeX;
	double planeY;
	int mapX;
	int mapY;
	double deltaDistX;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	int		stepX;
	int		stepY;
	int		side;
	int		wall_distance;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef struct	s_img {
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_map {
	char	*map;
	char	**map_tab;
	char	**infos;
	int		height;
	int		width;
}				t_map;

typedef struct	s_rgb {
	unsigned int R;
	unsigned int G;
	unsigned int B;
}				t_rgb;


typedef struct s_cub {
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	*map;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	t_rgb	*floor_rgb;
	t_rgb	*ceiling_rgb;
	t_player	*player;
	t_ray		*ray;
}				t_cub;

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
bool		is_correct_extension(char *filename, char *ext);
bool		is_map_line_valid(char *line);
bool		is_line_empty(char *line);
bool		is_valid_identifier(char *line);
bool		is_first_or_last_line_valid(char *line);
bool		pos_nb_checker(char *map, t_cub *data);
int			end_of_spaces_index(char *line);
char		*skip_to_next_line(char *str);
bool		check_walls(t_cub *cub, char **map, int i, int j);
bool		map_checker(t_cub *data, char **map);
void		set_player_pos(t_cub *data);

// TEXTURES
void		north_texture(t_cub *data);
void		south_texture(t_cub *data);
void		west_texture(t_cub *data);
void		east_texture(t_cub *data);

// CEILING/FLOOR COLORS
void	ceiling_color(t_cub *data);
void	floor_color(t_cub *data);

// MLX-RELATED FUNCTIONS
void	initialize_mlx(t_cub *cub);
void	events_handling(t_cub *cub);

#endif