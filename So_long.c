/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:23 by ezhou             #+#    #+#             */
/*   Updated: 2024/01/25 13:25:55 by ezhou            ###   ########.fr       */
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
	(mlx->map)->movement_counter = 0;
	mlx->t_0 = NULL;
	mlx->t_1 = NULL;
	mlx->t_c = NULL;
	mlx->t_e = NULL;
	mlx->t_p = NULL;
}

int	ft_load_map(t_data *mlx)
{
	mlx->mlx_ptr = mlx_init((mlx->map)->width * 64, (mlx->map)->height * 64,
			"So_Long", false);
	if (!(mlx->mlx_ptr))
		return (ft_putstr_fd(mlx_strerror(mlx_errno), 1), 0);
	mlx->win_ptr = mlx_new_image(mlx->mlx_ptr, (mlx->map)->width * 64,
			(mlx->map)->height * 64);
	if (!(mlx->win_ptr) || (mlx_image_to_window(mlx->mlx_ptr, mlx->win_ptr, 0,
				0) < 0))
		return (0);
	return (1);
}

void	ft_free_textures(t_data *mlx)
{
	if (mlx->t_p)
		mlx_delete_texture(mlx->t_p);
	if (mlx->t_c)
		mlx_delete_texture(mlx->t_c);
	if (mlx->t_e)
		mlx_delete_texture(mlx->t_e);
	if (mlx->t_1)
		mlx_delete_texture(mlx->t_1);
	if (mlx->t_0)
		mlx_delete_texture(mlx->t_0);
}

void	ft_free_all(t_data *mlx)
{
	ft_free_char(mlx->map->array);
	free(mlx->map);
	free(mlx);
}

void	leaks(void)
{
	system("leaks So_long");
}

int	main(int argc, char **argv)
{
	t_data	*mlx;
	int a;
	int	b;
	int	c;

	atexit(leaks);
	mlx = (t_data *)malloc(sizeof(t_data));
	ft_initialize_struct(mlx);
	if (!ft_error_check(argv[1], mlx->map))
		return (ft_free_all(mlx), 0);
	if (!ft_load_map(mlx) || !ft_load_images(mlx) || !ft_paint_map(mlx))
		return (mlx_close_window(mlx->mlx_ptr), ft_free_textures(mlx),
			mlx_terminate(mlx->mlx_ptr), ft_free_all(mlx), 0);
	mlx_key_hook(mlx->mlx_ptr, ft_key_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	ft_free_textures(mlx);
	mlx_terminate(mlx->mlx_ptr);
	ft_free_all(mlx);
	return (0);
}
