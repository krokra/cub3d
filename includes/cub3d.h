#ifndef CUB3D_H
#define CUB3D_H
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"


typedef struct	s_img {
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map {
	char *map;
}				t_map;

typedef struct s_cub {
	void	*mlx;
	void	*win;
	t_img	img;
	char	player_pos;
	t_map	map;
}				t_cub;

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
bool		is_correct_extension(char *filename, char *ext);
bool		is_map_line_valid(char *line);
bool		is_line_empty(char *line);
bool		is_valid_identifier(char *line);

#endif