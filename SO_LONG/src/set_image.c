/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:34:23 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 20:58:45 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_images_second(t_mlx *mlx, int temp)
{
	mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/wall2.xpm", &temp, &temp);
	mlx->map->wayout = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/wayout2.xpm", &temp, &temp);
	mlx->map->enemy = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/enemy2.xpm", &temp, &temp);
	mlx->map->collect = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/collect2.xpm", &temp, &temp);
}

static void	set_player_second(t_mlx *mlx, int temp)
{
	if (mlx->cur_key == 'S')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players2.xpm", &temp, &temp);
	if (mlx->cur_key == 'W')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playerw2.xpm", &temp, &temp);
	if (mlx->cur_key == 'A')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playera2.xpm", &temp, &temp);
	if (mlx->cur_key == 'D')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playerd2.xpm", &temp, &temp);
}

static void	set_images_first(t_mlx *mlx, int temp)
{
	mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/wall1.xpm", &temp, &temp);
	mlx->map->wayout = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/wayout1.xpm", &temp, &temp);
	mlx->map->enemy = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/enemy1.xpm", &temp, &temp);
	mlx->map->collect = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./img/collect1.xpm", &temp, &temp);
}

static void	set_player_first(t_mlx *mlx, int temp)
{
	if (mlx->cur_key == 'S')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/players1.xpm", &temp, &temp);
	if (mlx->cur_key == 'W')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playerw1.xpm", &temp, &temp);
	if (mlx->cur_key == 'A')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playera1.xpm", &temp, &temp);
	if (mlx->cur_key == 'D')
		mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"./img/playerd1.xpm", &temp, &temp);
}

void	init_images(t_mlx *mlx)
{
	int	temp;

	temp = BITSIZE;
	mlx->map->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "./img/floor.xpm", \
	&temp, &temp);
	if (20 < mlx->loop)
	{
		set_player_first(mlx, temp);
		set_images_first(mlx, temp);
	}
	else
	{
		set_player_second(mlx, temp);
		set_images_second(mlx, temp);
	}
}
