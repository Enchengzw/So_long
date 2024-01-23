/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:40:46 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/23 15:07:35by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

int	ft_is_valid(int x, int y, t_data *mlx)
{
	if ((mlx->map->array[y][x]) != '1')
	{
		if ((mlx->map)->array[y][x] == 'E' && (mlx->map)->coin_count == 0)
			return (mlx_terminate(mlx->mlx_ptr), 0);
		else if ((mlx->map)->array[y][x] == 'E')
			return (0);
		else if (mlx->map->array[y][x] == 'C')
		{
			mlx->map->coin_count -= 1;
			return (1);
		}
		else
			return (1);
	}
	else
		return (0);
}

int	ft_make_movement(t_data *mlx, int x, int y)
{
	int	old_x;
	int	old_y;

	old_x = (mlx->map)->player_coord.x;
	old_y = (mlx->map)->player_coord.y;
	if (mlx_image_to_window(mlx->mlx_ptr, mlx->image_p, x * 64, y * 64) < 0)
		return (mlx_terminate(mlx->mlx_ptr), 0);
	if (mlx_image_to_window(mlx->mlx_ptr, mlx->image_0,
			(mlx->map)->player_coord.x * 64, (mlx->map)->player_coord.y
			* 64) < 0)
		return (mlx_terminate(mlx->mlx_ptr), 0);
	(mlx->map)->player_coord.x = x;
	(mlx->map)->player_coord.y = y;
	return (1);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	int		x;
	int		y;
	t_data	*mlx;

	mlx = param;
	x = (mlx->map)->player_coord.x;
	y = (mlx->map)->player_coord.y;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS
		&& ft_is_valid(x, y + 1, mlx))
		ft_make_movement(mlx, x, y + 1);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS
		&& ft_is_valid(x, y - 1, mlx))
		ft_make_movement(mlx, x, y - 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS
		&& ft_is_valid(x - 1, y, mlx))
		ft_make_movement(mlx, x - 1, y);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS
		&& ft_is_valid(x + 1, y, mlx))
		ft_make_movement(mlx, x + 1, y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_terminate(mlx->mlx_ptr);
}
