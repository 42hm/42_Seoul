/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:37:12 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/25 17:10:13 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>

enum e_handle
{
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	REDCROSS = 17,
	ESC = 53,
	BITSIZE = 34,
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126,
};

typedef struct s_check
{
	int			exit_num;
	int			start_num;
	int			collect_num;
}				t_check;

typedef struct s_map
{
	char		**maparr;
	int			width;
	int			height;
	int			collect_num;
	int			exit_flag;
	void		*wall;
	void		*floor;
	void		*collect;
	void		*enemy;
	void		*player;
	void		*wayout;
}				t_map;

typedef struct s_mlx
{
	int			x;
	int			y;
	int			loop;
	int			move_count;
	char		cur_key;
	void		*mlx_ptr;
	void		*window;
	t_map		*map;
}				t_mlx;

void	is_file_compatibility(int ac, char **av);
void	is_map_compatibility(char *file, t_map *map);

void	make_bonus(t_map *map);
int		so_long_exit(t_mlx *mlx);

void	init_mlx(t_mlx *mlx);
void	draw_map(t_mlx *mlx);

void	init_images(t_mlx *mlx);

void	move_right(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_up(t_mlx *mlx);

#endif
