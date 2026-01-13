/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 00:38:48 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:53:38 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cancel(t_map *map, t_game *game, char *s)
{
	ft_printf("ERROR!\nFailed to initialize %s.\n", s);
	ft_free_design(map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	main(int argc, char**argv)
{
	t_game		game;
	t_map		map;
	t_player	player;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("ERROR!\n Please use ./so_long map.ber\n\n");
		return (0);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	if (!ft_init_map(&map, argv[1]))
	{
		ft_cancel(&map, &game, "map");
		return (0);
	}
	if (!ft_init_player(&player))
	{
		ft_cancel(&map, &game, "player");
		return (0);
	}
	start_game(&map, &player, game);
	return (0);
}
