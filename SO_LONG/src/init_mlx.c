/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:40:56 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/24 20:38:45 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_01b(t_mlx *mlx, int x, int y)
{
	if (mlx->map->maparr[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->wall, x * BITSIZE, y * BITSIZE);
	else if (mlx->map->maparr[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->floor, x * BITSIZE, y * BITSIZE);
	else if (mlx->map->maparr[y][x] == 'B')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->enemy, x * BITSIZE, y * BITSIZE);
}

static void	draw_cep(t_mlx *mlx, int x, int y)
{
	char	*temp;

	if (mlx->map->maparr[y][x] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->collect, x * BITSIZE, y * BITSIZE);
	}
	else if (mlx->map->maparr[y][x] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->wayout, x * BITSIZE, y * BITSIZE);
	}
	else if (mlx->map->maparr[y][x] == 'P')
	{
		mlx->x = x;
		mlx->y = y;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->player, x * BITSIZE, y * BITSIZE);
	}
	mlx_string_put(mlx->mlx_ptr, mlx->window, 13, 20, \
	0xFFFFFF, temp = ft_itoa(mlx->move_count));
	free(temp);
}

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	init_images(mlx);
	y = -1;
	while (++y < mlx->map->height)
	{
		x = -1;
		while (++x < mlx->map->width)
		{
			if (ft_strchr("01B", mlx->map->maparr[y][x]))
				draw_01b(mlx, x, y);
			else if (ft_strchr("CEP", mlx->map->maparr[y][x]))
				draw_cep(mlx, x, y);
		}
	}
}

void	init_mlx(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->map->width * 34, \
			mlx->map->height * 34, "so_long");
	if (mlx->window == NULL)
		ft_error_exit("Error\nmlx_new_window error");
	y = -1;
	while (++y < mlx->map->height)
	{
		x = -1;
		while (++x < mlx->map->width)
		{
			if (mlx->map->maparr[y][x] == 'P')
			{
				mlx->x = x;
				mlx->y = y;
				mlx->cur_key = 'S';
				mlx->loop = 0;
				mlx->move_count = 0;
				return ;
			}
		}
	}
}
