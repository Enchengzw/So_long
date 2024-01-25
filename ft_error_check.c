/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:09 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/25 18:01:08 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

int	ft_check_dimensions(char *file, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nEmpty file\n"), 0);
	map->width = ft_strlen(line) - 1;
	while (line)
	{
		if (ft_strcontains(line, '\n') && (ft_strlen(line) - 1) != map->width)
			return (free(line), ft_printf("Error\nIrregular dimensions\n"), 0);
		else if (!ft_strcontains (line, '\n') && ft_strlen(line) != map->width)
			return (free(line), ft_printf("Error\nIrregular dimensions\n"), 0);
		free(line);
		line = get_next_line(fd);
		(map->height)++;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nNo se puede abrir el archivo\n"), 0);
	return (1);
}

void	ft_generate(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	map->array = (char **)malloc(sizeof(char *) * (map->height + 1));
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		(map->array)[i] = line;
		i++;
	}
	map->array[i] = 0;
}

int	ft_valid_border(int x, int y, t_map *map)
{
	if (x == 0)
		return (1);
	else if (y == 0)
		return (1);
	else if (x == map->width && y == map->height)
		return (1);
	else
		return (0);
}

int	ft_count_items(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (++i < map->width)
		{
			if (!ft_strcontains ("10CEP", map->array[j][i]))
				return (0);
			if ((map->array)[j][i] == 'C')
				(map->coin_count)++;
			else if ((map->array)[j][i] == 'P')
			{
				(map->player_coord).x = i;
				(map->player_coord).y = j;
				(map->player_count)++;
			}
			else if ((map->array)[j][i] == 'E')
				(map->exit_count)++;
		}
		j++;
	}
	return (1);
}

int	ft_error_check(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n No se puede abrir el archivo\n"), 0);
	if (!ft_check_dimensions(file, map, fd))
		return (0);
	ft_generate(fd, map);
	if (!ft_count_items(map))
		return (ft_printf("Error\nCharacters not allowed in map"), 0);
	if (!ft_is_map_valid(map))
		return (0);
	return (1);
}
