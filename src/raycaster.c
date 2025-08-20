/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:00:27 by psirault          #+#    #+#             */
/*   Updated: 2025/08/20 12:29:05 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void raycast_init(int x, t_player *player, t_ray *ray)
{
	ray->cameraX = 2 * x / (double)WIDTH - 1;
	ray->dirX = player->dirX + player->planeX * ray->cameraX;
	ray->dirY = player->dirY + player->planeY * ray->cameraX;
	ray->mapX = (int)player->pos_X;
	ray->mapY = (int)player->pos_Y;
	ray->deltaDistX = fabs(1 / ray->dirX);
	ray->deltaDistY = fabs(1 / ray->dirY);
}

void	dda_init(t_ray *ray, t_player *player)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->pos_X - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->pos_X) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->pos_Y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->pos_Y) * ray->deltaDistY;
	}
}

void	exec_dda(t_cub *data, t_ray *ray, t_player *player)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (ray->mapY < 0.25
			|| ray->mapX < 0.25
			|| ray->mapY > data->map->height - 0.25
			|| ray->mapX > data->map->width - 1.25)
			break ;
		else if (data->map->map_tab[ray->mapY][ray->mapX] > '0')
			hit = 1;
	}
}

int raycaster(t_cub *data, t_player *player)
{
	t_ray *ray;
	int x;

	x = 0;
	ray = data->ray;
	while (x < WIDTH)
	{
		raycast_init(x, player, ray);
		dda_init(ray, player);
		exec_dda(data, ray, player);
		
		
		x++;
	}
	return 0;
}