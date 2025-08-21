/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:28:49 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 12:30:29 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_cub *cub)
{
	double next_y = cub->player->pos_Y + cub->player->dirY * MOVESPEED;
	double next_x = cub->player->pos_X + cub->player->dirX * MOVESPEED;

	if (next_y >= 0 && next_y < cub->map->height &&
			cub->player->pos_X >= 0 && cub->player->pos_X < cub->map->width &&
			cub->map->map_tab[(int)next_y][(int)cub->player->pos_X] == '0')
		cub->player->pos_Y = next_y;
	if (cub->player->pos_Y >= 0 && cub->player->pos_Y < cub->map->height &&
			next_x >= 0 && next_x < cub->map->width &&
			cub->map->map_tab[(int)cub->player->pos_Y][(int)next_x] == '0')
		cub->player->pos_X = next_x;
}

void	move_backward(t_cub *cub)
{
	double next_y = cub->player->pos_Y - cub->player->dirY * MOVESPEED;
	double next_x = cub->player->pos_X - cub->player->dirX * MOVESPEED;

	if (next_y >= 0 && next_y < cub->map->height &&
			cub->player->pos_X >= 0 && cub->player->pos_X < cub->map->width &&
			cub->map->map_tab[(int)next_y][(int)cub->player->pos_X] == '0')
		cub->player->pos_Y = next_y;
	if (cub->player->pos_Y >= 0 && cub->player->pos_Y < cub->map->height &&
			next_x >= 0 && next_x < cub->map->width &&
			cub->map->map_tab[(int)cub->player->pos_Y][(int)next_x] == '0')
		cub->player->pos_X = next_x;
}

void	move_left(t_cub *cub)
{
	double next_y = cub->player->pos_Y - cub->player->planeY * MOVESPEED;
	double next_x = cub->player->pos_X - cub->player->planeX * MOVESPEED;

	if (next_y >= 0 && next_y < cub->map->height &&
			cub->player->pos_X >= 0 && cub->player->pos_X < cub->map->width &&
			cub->map->map_tab[(int)next_y][(int)cub->player->pos_X] == '0')
		cub->player->pos_Y = next_y;
	if (cub->player->pos_Y >= 0 && cub->player->pos_Y < cub->map->height &&
			next_x >= 0 && next_x < cub->map->width &&
			cub->map->map_tab[(int)cub->player->pos_Y][(int)next_x] == '0')
		cub->player->pos_X = next_x;
}

void	move_right(t_cub *cub)
{
	double next_y = cub->player->pos_Y + cub->player->planeY * MOVESPEED;
	double next_x = cub->player->pos_X + cub->player->planeX * MOVESPEED;

	if (next_y >= 0 && next_y < cub->map->height &&
			cub->player->pos_X >= 0 && cub->player->pos_X < cub->map->width &&
			cub->map->map_tab[(int)next_y][(int)cub->player->pos_X] == '0')
		cub->player->pos_Y = next_y;
	if (cub->player->pos_Y >= 0 && cub->player->pos_Y < cub->map->height &&
			next_x >= 0 && next_x < cub->map->width &&
			cub->map->map_tab[(int)cub->player->pos_Y][(int)next_x] == '0')
		cub->player->pos_X = next_x;
}