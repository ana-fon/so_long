/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:33:10 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/08 00:33:10 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <../X11/keysym.h>
# include <stdlib.h>
# include <../X11/X.h>
# include <fcntl.h>
# include <stdbool.h>

# define EXTENSION ".ber"
# define WALL "textures/wall.xpm"
# define LARA "textures/lara.xpm"
# define FLOOR "textures/floor.xpm"
# define COLLECTABLE "textures/collectable.xpm"
# define EXIT "textures/exit.xpm"
# define SIZE 64

/*STRUCTS*/

typedef struct s_map
{
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		is_collectable;
	int		is_exit;
	int		is_player;
	int		is_floor;
	char	**design;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_data		*img; // array de imagens
	int			pos; //posição atual/contador de tiles carregados
}	t_game;

/*MOVEMENTS*/

int		ft_check_up(t_game *game);
int		ft_check_down(t_game *game);
int		ft_check_right(t_game *game);
int		ft_check_left(t_game *game);

void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_right(t_game *game);
void	ft_left(t_game *game);

/*MAP*/
void	ft_put_value(t_map *map);
int		ft_init_map(t_map *map, char *file);
int		ft_mapsize(t_map *map, char *file);
int		ft_line_len(char *str);
bool	ft_fill_map(t_map *map, char *file);

int		ft_check_map(t_map *map, char *file);
int		ft_check_map_name(char *file);
int		ft_check_map_components(t_map	*map);
int		ft_check_walls(t_map *map);
int		ft_check_map_goals(t_map *map);
void	ft_free_design(t_map *map);

/*PLAYER*/
int		ft_init_player(t_player *player);
int		ft_check_path(t_map *map, char *file);
int		is_goal(char c);
void	ft_get_p(t_map *map);
void	ft_find_path(t_map *map, int x, int y);

/*GAME*/
void	start_game(t_map *map, t_player *player, t_game game);
void	ft_finish(t_game *game);
void	ft_cancel(t_map *map, t_game *game, char *s);
void	is_movement(int keysym, t_game *game);
char	*ft_select_image(int x, int y, t_map *map);
int		ft_put_img_to_window(t_game *game, int x, int y, t_map *map);
int		ft_render_map(t_game *game);
int		ft_quit(t_game *game);
int		handle_input(int keysym, t_game *game);

/*FREE*/
void	ft_free(t_game *game);
void	ft_free_img(t_game	*game);
void	ft_free_design(t_map *map);
int		ft_check_lines(int fd, t_map *map);

#endif