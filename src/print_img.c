/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:01:49 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/16 19:05:48 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static void	draw_cone(t_data *data, t_img *img)
{
	int		k;
	float	angle;
	float	start_angle;
	float	end_angle;
	float	ray_x;
	float	ray_y;
	int		map_x;
	int		map_y;
	int		step;
	int		max_dist;

	start_angle = data->r - 0.523599f;
	end_angle = data->r + 0.523599f;
	k = 0;
	while (k < img->width)
	{
		angle = start_angle + (end_angle - start_angle) * k / (img->width - 1);
		step = 0;
		max_dist = 20 * data->size;
		while (step < max_dist)
		{
			ray_x = data->pos[0] * data->size + cosf(angle) * step;
			ray_y = data->pos[1] * data->size + sinf(angle) * step;
			map_x = (int)(ray_x);
			map_y = (int)(ray_y);
			if (map_x < 0 || map_x >= img->width || map_y < 0 || map_y >= img->height)
				break;
			set_pixel(img, map_x, map_y, 0x0000FF);
			if (data->map[(int)(ray_y / data->size)][(int)(ray_x / data->size)] != '0')
				break;
			step++;
		}
		k++;
	}
}
void	print_img(t_mlx *mlx)
{
	draw_map(mlx->data, mlx->img);
	draw_cone(mlx->data, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
