/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:33:30 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/25 17:27:29 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	move_handle(t_mlx *mlx)
{
	if (mlx->map->maparr[mlx->y][mlx->x] == 'C')
	{
		mlx->map->collect_num--;
		mlx->map->maparr[mlx->y][mlx->x] = '0';
	}
	if (mlx->map->maparr[mlx->y][mlx->x] == 'B')
		so_long_exit(mlx);
	if (mlx->map->maparr[mlx->y][mlx->x] == 'E')
	{
		if (mlx->map->collect_num == 0)
			so_long_exit(mlx);
		mlx->map->exit_flag = 1;
	}
	else
		mlx->map->exit_flag = 0;
	mlx->map->maparr[mlx->y][mlx->x] = 'P';
	mlx->move_count++;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_up(t_mlx *mlx)
{
	mlx->cur_key = 'W';
	if (mlx->map->exit_flag == 1)
	{
		mlx->map->maparr[mlx->y][mlx->x] = 'E';
		draw_map(mlx);
	}
	if (mlx->map->maparr[mlx->y][mlx->x] != 'E')
		mlx->map->maparr[mlx->y][mlx->x] = '0';
	mlx->y -= 1;
	if (mlx->map->maparr[mlx->y][mlx->x] == '1')
		mlx->y += 1;
	move_handle(mlx);
}

void	move_left(t_mlx *mlx)
{
	mlx->cur_key = 'A';
	if (mlx->map->exit_flag == 1)
	{
		mlx->map->maparr[mlx->y][mlx->x] = 'E';
		draw_map(mlx);
	}
	if (mlx->map->maparr[mlx->y][mlx->x] != 'E')
		mlx->map->maparr[mlx->y][mlx->x] = '0';
	mlx->x -= 1;
	if (mlx->map->maparr[mlx->y][mlx->x] == '1')
		mlx->x += 1;
	move_handle(mlx);
}

void	move_down(t_mlx *mlx)
{
	mlx->cur_key = 'S';
	if (mlx->map->exit_flag == 1)
	{
		mlx->map->maparr[mlx->y][mlx->x] = 'E';
		draw_map(mlx);
	}
	if (mlx->map->maparr[mlx->y][mlx->x] != 'E')
		mlx->map->maparr[mlx->y][mlx->x] = '0';
	mlx->y += 1;
	if (mlx->map->maparr[mlx->y][mlx->x] == '1')
		mlx->y -= 1;
	move_handle(mlx);
}

void	move_right(t_mlx *mlx)
{
	mlx->cur_key = 'D';
	if (mlx->map->exit_flag == 1)
	{
		mlx->map->maparr[mlx->y][mlx->x] = 'E';
		draw_map(mlx);
	}
	if (mlx->map->maparr[mlx->y][mlx->x] != 'E')
		mlx->map->maparr[mlx->y][mlx->x] = '0';
	mlx->x += 1;
	if (mlx->map->maparr[mlx->y][mlx->x] == '1')
		mlx->x -= 1;
	move_handle(mlx);
}
