/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:27:57 by psirault          #+#    #+#             */
/*   Updated: 2025/08/07 13:13:35 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	north_texture(t_cub *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = ft_strdup("");
	while ((line[0] != 'N' || line[1] != 'O') && line)
		line = get_next_line(fd);
	data->no_texture = ft_substr(line, 3, ft_strlen(line) - 4);
	// printf("\nNO TEXTURE PATH : %s", data->no_texture);
	close(fd);
}

void	south_texture(t_cub *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = ft_strdup("");
	while ((line[0] != 'S' || line[1] != 'O') && line)
		line = get_next_line(fd);
	data->no_texture = ft_substr(line, 3, ft_strlen(line) - 4);
	// printf("\nSO TEXTURE PATH : %s", data->no_texture);
	close(fd);
}

void	east_texture(t_cub *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = ft_strdup("");
	while ((line[0] != 'E' || line[1] != 'A') && line)
		line = get_next_line(fd);
	data->no_texture = ft_substr(line, 3, ft_strlen(line) - 4);
	// printf("\nEA TEXTURE PATH : %s", data->no_texture);
	close(fd);
}

void	west_texture(t_cub *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = ft_strdup("");
	while ((line[0] != 'W' || line[1] != 'E') && line)
		line = get_next_line(fd);
	data->no_texture = ft_substr(line, 3, ft_strlen(line) - 4);
	// printf("\nWE TEXTURE PATH : %s", data->no_texture);
	close(fd);
}