/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:53:08 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 20:52:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x;
	y = game->player->y * game->map->width;
	if (!ft_check_up(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	y -= game->map->width;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, LARA, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	game->player->y--;
	game->player->moves++;
	ft_printf("Moves = %d.\n", game->player->moves);
}

void	ft_down(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x;
	y = game->player->y * game->map->width;
	if (!ft_check_down(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	y += game->map->width;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, LARA, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	game->player->y++;
	game->player->moves++;
	ft_printf("Moves = %d.\n", game->player->moves);
}

void	ft_right(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x;
	y = game->player->y * game->map->width;
	if (!ft_check_right(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	x++;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, LARA, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	game->player->x++;
	game->player->moves++;
	ft_printf("Moves = %d.\n", game->player->moves);
}

void	ft_left(t_game *game)
{
	int	x;
	int	y;
	int	res;

	res = 64;
	x = game->player->x;
	y = game->player->y * game->map->width;
	if (!ft_check_left(game))
		return ;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, FLOOR, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	x--;
	mlx_destroy_image(game->mlx, game->img[x + y].img);
	game->img[x + y].img = mlx_xpm_file_to_image(game->mlx, LARA, &res, &res);
	mlx_put_image_to_window(game->mlx, game->win, game->img[x + y].img,
		x * res, y / game->map->width * res);
	game->player->x--;
	game->player->moves++;
	ft_printf("Moves = %d.\n", game->player->moves);
}
