/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:27:57 by psirault          #+#    #+#             */
/*   Updated: 2025/08/13 15:16:07 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	north_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;
	void	*img;
	int		img_width = 0;
	int		img_height = 0;
	
	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "NO") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->no_texture = ft_strtrim(tab[1], "\n");
	if (!is_correct_extension(data->no_texture, "xpm"))
		return ;
	img = mlx_xpm_file_to_image(data->mlx, data->no_texture, &img_height, &img_width);
	if (!img)
	{
		printf("North texture reading failed.");
		return ;
	}
	if (img_height != 64 || img_width != 64)
	{
		printf("Invalid north texture width or height.");
		return ;
	}
	// printf("IMGH : %d, IMGW : %d", img_height, img_width);
	// printf("\nNO TEXTURE :%s", data->no_texture);
}

void	south_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;
	void	*img;
	int		img_width = 0;
	int		img_height = 0;
	
	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "SO") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->so_texture = ft_strtrim(tab[1], "\n");
	if (!is_correct_extension(data->so_texture, "xpm"))
		return ;
	img = mlx_xpm_file_to_image(data->mlx, data->so_texture, &img_height, &img_width);
	if (!img)
	{
		printf("South texture reading failed.");
		return ;
	}
	if (img_height != 64 || img_width != 64)
	{
		printf("Invalid south texture width or height.");
		return ;
	}
	//printf("\nSO TEXTURE PATH : %s", data->so_texture);
}

void	east_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;
	void	*img;
	int		img_width = 0;
	int		img_height = 0;
	
	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "EA") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->ea_texture = ft_strtrim(tab[1], "\n");
	if (!is_correct_extension(data->ea_texture, "xpm"))
		return ;
	img = mlx_xpm_file_to_image(data->mlx, data->ea_texture, &img_height, &img_width);
	if (!img)
	{
		printf("East texture reading failed.");
		return ;
	}
	if (img_height != 64 || img_width != 64)
	{
		printf("Invalid east texture width or height.");
		return ;
	}
	//printf("\nEA TEXTURE PATH : %s", data->ea_texture);
}

void	west_texture(t_cub *data)
{
	char	**line;
	char	**tab;
	int		i;
	void	*img;
	int		img_width = 0;
	int		img_height = 0;
	
	i = 0;
	line = data->map->infos;
	while (!ft_strstr(line[i], "WE") && line[i])
		i++;
	tab = ft_split(line[i], " \t");
	data->we_texture = ft_strtrim(tab[1], "\n");
	if (!is_correct_extension(data->we_texture, "xpm"))
		return ;
	img = mlx_xpm_file_to_image(data->mlx, data->we_texture, &img_height, &img_width);
	if (!img)
	{
		printf("West texture reading failed.");
		return ;
	}
	if (img_height != 64 || img_width != 64)
	{
		printf("Invalid west texture width or height.");
		return ;
	}
	//printf("\nWE TEXTURE PATH : %s", data->we_texture);
}