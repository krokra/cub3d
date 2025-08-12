/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:24:20 by psirault          #+#    #+#             */
/*   Updated: 2025/08/12 12:23:45 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_cub 	*data = malloc(sizeof(t_cub));
	t_map	*cub_map = malloc(sizeof(t_map));
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
	cub_map->infos = malloc(sizeof(char *) * 100);
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
	i = 1;
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
	char **tab_test = ft_split(data->map->map, "\n");
	for (int j = 0; tab_test[j]; j++)
	{
		printf("TAB %d :%s\n", j, tab_test[j]);
	}
	
	if (!map_checker(data, tab_test))
		printf("INVALID MAP\n");
	north_texture(data);
	south_texture(data);
	east_texture(data);
	west_texture(data);
	floor_color(data);
	ceiling_color(data);
	return 0;
}
