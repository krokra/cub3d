/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:34:02 by psirault          #+#    #+#             */
/*   Updated: 2025/08/07 11:39:17 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_correct_extension(char *filename, char *ext)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (filename[i] != '.' && filename[i] != '\0')
		i++;
	if (filename[i] == '\0' || !filename[i])
		return false;
	while (filename[++i] == ext[j] && filename[i] && ext[j])
		j++;
	if (ext[j] == '\0' && filename[i] == 0)
		return true;
	return false;
}

bool	is_line_empty(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\n')
		return true;
	while (line[i] != '\0')
	{
		if (line[i] != ' '
			&& line[i] != '\t')
			return false;
		i++;
	}
	return true;
}

bool	is_valid_identifier(char *line)
{
	char ID[2];

	if (!is_line_empty(line))
	{
		ID[0] = line[0];
		ID[1] = line[1];
	}
	printf("%s", ID);
	if (ft_strcmp(ID, "NO") == 0
		|| ft_strcmp(ID, "SO") == 0
		|| ft_strcmp(ID, "EA") == 0
		|| ft_strcmp(ID, "WE") == 0
		|| ft_strcmp(ID, "C ") == 0
		|| ft_strcmp(ID, "F ") == 0)
		return true;
	return false;
}