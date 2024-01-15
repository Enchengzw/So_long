/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:05:40 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/15 17:31:15y ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

void	fill(char **tab, t_point cur, int *coins, int *exit)
{
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'P')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		*coins += 1;
	if (tab[cur.y][cur.x] == 'E')
		*exit = 1;
	ft_printf("X:%d, Y:%d char:%c\n", cur.x, cur.y, tab[cur.y][cur.x]);
	tab[cur.y][cur.x] = 'P';
	fill(tab, (t_point){cur.x - 1, cur.y}, coins, exit);
	fill(tab, (t_point){cur.x + 1, cur.y}, coins, exit);
	fill(tab, (t_point){cur.x, cur.y - 1}, coins, exit);
	fill(tab, (t_point){cur.x, cur.y + 1}, coins, exit);
}

void	flood_fill(t_map *map, int *coins, int *exit)
{
	t_point	start;

	start.x = map->player_coord.x;
	start.y = map->player_coord.y;
	fill(map->array, (t_point){start.x - 1, start.y}, exit, coins);
	fill(map->array, (t_point){start.x + 1, start.y}, exit, coins);
	fill(map->array, (t_point){start.x, start.y - 1}, exit, coins);
	fill(map->array, (t_point){start.x, start.y + 1}, exit, coins);
}

int	ft_is_map_solvable(t_map *map)
{
	int	coins;
	int	exit;

	coins = 0;
	exit = 0;
	flood_fill(map, &exit, &coins);
	if (coins != map->coin_count)
		return (0);
	else if (!exit)
		return (0);
	return (1);
}

int	ft_check_borders(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (i == 0 && (map->array)[j][i] != '1')
				return (0);
			else if (j == 0 && (map->array)[j][i] != '1')
				return (0);
			else if (i == (map->width - 1) && (map->array)[j][i] != '1')
				return (0);
			else if (j == (map->height - 1) && (map->array)[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_is_map_valid(t_map *map)
{
	if (map->player_count > 1)
		return (ft_printf("Error\nMore than one initial position"), 0);
	if (map->exit_count > 1)
		return (ft_printf("Error\nMore than one exit"), 0);
	if (!ft_check_borders(map))
		return (ft_printf("Error\nInvalid borders"), 0);
	if (!ft_is_map_solvable(map))
		return (ft_printf("Error\nExit or coins not accessible"), 0);
	return (1);
}
