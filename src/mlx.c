/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:05:18 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 17:15:50 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	close_win(void)
{
	free_mlx();
	exit(0);
}

int	make_img(void)
{
	const int		size = 800;
	t_mlx			*mlx;

	mlx = get_mlx();
	mlx->img = mlx_new_image(mlx->mlx, size, size);
	if (mlx->img == NULL)
		return (0);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->pixel_bits,
			&mlx->line_l, &mlx->endian);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, 800, 800, "Fractol");
	if (mlx->win == NULL)
		return (0);
	if (make_img() == 0)
		return (0);
	return (1);
}
