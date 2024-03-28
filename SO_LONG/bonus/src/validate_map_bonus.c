/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:34:34 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/25 17:28:10 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	check_char(t_check *check, char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_error_exit("Error\nInvalid map charset");
	if (c == 'E')
		check->exit_num++;
	else if (c == 'P')
		check->start_num++;
	else if (c == 'C')
		check->collect_num++;
}

static void	is_map_possible(t_map *map)
{
	int		x;
	int		y;
	t_check	check;

	ft_memset(&check, 0, sizeof(t_check));
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (((y == 0 || y == map->height - 1) && map->maparr[y][x] != '1')
			|| ((x == 0 || x == map->width - 1) && map->maparr[y][x] != '1'))
				ft_error_exit("Error\nMap is not closed");
			check_char(&check, map->maparr[y][x]);
		}
	}
	if (check.collect_num < 1 || check.exit_num < 1 \
	|| check.start_num < 1 || check.start_num != 1)
		ft_error_exit("Error\nInvalid map charset");
	map->collect_num = check.collect_num;
}

static void	get_map_size(char *file, t_map *map)
{
	int		fd;
	int		gnl;
	char	*str;

	fd = ft_open(file, 0);
	gnl = get_next_line(fd, &str);
	if (!gnl)
		ft_error_exit("Error\nEmpty file");
	map->width = (int)(ft_strlen(str));
	while (gnl > 0)
	{
		if ((int)(ft_strlen(str)) != map->width)
		{
			ft_close(fd);
			free(str);
			ft_error_exit("Error\nMap must be rectangle");
		}
		free(str);
		map->height++;
		gnl = get_next_line(fd, &str);
	}
	free(str);
	ft_close(fd);
}

void	is_map_compatibility(char *file, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = ft_open(file, 0);
	get_map_size(file, map);
	if (map->height < 3 || map->width < 3 \
	|| map->height > 30 || map->width > 50)
		ft_error_exit("Error\nInvalid map size");
	map->maparr = ft_malloc(sizeof(char *) * (map->height + 1));
	while ((get_next_line(fd, &line) > 0))
	{
		map->maparr[i++] = ft_strdup(line);
		free(line);
	}
	map->maparr[i] = ft_strdup(line);
	free(line);
	ft_close(fd);
	is_map_possible(map);
}
