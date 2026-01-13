/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:44:02 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 15:48:34 by anisabel         ###   ########.fr       */
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
/* void	ft_put_value(t_map *map)
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
} */

/* int	ft_check_lines(int fd, t_map *map)
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
} */

/* int	ft_mapsize(t_map *map, char *file)
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
} */

/* int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\r')
		i++;
	while (i > 0 && str[i - 1] == ' ')
		i--;
	return (i);
} */

/* bool	ft_fill_map(t_map *map, char *file)
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
} */

/*
	Vai ler o ficheiro do mapa e guardá-lo em memória, 
	dentro de map->design (**char);

design
 ├── design[0] -> "111111\n"
 ├── design[1] -> "1P0C01\n"
 ├── design[2] -> "100001\n"
 ├── design[3] -> "111111\n"
 └── design[4] -> NULL

 -----------------------------------

	Preferencialmente, caso a leitura  no mapa não seja feita até 
	ao fim ou caso ocorra algum
	erro, o correto seria libertar cada linha e depois libertar todo o array



	int	ft_mapsize(t_map *map, char *file)

{
    int		fd;
    char	*line;
    int		w;
	int		len;

    fd = open(file,O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    if (!line)
        return (close(fd), 0);
    w = ft_line_len(line);
	if (w == 0)
		return (free(line), close(fd), 0);
    map->width = w;
    map->height = 1;
    free(line);
    while ((line = get_next_line(fd)))
    {
		len = ft_line_len(line);
		if (len == 0)
		{
			ft_printf("Error\nEmpty line in map\n");
            return (free(line), close(fd), 0);
		if (len != w)
		{
            ft_printf("Error\nLine %d has wrong size\n", map->height + 1);
            return (free(line), close(fd), 0);			
		}
		map ->height++;
		free(line);
	}
	return (close(fd), 1);
}

int	ft_mapsize(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		len;

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
	while ((line = get_next_line(fd)))
	{
		len = ft_line_len(line);
		if (len == 0 || len != map->width)
			return (free(line), close(fd), 0);
		map->height++;
		free(line);
	}
	return (close(fd), 1);
}

int	ft_mapsize(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		len;

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
	line = get_next_line(fd);
	while (line)
	{
		len = ft_line_len(line);
		if (len == 0 || len != map->width)
			return (free(line), close(fd), 0);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}
*/
