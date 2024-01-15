/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:23:41 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/15 16:57:48 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	t_point	player_coord;
	char	**array;
	int		height;
	int		width;
	int		coin_count;
	int		player_count;
	int		exit_count;
}			t_map;

int			ft_check_dimensions(char *file, t_map *map, int fd);
void		fill(char **tab, t_point cur, int *coins, int *exit);
void		flood_fill(t_map *map, int *coins, int *exit);
void		ft_generate(int fd, t_map *map);
int			ft_error_check(char *file, t_map *map);
int			ft_is_map_valid(t_map *map);
int			ft_check_borders(t_map *map);

#endif