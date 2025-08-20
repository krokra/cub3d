/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:46:31 by psirault          #+#    #+#             */
/*   Updated: 2025/08/20 11:00:12 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool is_first_or_last_line_valid(char *line)
{
	int i;

	i = 0;
	if (!line)
		return false;
	while (line[i] != '\0')
	{
		if ((line[i] != '1' && line[i] != ' ' && line[i] != '\n') || is_line_empty(line))
			return false;
		i++;
	}
	return true;
}

bool	pos_nb_checker(char *map, t_cub *data)
{
	int i;
	int pos;

	pos = 0;
	i = 0;
	while (map[i + 1] != '\0')
	{
		if (map[i] == 'N'
			|| map[i] == 'S'
			|| map[i] == 'W'
			|| map[i] == 'E')
		{
			data->player_dir = map[i];
			pos++;
		}
		if (pos > 1)
			return false;
		i++;
	}
	if (pos != 1)
		return false;
	return true;
}
bool	check_walls(t_cub *cub, char **map, int i, int j)
{
	if (j - 1 >= 0 && j - 1 < cub->map->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1]))
			if (map[j - 1][i - 1] == '0')
				return false;
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1]))
			if (map[j - 1][i + 1] == '0')
				return false;
		if (i >= 0 && i < (int)ft_strlen(map[j - 1]))
			if (map[j - 1][i] == '0')
				return false;
	}
	if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j]))
		if (map[j][i - 1] == '0')
			return false;
	if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j]))
		if (map[j][i + 1] == '0')
			return false;
	if (j + 1 >= 0 && j + 1 < cub->map->height)
	{
		if (i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1]))
			if (map[j + 1][i - 1] == '0')
				return false;
		if (i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1]))
			if (map[j + 1][i + 1] == '0')
				return false;
		if (i >= 0 && i < (int)ft_strlen(map[j + 1]))
			if (map[j + 1][i] == '0')
				return false;
	}
	return true;
}

void	set_player_pos(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_tab[i])
	{
		j = 0;
		while (data->map->map_tab[i][j] != '\0')
		{
			if (data->map->map_tab[i][j] == 'N'
				|| data->map->map_tab[i][j] == 'S'
				|| data->map->map_tab[i][j] == 'W'
				|| data->map->map_tab[i][j] == 'E')
			{
				data->pos_X = j;
				data->pos_Y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	map_checker(t_cub *data, char **map)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->map->height)
	{
		i = -1;
		while (++i < data->map->width)
		{
			if (map[j][i] == ' ')
				if (!check_walls(data, map, i, j))
					return false;
		}
	}
	return true;
}