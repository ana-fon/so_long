/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:44:02 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/14 13:03:17 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_map(t_map *map, char *file)
{
	int	fd;

	ft_memset(map, 0, sizeof(t_map));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\n Invalid map.\n"), 0);
	close(fd);
	ft_put_value(map);
	if (!ft_mapsize(map, file))
		return (ft_printf("ERROR!\nWrong map size.\n\n"), 0);
	if (!ft_fill_map(map, file))
		return (ft_printf("Error/n Failed to fill the map.\n"),
			0);
	if (!ft_check_map(map, file))
		return (0);
	return (1);
}

void	ft_put_value(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->is_collectable = 0;
	map->is_exit = 0;
	map->is_player = 0;
	map->is_floor = 0;
	map->design = NULL;
}
