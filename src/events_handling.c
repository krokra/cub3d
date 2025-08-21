/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:17:00 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 12:31:20 by psirault         ###   ########.fr       */
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

int	key_hook(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		ft_close_window(cub);
	if (keysym == XK_Z || keysym == XK_Up)
		move_forward(cub);
	else if (keysym == XK_S || keysym == XK_Down)
		move_backward(cub);
	else if (keysym == XK_Q || keysym == XK_Left)
		move_left(cub);
	else if (keysym == XK_D || keysym == XK_Right)
		move_right(cub);
	raycasting(cub);
	return (0);
}

void	events_handling(t_cub *cub)
{
	mlx_hook(cub->win, 02, (1L << 0), key_hook, cub);
	mlx_hook(cub->win, 17, (1L << 17), ft_close_window, cub);
}