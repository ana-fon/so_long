/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 02:35:48 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:59:03 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_finish(t_game *game)
{
	ft_free(game);
	return ;
}

int	ft_quit(t_game *game)
{
	ft_printf("Well that's unfortunate :(\n\n");
	ft_free(game);
	return (0);
}

void	is_movement(int keysym, t_game *game)
{
	if (keysym == XK_w)
		ft_up(game);
	if (keysym == XK_a)
		ft_left(game);
	if (keysym == XK_s)
		ft_down(game);
	if (keysym == XK_d)
		ft_right(game);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		ft_quit(game);
		exit(1);
	}
	else
		is_movement(keysym, game);
	return (0);
}

void	start_game(t_map *map, t_player *player, t_game game)
{
	game.map = map;
	game.player = player;
	game.player->x = map->start_x;
	game.player->y = map->start_y;
	game.img = malloc(sizeof(t_data) * (game.map->height * game.map->width));
	if (!game.img)
	{
		ft_printf("ERROR!\n Malloc failed game.img.\n");
		ft_finish(&game);
		return ;
	}
	game.pos = 0;
	game.win = mlx_new_window(game.mlx, map->width * SIZE,
			map->height * SIZE, "Lara Croft Adventures");
	if (!ft_render_map(&game))
	{
		ft_printf("ERROR!\n Could not render the game.\n\n");
		ft_finish(&game);
	}
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_input, &game);
	mlx_hook(game.win, DestroyNotify, 0, &ft_quit, &game);
	mlx_loop(game.mlx);
}
