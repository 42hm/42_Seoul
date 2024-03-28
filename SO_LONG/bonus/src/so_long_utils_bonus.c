/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:02:27 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/25 17:27:39 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static unsigned int	ft_rand(unsigned int seed)
{
	unsigned int	next;

	next = seed * 1103515245 + 12345;
	return ((next >> 16) & 0x7fffffff);
}

static void	destroy_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->floor);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->enemy);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->collect);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->player);
}

int	so_long_exit(t_mlx *mlx)
{
	int	i;

	i = 0;
	destroy_image(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(0);
	return (0);
}

void	make_bonus(t_map *map)
{
	unsigned int	seed;
	unsigned int	prev;
	int				x;
	int				y;

	seed = map->width * map->height * map->collect_num;
	prev = ft_rand(seed);
	x = 0;
	y = 0;
	while (++y < map->height)
	{
		x = 0;
		while (++x < map->width)
		{
			if (map->maparr[y][x] == '0')
			{
				if (prev % 10 == 0 && map->maparr[y][x - 1] != 'B')
					map->maparr[y][x] = 'B';
				prev = ft_rand(prev);
			}
		}
	}
}
