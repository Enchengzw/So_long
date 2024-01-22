/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:50:28 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/22 18:20:40 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

int	ft_texture_to_images(t_data *mlx)
{
	mlx->image_p = mlx_texture_to_image(mlx->mlx_ptr, mlx->textures_p);
	if (!(mlx->image_p))
		return (0);
	mlx->image_c = mlx_texture_to_image(mlx->mlx_ptr, mlx->textures_c);
	if (!(mlx->image_c))
		return (0);
	mlx->image_e = mlx_texture_to_image(mlx->mlx_ptr, mlx->textures_e);
	if (!(mlx->image_e))
		return (0);
	mlx->image_1 = mlx_texture_to_image(mlx->mlx_ptr, mlx->textures_1);
	if (!(mlx->image_1))
		return (0);
	mlx->image_0 = mlx_texture_to_image(mlx->mlx_ptr, mlx->textures_0);
	if (!(mlx->image_0))
		return (0);
	return (1);
}

int	ft_load_images(t_data *mlx)
{
	mlx->textures_p = mlx_load_png("./images/player.png");
	if (!mlx->textures_p)
		return (ft_printf("Error\n", 0));
	mlx->textures_c = mlx_load_png("./images/Coin.png");
	if (!mlx->textures_c)
		return (ft_printf("Error\n", 0));
	mlx->textures_e = mlx_load_png("./images/exit.png");
	if (!mlx->textures_e)
		return (ft_printf("Error\n", 0));
	mlx->textures_1 = mlx_load_png("./images/Wall.png");
	if (!mlx->textures_1)
		return (ft_printf("Error\n", 0));
	mlx->textures_0 = mlx_load_png("./images/empty.png");
	if (!mlx->textures_0)
		return (ft_printf("Error\n", 0));
	if (!ft_texture_to_images(mlx))
		return (ft_printf("Error\n", 0));
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
	while (j < ((mlx->map)->height))
	{
		i = 0;
		while (i < (mlx->map)->width)
		{
			if (!ft_paint_one(((mlx->map)->array)[j][i], j, i, mlx))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
