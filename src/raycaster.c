/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:00:27 by psirault          #+#    #+#             */
/*   Updated: 2025/08/20 15:58:41 by psirault         ###   ########.fr       */
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
        // Use integer boundary checks
        if (ray->mapY < 0 || ray->mapX < 0 ||
            ray->mapY >= data->map->height ||
            ray->mapX >= data->map->width)
        {
            // Set hit to avoid using uninitialized values
            hit = 1;
            // Optionally, set a flag to indicate no wall was hit
            ray->wall_distance = (int)1e30; // Large value to avoid division by zero
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

void	raycasting(t_cub *data)
{
    t_ray	*ray = malloc(sizeof(t_ray));
    int		x, y;
    int		color;

	data->ray = ray;
    for (x = 0; x < WIDTH; x++)
    {
        raycast_init(x, data->player, ray);
        dda_init(ray, data->player);
        exec_dda(data, ray);
        line_height(ray, data->player, data);

        // Choose color based on wall side (simple example)
        color = (ray->side == 0) ? 0xAAAAAA : 0x555555;

        // Draw vertical line for this column
        for (y = 0; y < HEIGHT; y++)
        {
            if (y >= ray->draw_start && y <= ray->draw_end)
                my_mlx_pixel_put(&data->img, x, y, color); // Wall
            else if (y < ray->draw_start)
                my_mlx_pixel_put(&data->img, x, y, 0x87CEEB); // Ceiling (sky blue)
            else
                my_mlx_pixel_put(&data->img, x, y, 0x222222); // Floor (dark)
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.data, 0, 0);
}