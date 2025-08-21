/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:24:20 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 12:26:01 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_cub 	*data = malloc(sizeof(t_cub));
	int		fd;
	char	*line;
	size_t i;
	size_t j;

	arg_check(data, argc, argv);
	i = 0;
	data_init(data);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	data->map->infos[i] = line;
	i++;
	// SKIP EVERY LINE UNTIL THE FIRST LINE OF THE MAP DESCRIPTION
	while(!is_first_or_last_line_valid(line))
	{
		data->map->infos[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map->map = line;
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (!is_first_or_last_line_valid(line))
	{
		data->map->map = ft_strjoin(data->map->map, line);
		line = get_next_line(fd);
		if (ft_strlen(line) > j)
			j = ft_strlen(line);
		i++;
	}
	data->map->height = i;
	data->map->width = j;
	data->map->map = ft_strjoin(data->map->map, line);
	if (!pos_nb_checker(data->map->map, data))
	{
		printf("More than one player position found in the map.\n");
		free(data);
		return (1);
	}
	close(fd);
	data->map->map_tab = ft_split(data->map->map, "\n");
	set_player_pos(data);
	player_init(data);
	initialize_mlx(data);
	textures_and_colors_init(data);
	raycasting(data);
	events_handling(data);
	mlx_loop_hook(data->win, raycasting, data);
	mlx_loop(data->mlx);
	return 0;
}
