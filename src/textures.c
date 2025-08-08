/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:27:57 by psirault          #+#    #+#             */
/*   Updated: 2025/08/08 22:54:22 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	north_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "NO") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->no_texture = tab[1];
	//printf("\nNO TEXTURE :%s", data->no_texture);
}

void	south_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "SO") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->so_texture = tab[1];
	//printf("\nSO TEXTURE PATH : %s", data->so_texture);
}

void	east_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "EA") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->ea_texture = tab[1];
	//printf("\nEA TEXTURE PATH : %s", data->ea_texture);
}

void	west_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "WE") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->we_texture = tab[1];
	//printf("\nWE TEXTURE PATH : %s", data->we_texture);
}