/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:02:34 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 12:08:46 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	malloc_error(void)
{
	perror("There was an issue with memory allocation");
	exit(EXIT_FAILURE);
}

static void	window_error(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub->mlx);
	malloc_error();
}

static void	image_error(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub);
	malloc_error();
}

void	initialize_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		malloc_error();
	cub->win = mlx_new_window(cub->mlx, 800, 800, "cub3d");
	if (cub->win == NULL)
		window_error(cub);
	cub->img.data = mlx_new_image(cub->mlx, 800, 800);
	if (cub->img.data == NULL)
		image_error(cub);
	cub->img.addr = mlx_get_data_addr(cub->img.data,
		 &cub->img.bits_per_pixel,
		 &cub->img.line_length,
		 &cub->img.endian);
}