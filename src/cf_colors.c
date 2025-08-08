/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:11:11 by psirault          #+#    #+#             */
/*   Updated: 2025/08/08 22:54:15 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ceiling_color(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strchr(line[i], 'C') && line)
		i++;
	tab = ft_split(line[i], " ,\t");
	data->ceiling_rgb = malloc(sizeof(t_rgb));
	data->ceiling_rgb->R = ft_atoi(tab[1]);
	data->ceiling_rgb->G = ft_atoi(tab[2]);
	data->ceiling_rgb->B = ft_atoi(tab[3]);
	// DEBUG
	// printf("\nCEILING RGB :%u,", data->ceiling_rgb->R);
	// printf("%u,", data->ceiling_rgb->G);
	// printf("%u\n", data->ceiling_rgb->B);
}

void	floor_color(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	line = data->map->infos;
	while (!ft_strchr(line[i], 'F') && line)
		i++;
	tab = ft_split(line[i], " ,\t");
	data->floor_rgb = malloc(sizeof(t_rgb));
	data->floor_rgb->R = ft_atoi(tab[1]);
	data->floor_rgb->G = ft_atoi(tab[2]);
	data->floor_rgb->B = ft_atoi(tab[3]);
	// DEBUG
	// printf("\nFLOOR RGB :%u,", data->floor_rgb->R);
	// printf("%u,", data->floor_rgb->G);
	// printf("%u\n", data->floor_rgb->B);
}
