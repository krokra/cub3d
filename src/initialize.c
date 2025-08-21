/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:30:59 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 11:57:42 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	data_init(t_cub *data)
{
	data->map = malloc(sizeof(t_map));
	data->map->infos = malloc(sizeof(char *) * 100);
	data->floor_rgb = malloc(sizeof(t_rgb));
	data->ceiling_rgb = malloc(sizeof(t_rgb));
	data->player = malloc(sizeof(t_player));
	data->ray = malloc(sizeof(t_ray));
	data->w_height = HEIGHT;
	data->w_width = WIDTH;
}

void	player_init(t_cub *data)
{
	if (data->player->player_dir == 'N')
	{
	    data->player->dirX = 0;
	    data->player->dirY = -1;
	    data->player->planeX = 0.66;
	    data->player->planeY = 0;
	}
	else if (data->player->player_dir == 'S')
	{
	    data->player->dirX = 0;
		data->player->dirY = 1;
		data->player->planeX = -0.66;
		data->player->planeY = 0;
	}
	else if (data->player->player_dir == 'E')
	{
    	data->player->dirX = 1;
 		data->player->dirY = 0;
    	data->player->planeX = 0;
    	data->player->planeY = 0.66;
	}

	else if (data->player->player_dir == 'W')
	{
		data->player->dirX = -1;
		data->player->dirY = 0;
		data->player->planeX = 0;
		data->player->planeY = -0.66;
	}
}

void	textures_and_colors_init(t_cub *data)
{
	north_texture(data);
	south_texture(data);
	east_texture(data);
	west_texture(data);
	floor_color(data);
	ceiling_color(data);
}