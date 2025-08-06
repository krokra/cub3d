/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:46:31 by psirault          #+#    #+#             */
/*   Updated: 2025/08/06 14:32:54 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool is_first_or_last_line_valid(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' || line[i] != ' ')
			return false;
	}
	return true;
}

bool	is_map_valid(char *map)
{
	int i;
	int pos;

	pos = 0;
	i = 0;
	while (map[i + 1] != '\0')
	{
		if (map[i] != 'N' && map[i] != 'S' && map[i] != 'W' && map[i] != 'E' && map[i] != '0' && map[i] != '1' && map[i] != ' ')
			return false;
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
			pos++;
		if (pos > 1)
			return false;
		i++;
	}
	if (map[i] != 1 || pos != 0)
		return false;
	return true;
}
