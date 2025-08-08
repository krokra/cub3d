/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:24:20 by psirault          #+#    #+#             */
/*   Updated: 2025/08/08 13:06:53 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_cub 	*data = malloc(sizeof(t_cub));
	t_map	*cub_map = malloc(sizeof(t_map));
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (printf("Use the program as follows: ./cub3d file.cub"));
	if (!is_correct_extension(argv[1], "cub"))
	{
		printf("Invalid file extension. Use .cub files only.\n");
		free(data);
		free(cub_map);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	// SKIP EVERY LINE UNTIL THE FIRST LINE OF THE MAP DESCRIPTION
	while(!is_first_or_last_line_valid(line))
		line = get_next_line(fd);
	cub_map->map = line;
	line = get_next_line(fd);
	while (!is_first_or_last_line_valid(line))
	{
		cub_map->map = ft_strjoin(cub_map->map, line);
		line = get_next_line(fd);
	}
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
	printf("%s", cub_map->map);
	north_texture(data, argv[1]);
	south_texture(data, argv[1]);
	east_texture(data, argv[1]);
	west_texture(data, argv[1]);
	// floor_color(data, argv[1]);
	ceiling_color(data, argv[1]);
	return 0;
}
