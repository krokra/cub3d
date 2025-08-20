/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:17:00 by psirault          #+#    #+#             */
/*   Updated: 2025/08/20 16:40:32 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_close_window(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img.data);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(EXIT_SUCCESS);
}

static int	key_hook(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		ft_close_window(cub);
	else if (keysym == XK_Z)
	{
		if(cub->map->map_tab[(int)(cub->player->pos_X + cub->player->dirX * 2)][(int)cub->player->pos_Y] == false) cub->player->pos_X += cub->player->dirX * 2;
		if(cub->map->map_tab[(int)(cub->player->pos_X)][(int)(cub->player->pos_Y + cub->player->dirY * 2)] == false) cub->player->pos_X += cub->player->dirX * 2;
	}
	return (0);
}

void	events_handling(t_cub *cub)
{
	mlx_hook(cub->win, 02, (1L << 0), key_hook, cub);
	mlx_hook(cub->win, 17, (1L << 17), ft_close_window, cub);
}