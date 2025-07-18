/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:01:49 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/18 19:26:41 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static void	print_wall(t_data *data, t_img *img, int wall_top, int wall_bottom, int x, int side)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		if (i < wall_top)
			set_pixel(img, x, i, data->sky);
		else if (i > wall_bottom)
			set_pixel(img, x, i, data->floor);
		else
		{
			if (side == 0)
				set_pixel(img, x, i, 0x0000FF);
			else
				set_pixel(img, x, i, 0x00FF00);
		}
		i++;
	}
}
static void	draw_wall(t_data *data, t_img *img, t_ray *ray, int side, int screen_x)
{
	float	wall_dis;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;

	if (side == 0)
		wall_dis = (ray->map_x - data->pos[0] + (1 - ray->step_x) / 2.0f) / ray->cos_angle;
	else
		wall_dis = (ray->map_y - data->pos[1] + (1 - ray->step_y) / 2.0f) / ray->sin_angle;
	if (wall_dis <= 0)
		wall_dis = 1.0f;
	wall_height = (int)(img->height / wall_dis);
	wall_top = (img->height / 2) - (wall_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (img->height / 2) + (wall_height / 2);
	if (wall_bottom >= img->height)
		wall_bottom = img->height - 1;
	print_wall(data, img, wall_top, wall_bottom, screen_x, side);
}

static void	dda(t_data *data, t_img *img, t_ray *ray, int screen_x)
{
	int	side;

	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->dist_x;
			ray->map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->dist_y;
			ray->map_y += ray->step_y;
			side = 1;
		}
		if (data->map[ray->map_y] && data->map[ray->map_y][ray->map_x]
			&& data->map[ray->map_y][ray->map_x] != '0')
			break;
	}
	draw_wall(data, img, ray, side, screen_x);
}

static void	def_step(t_data *data, t_ray *ray)
{
	if (ray->cos_angle < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->pos[0] - ray->map_x) * ray->dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - data->pos[0]) * ray->dist_x;
	}
	if (ray->sin_angle < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->pos[1] - ray->map_y) * ray->dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - data->pos[1]) * ray->dist_y;
	}
}

//define ray direction
static void	draw_recast(t_data *data, t_img *img)
{
	int		i;
	const float	fov = 1;
	t_ray	ray;

	i = 0;
	ray.start_angle = data->r - fov / 2;
	while (i < img->width)
	{
		ray.map_x = (int)(data->pos[0]);
		ray.map_y = (int)(data->pos[1]);
		ray.angle = ray.start_angle + (fov * i / (img->width - 1));
		ray.cos_angle = cosf(ray.angle);
		ray.sin_angle = sinf(ray.angle);
		ray.dist_x = fabsf(1 / ray.cos_angle);
		ray.dist_y = fabsf(1 / ray.sin_angle);
		def_step(data, &ray);
		dda(data, img, &ray, i);
		//draw_ray(data, img, ray.angle);
		i ++;
	}
}

void	print_img(t_mlx *mlx)
{
	draw_recast(mlx->data, mlx->img);
	draw_map(mlx->data, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
