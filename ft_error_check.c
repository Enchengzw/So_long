/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:17:09 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/24 17:18:32 by ezhou            ###   ########.fr       */
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

void	ft_count_items(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 1;
		while (i < map->width)
		{
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
			i++;
		}
		j++;
	}
}

int	ft_error_check(char *file, t_map *map)
{
	int	fd;
	int	flag;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n No se puede abrir el archivo\n"), 0);
	flag = ft_check_dimensions(file, map, fd);
	if (!flag)
		return (0);
	ft_generate(fd, map);
	ft_count_items(map);
	flag = ft_is_map_valid(map);
	if (!flag)
		return (0);
	return (1);
}
