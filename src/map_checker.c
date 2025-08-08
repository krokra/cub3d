/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:46:31 by psirault          #+#    #+#             */
/*   Updated: 2025/08/07 12:59:27 by psirault         ###   ########.fr       */
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
			data->player_pos = map[i];
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
