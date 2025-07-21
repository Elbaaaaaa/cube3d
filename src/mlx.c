/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:05:18 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/21 15:09:25 by adoireau         ###   ########.fr       */
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

void	make_img(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	draw_recast(mlx->data, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

int	init_mlx(t_mlx *mlx)
{
	const int	size = 800;

	mlx->win = mlx_new_window(mlx->mlx, size, size, "Cube3D");
	if (mlx->win == NULL)
		return (0);
	mlx->img->img = mlx_new_image(mlx->mlx, size, size);
	if (mlx->img->img == NULL)
		return (0);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->pixel_bits,
			&mlx->img->line_l, &mlx->img->endian);
	if (mlx->img->addr == NULL)
		return (0);
	mlx->img->width = size;
	mlx->img->height = size;
	make_img();
	return (1);
}
