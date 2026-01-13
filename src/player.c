/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 02:30:43 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/11 05:12:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_player(t_player *player)
{
	if (!player)
		return (0);
	player->x = 0;
	player->y = 0;
	player->moves = 0;
	return (1);
}
