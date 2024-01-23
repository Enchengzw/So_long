/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:23 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/23 17:18:01 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <So_long.h>

void	ft_initialize_struct(t_data *mlx)
{
	mlx->map = (t_map *)malloc(sizeof(t_map));
	(mlx->map)->height = 0;
	(mlx->map)->width = 0;
	(mlx->map)->player_coord.x = 0;
	(mlx->map)->player_coord.y = 0;
	(mlx->map)->player_count = 0;
	(mlx->map)->exit_count = 0;
	(mlx->map)->coin_count = 0;
	(mlx->map)->array = 0;
}

int	ft_load_map(t_data *mlx)
{
	mlx->mlx_ptr = mlx_init((mlx->map)->width * 64, (mlx->map)->height * 64,
			"So_Long", false);
	if (!(mlx->mlx_ptr))
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 0);
	mlx->win_ptr = mlx_new_image(mlx->mlx_ptr, (mlx->map)->width * 64,
			(mlx->map)->height * 64);
	if (!(mlx->win_ptr) || (mlx_image_to_window(mlx->mlx_ptr, mlx->win_ptr, 0,
				0) < 0))
		return (0);
	return (1);
}

void	ft_free_textures(t_data *mlx)
{
	mlx_delete_texture(mlx->textures_p);
	mlx_delete_texture(mlx->textures_c);
	mlx_delete_texture(mlx->textures_e);
	mlx_delete_texture(mlx->textures_1);
	mlx_delete_texture(mlx->textures_0);
}

int	main(int argc, char **argv)
{
	t_data	*mlx;

	mlx = (t_data *)malloc(sizeof(t_data));
	ft_initialize_struct(mlx);
	if (!ft_error_check(argv[1], mlx->map))
		return (0);
	if (!ft_load_map(mlx))
		return (0);
	if (!ft_load_images(mlx))
		return (0);
	if (!ft_paint_map(mlx))
		return (0);
	mlx_key_hook(mlx->mlx_ptr, ft_key_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	write(2, "Hola\n", 5);
	//ft_free_textures(mlx);
	return (0);
}
