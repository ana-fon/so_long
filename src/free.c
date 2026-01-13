/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 02:17:19 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 05:08:35 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_design(t_map *map)
{
	int	i;

	i = 0;
	if (!map->design)
		return ;
	while (i < map->height)
		free(map->design[i++]);
	free(map->design);
}

void	ft_free_img(t_game	*game)
{
	if (game->img)
	{
		game->pos--;
		while (game->pos >= 0)
		{
			if (game->img[game->pos].img)
				mlx_destroy_image(game->mlx, game->img[game->pos].img);
			game->pos--;
		}
		free(game->img);
	}
}

void	ft_free(t_game *game)
{
	if (game->map)
		ft_free_design(game->map);
	ft_free_img(game);
	if (game-> mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
