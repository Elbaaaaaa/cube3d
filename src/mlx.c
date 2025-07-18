/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:05:18 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/18 15:54:01 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr
		+ (y * img->line_l)
		+ (x * (img->pixel_bits / 8))));
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr
			+ (y * img->line_l)
			+ (x * (img->pixel_bits / 8)))
		= color;
}

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
	mlx->img->img = mlx_new_image(mlx->mlx, size, size);
	if (mlx->img->img == NULL)
		return (0);
	mlx->img->width = size;
	mlx->img->height = size;
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->pixel_bits,
			&mlx->img->line_l, &mlx->img->endian);
	print_img(mlx);
	return (1);
}

int	init_mlx(t_mlx *mlx)
{
	mlx->data->size = 10;
	mlx->win = mlx_new_window(mlx->mlx, 800, 800, "Cube3D");
	if (mlx->win == NULL)
		return (0);
	if (make_img() == 0)
		return (0);
	return (1);
}
