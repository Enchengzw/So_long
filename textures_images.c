/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:50:28 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/25 13:26:16 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

int	ft_texture_to_images(t_data *mlx)
{
	mlx->image_p = mlx_texture_to_image(mlx->mlx_ptr, mlx->t_p);
	if (!(mlx->image_p))
		return (0);
	mlx->image_c = mlx_texture_to_image(mlx->mlx_ptr, mlx->t_c);
	if (!(mlx->image_c))
		return (0);
	mlx->image_e = mlx_texture_to_image(mlx->mlx_ptr, mlx->t_e);
	if (!(mlx->image_e))
		return (0);
	mlx->image_1 = mlx_texture_to_image(mlx->mlx_ptr, mlx->t_1);
	if (!(mlx->image_1))
		return (0);
	mlx->image_0 = mlx_texture_to_image(mlx->mlx_ptr, mlx->t_0);
	if (!(mlx->image_0))
		return (0);
	return (1);
}

int	ft_load_images(t_data *mlx)
{
	mlx->t_p = mlx_load_png("/Users/ezhou/github/So_long/images/player.png");
	if (!mlx->t_p)
		return (ft_printf("Error\n"), 0);
	mlx->t_c = mlx_load_png("/Users/ezhou/github/So_long/images/Coin.png");
	if (!mlx->t_c)
		return (ft_printf("Error\n"), 0);
	mlx->t_e = mlx_load_png("/Users/ezhou/github/So_long/images/exit.png");
	if (!mlx->t_e)
		return (ft_printf("Error\n"), 0);
	mlx->t_1 = mlx_load_png("/Users/ezhou/github/So_long/images/Wall.png");
	if (!mlx->t_1)
		return (ft_printf("Error\n"), 0);
	mlx->t_0 = mlx_load_png("/Users/ezhou/github/So_long/images/empty.png");
	if (!mlx->t_0)
		return (ft_printf("Error\n"), 0);
	if (!ft_texture_to_images(mlx))
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	ft_paint_one(char position, int width, int height, t_data *mlx)
{
	void	*image;

	if (position == 'P')
		image = mlx->image_p;
	else if (position == 'E')
		image = mlx->image_e;
	else if (position == 'C')
		image = mlx->image_c;
	else if (position == '1')
		image = mlx->image_1;
	else if (position == '0')
		image = mlx->image_0;
	if (mlx_image_to_window(mlx->mlx_ptr, image, width * 64, height * 64) < 0)
		return (0);
	return (1);
}

int	ft_paint_map(t_data *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (j < (mlx->map->height))
	{
		i = 0;
		while (i < (mlx->map)->width)
		{
			if (!ft_paint_one(((mlx->map)->array)[j][i], i, j, mlx))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
