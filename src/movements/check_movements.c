/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:57:39 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 05:53:36 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y - 1][x] == '1')
		return (0);
	if (game->map->design[y - 1][x] == 'C')
	{
		game->map->is_collectable--;
		game->map->design[y - 1][x] = '0';
	}
	if (game->map->design[y - 1][x] == 'E' && !game->map->is_collectable)
	{
		game->player->moves++;
		ft_printf("Congrats, you won!\n");
		return (ft_finish(game), 0);
	}
	if (game->map->design[y - 1][x] == 'E' && game->map->is_collectable)
		return (0);
	return (1);
}

int	ft_check_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y + 1][x] == '1')
		return (0);
	if (game->map->design[y + 1][x] == 'C')
	{
		game->map->is_collectable--;
		game->map->design[y + 1][x] = '0';
	}
	if (game->map->design[y + 1][x] == 'E' && !game->map->is_collectable)
	{
		game->player->moves++;
		ft_printf("Congrats, you won!\n");
		return (ft_finish(game), 0);
	}
	if (game->map->design[y + 1][x] == 'E' && game->map->is_collectable)
		return (0);
	return (1);
}

int	ft_check_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y][x + 1] == '1')
		return (0);
	if (game->map->design[y][x + 1] == 'C')
	{
		game->map->is_collectable--;
		game->map->design[y][x + 1] = '0';
	}
	if (game->map->design[y][x + 1] == 'E' && !game->map->is_collectable)
	{
		game->player->moves++;
		ft_printf("Congrats, you won!\n");
		return (ft_finish(game), 0);
	}
	if (game->map->design[y][x + 1] == 'E' && game->map->is_collectable)
		return (0);
	return (1);
}

int	ft_check_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->design[y][x - 1] == '1')
		return (0);
	if (game->map->design[y][x - 1] == 'C')
	{
		game->map->is_collectable--;
		game->map->design[y][x - 1] = '0';
	}
	if (game->map->design[y][x - 1] == 'E' && !game->map->is_collectable)
	{
		game->player->moves++;
		ft_printf("Congrats, you won!\n");
		return (ft_finish(game), 0);
	}
	if (game->map->design[y][x - 1] == 'E' && game->map->is_collectable)
		return (0);
	return (1);
}
