/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 22:30:27 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:49:44 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_goals(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] == 'C')
				map->is_collectable++;
			if (map->design[y][x] == 'E')
				map->is_exit++;
			if (map->design[y][x] == 'P')
				map->is_player++;
			x++;
		}
		y++;
	}
	if (map->is_collectable < 1 || map->is_exit != 1 || map->is_player != 1)
		return (0);
	return (1);
}

int	ft_check_walls(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[0][x] != '1')
				return (0);
			if (map->design[y][0] != '1')
				return (0);
			if (map->design[y][map->width - 1] != '1')
				return (0);
			if (map->design[map->height - 1][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map_components(t_map	*map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->design[y][x] != '1' && map->design[y][x] != '0'
				&& map->design[y][x] != 'P' && map->design[y][x] != 'C'
				&& map->design[y][x] != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map_name(char *file)
{
	char	*s;
	char	*file_name;
	int		len;

	s = ft_strrchr(file, '.');
	file_name = ft_strrchr(file, '/');
	if (file_name)
		len = ft_strlen(file_name) - 1;
	else
		len = ft_strlen(s);
	if (!s || len < 5 || ft_strncmp(s, EXTENSION, ft_strlen(EXTENSION) + 1))
		return (0);
	return (1);
}

int	ft_check_map(t_map *map, char *file)
{
	if (map->height < 3 || map->width < 3)
		return (ft_printf("ERROR!\nMap is too small.\n\n"), 0);
	if (!ft_check_map_components(map))
		return (ft_printf("ERROR!\nMap is not valid.\n\n"), 0);
	if (!ft_check_walls(map))
		return (ft_printf("ERROR!\nMap is not delimited by walls.\n\n"), 0);
	if (!ft_check_map_goals(map))
		return (ft_printf("ERROR!\nInvalid number of C, E or P.\n\n"), 0);
	if (!ft_check_map_name(file))
		return (ft_printf("Error!\nMap name is invalid.\n\n"), 0);
	if (!ft_check_path(map, file))
		return (ft_printf("Error!\nNo valid path to conclude map.\n\n"), 0);
	return (1);
}
