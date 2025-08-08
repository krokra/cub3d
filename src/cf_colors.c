/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:11:11 by psirault          #+#    #+#             */
/*   Updated: 2025/08/08 13:06:01 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ceiling_color(t_cub *data, char *filename)
{
	int		fd;
	char	*line;
	char	**tab;

	(void)data;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line[end_of_spaces_index(line)] != 'C' && line)
		line = get_next_line(fd);
	printf("\nLINE :%s\n", line);
	tab = ft_split(line, " ,\t");
	for (int j = 0; j < 4; j++)
	{
		printf("TAB %d : %s\n", j, tab[j]);
	}
	
	// while (line[i])
	// {
	// 	while (line[i] != ',' && line[i] != '.')
	// 		i++;
	// 	if (!data->ceiling_rgb->R)
	// 		data->ceiling_rgb->R = ft_atoi(ft_substr(line, 2, i));
	// 	else if (!data->ceiling_rgb->G && )
	// }
	// data->ceiling_rgb->R = ft_atoi(tab[1]);
	// printf("\nCEILING COLOR : %s", data->ceiling_rgb);
	close(fd);
}

// void	floor_color(t_cub *data, char *filename)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(filename, O_RDONLY);
// 	line = ft_strdup("");
// 	while (line[0] != 'F' && line)
// 		line = get_next_line(fd);
// 	data->floor_rgb = ft_substr(line, 2, ft_strlen(line) - 3);
// 	printf("\nFLOOR COLOR : %s", data->floor_rgb);
// 	close(fd);
// }