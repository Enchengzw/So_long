/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:23 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/11 14:37:15 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

void	ft_initialize_struct(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->player_coord.x = 0;
	map->player_coord.y = 0;
	map->coin_count = 0;
	map->array = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_initialize_struct(map);
	if (!ft_error_check(argv[1], map))
		;
	return (0);
}
