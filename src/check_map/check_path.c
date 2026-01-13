/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:19:09 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:50:15 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_p(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
			}
			x++;
		}
		y++;
	}
}

int	is_goal(char c)
{
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'P')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

void	ft_find_path(t_map *map, int x, int y)
{
	if (map->design[y][x] == '1' || map->design[y][x] == 'F')
		return ;
	if (is_goal(map->design[y][x]))
	{
		if (map->design[y][x] == 'C')
			map->is_collectable--;
		if (map->design[y][x] == 'E' && map->is_exit)
			map->is_exit--;
	}
	if (map->design[y][x] == 'E')
		return ;
	map->design[y][x] = 'F';
	ft_find_path(map, x, y - 1);
	ft_find_path(map, x, y + 1);
	ft_find_path(map, x + 1, y);
	ft_find_path(map, x - 1, y);
}

int	ft_check_path(t_map *map, char *file)
{
	int	n_collect;
	int	x;
	int	y;

	ft_get_p(map);
	x = map->start_x;
	y = map->start_y;
	n_collect = map->is_collectable;
	ft_find_path(map, x, y);
	ft_free_design(map);
	ft_fill_map(map, file);
	if (map->is_collectable != 0 || map->is_exit)
		return (0);
	map->is_collectable = n_collect;
	map->is_exit = 1;
	return (1);
}
