/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:24:20 by psirault          #+#    #+#             */
/*   Updated: 2025/08/20 16:43:41 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_cub 	*data = malloc(sizeof(t_cub));
	t_map	*cub_map = malloc(sizeof(t_map));
	t_player *player = malloc(sizeof(t_player));

	int		fd;
	char	*line;
	size_t i;
	size_t j;

	i = 0;
	if (argc != 2)
		return (printf("Use the program as follows: ./cub3d file.cub"));
	if (!is_correct_extension(argv[1], "cub"))
	{
		printf("Invalid file extension. Use .cub files only.\n");
		free(data);
		free(cub_map);
		return (1);
	}
	data->w_height = HEIGHT;
	data->w_width = WIDTH;
	cub_map->infos = malloc(sizeof(char *) * 100);
	data->player = player;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	cub_map->infos[i] = line;
	i++;
	// SKIP EVERY LINE UNTIL THE FIRST LINE OF THE MAP DESCRIPTION
	while(!is_first_or_last_line_valid(line))
	{
		cub_map->infos[i] = line;
		line = get_next_line(fd);
		i++;
	}
	cub_map->map = line;
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (!is_first_or_last_line_valid(line))
	{
		cub_map->map = ft_strjoin(cub_map->map, line);
		line = get_next_line(fd);
		if (ft_strlen(line) > j)
			j = ft_strlen(line);
		i++;
	}
	cub_map->height = i;
	cub_map->width = j;
	cub_map->map = ft_strjoin(cub_map->map, line);
	if (!pos_nb_checker(cub_map->map, data))
	{
		printf("More than one player position found in the map.\n");
		free(data);
		free(cub_map);
		return (1);
	}
	data->map = cub_map;
	close(fd);
	char **tmap = ft_split(data->map->map, "\n");
	data->map->map_tab = tmap;
	set_player_pos(data);

	// Initialize player direction and camera plane
	if (data->player->player_dir == 'N')
	{
	    data->player->dirX = 0;
	    data->player->dirY = -1;
	    data->player->planeX = 0.66;
	    data->player->planeY = 0;
	}
	else if (data->player->player_dir == 'S')
	{
	    data->player->dirX = 0;
	    data->player->dirY = 1;
	   data->player->planeX = -0.66;
 	   data->player->planeY = 0;
	}
	else if (data->player->player_dir == 'E')
	{
    	data->player->dirX = 1;
 		data->player->dirY = 0;
    	data->player->planeX = 0;
    	data->player->planeY = 0.66;
	}
	else if (data->player->player_dir == 'W')
	{
    	data->player->dirX = -1;
    	data->player->dirY = 0;
    	data->player->planeX = 0;
    	data->player->planeY = -0.66;
	}
	for (int k = 0; tmap[k]; k++)
	{
		printf("TAB %d :%s\n", k, tmap[k]);
	}
	printf("X:%d\nY:%d\n", data->player->pos_X, data->player->pos_Y);
	if (!map_checker(data, tmap))
		return printf("INVALID MAP\n");
	initialize_mlx(data);
	north_texture(data);
	south_texture(data);
	east_texture(data);
	west_texture(data);
	floor_color(data);
	ceiling_color(data);
	raycasting(data);
	mlx_loop(data->mlx);


	return 0;
}
