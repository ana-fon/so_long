/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:46:52 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 15:51:06 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	ft_fill_map(t_map *map, char *file)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	map->design = malloc(sizeof(char *) * (map->height + 1));
	if (!map->design)
		return (close(fd), false);
	i = 0;
	while (i < map->height)
	{
		map->design[i] = get_next_line(fd);
		if (!map->design[i])
			return (close(fd), false);
		i++;
	}
	map->design[i] = NULL;
	return (close(fd), true);
}

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\r')
		i++;
	while (i > 0 && str[i - 1] == ' ')
		i--;
	return (i);
}

int	ft_check_lines(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_line_len(line);
		if (len == 0 || len != map->width)
			return (free(line), 0);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_mapsize(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	map->width = ft_line_len(line);
	if (map->width == 0)
		return (free(line), close(fd), 0);
	map->height = 1;
	free(line);
	if (!ft_check_lines(fd, map))
		return (close(fd), 0);
	return (close(fd), 1);
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
