/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 03:53:01 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:51:13 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_select_image(int x, int y, t_map *map)
{
	if (x == 0 || y == 0)
		return (WALL);
	if (x == (map->width - 1))
		return (WALL);
	if (y == (map->height - 1))
		return (WALL);
	if (map->design[y][x] == '1')
		return (WALL);
	if (map->design[y][x] == 'C')
		return (COLLECTABLE);
	if (map->design[y][x] == 'P')
		return (LARA);
	if (map->design[y][x] == 'E')
		return (EXIT);
	return (FLOOR);
}

int	ft_put_img_to_window(t_game *game, int x, int y, t_map *map)
{
	int		img_width;
	int		img_height;
	char	*relative_path;

	if (game->pos >= game->map->height * game->map->width)
		return (ft_printf("ERROR!\npos exceeds size for game->img.\n\n"), 0);
	relative_path = NULL;
	relative_path = ft_select_image(x, y, map);
	if (!relative_path)
		return (ft_printf("ERROR!\nFailed to select image (%d,%d).\n\n",
				x, y), 0);
	img_height = SIZE;
	img_width = SIZE;
	game->img[game->pos].img = mlx_xpm_file_to_image(game->mlx,
			relative_path, &img_width, &img_height);
	if (!game->img[game->pos].img)
	{
		ft_printf("ERROR!\nFailed to load image '%s'.\n", relative_path);
		return (0);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[game->pos++].img, x * SIZE, y * SIZE);
	return (1);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;
	int	image;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			image = ft_put_img_to_window(game, x, y, game->map);
			if (!image)
				return (ft_printf("ERROR\n Missing image.\n\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
