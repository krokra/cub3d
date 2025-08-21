/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:00:27 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 11:51:52 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->cameraX = 0;
	ray->dirX = 0;
	ray->dirY = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->wall_distance = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void raycast_init(int x, t_player *player, t_ray *ray)
{
	init_ray(ray);
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

void	exec_dda(t_cub *data, t_ray *ray)
{
    int hit = 0;
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
        if (ray->mapY < 0 || ray->mapX < 0 ||
            ray->mapY >= data->map->height ||
            ray->mapX >= data->map->width)
        {
            hit = 1;
            ray->wall_distance = 1e30;
            break;
        }
        else if (data->map->map_tab[ray->mapY][ray->mapX] == '1')
            hit = 1;
    }
}

void	line_height(t_ray *ray, t_player *player, t_cub *data)
{
	if (ray->side == 0)
		ray->wall_distance = (ray->sideDistX - ray->deltaDistX);
	else
		ray->wall_distance = (ray->sideDistY - ray->deltaDistY);
	ray->line_height = (int)(data->w_height / ray->wall_distance);
	ray->draw_start = -(ray->line_height) / 2 + data->w_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->w_height / 2;
	if (ray->draw_end >= data->w_height)
		ray->draw_end = data->w_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_Y + ray->wall_distance * ray->dirY;
	else
		ray->wall_x = player->pos_X + ray->wall_distance * ray->dirX;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_cub *data)
{
    int		x, y;
    int		color;

    for (x = 0; x < WIDTH; x++)
    {
        raycast_init(x, data->player, data->ray);
        dda_init(data->ray, data->player);
        exec_dda(data, data->ray);
        line_height(data->ray, data->player, data);
		if (data->ray->side == 0)
			color = 0x00ff00;
		else
			color = 0xff00ff;
        for (y = 0; y < HEIGHT; y++)
        {
            if (y >= data->ray->draw_start && y <= data->ray->draw_end)
                my_mlx_pixel_put(&data->img, x, y, color);
			else if (y < data->ray->draw_start)
				my_mlx_pixel_put(&data->img, x, y, (data->ceiling_rgb->R << 16) | (data->ceiling_rgb->G << 8) | data->ceiling_rgb->B);
			else if (y > data->ray->draw_end)
				my_mlx_pixel_put(&data->img, x, y, (data->floor_rgb->R << 16) | (data->floor_rgb->G << 8) | data->floor_rgb->B);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.data, 0, 0);
	return 0;
}