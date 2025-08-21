/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:03:29 by psirault          #+#    #+#             */
/*   Updated: 2025/08/21 12:10:02 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arg_check(t_cub *data, int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Use the program as follows: ./cub3d file.cub");	
		free(data);
		return ;
	}
	if (!is_correct_extension(argv[1], "cub"))
	{
		printf("Invalid file extension. Use .cub files only.\n");
		free(data);
		return ;
	}
}