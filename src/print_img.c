/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:01:49 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/21 15:39:02 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static void	print_wall(t_data *data, t_img *img, t_ray *ray, int side)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		if (i < ray->wall_top)
			set_pixel(img, ray->x, i, data->sky);
		else if (i > ray->wall_bottom)
			set_pixel(img, ray->x, i, data->floor);
		else
		{
			if (side == 0 && ray->cos_angle < 0)
				set_pixel(img, ray->x, i, 0x0000FF);
			else if (side == 0)
				set_pixel(img, ray->x, i, 0x00FFFF);
			else if (ray->sin_angle < 0)
				set_pixel(img, ray->x, i, 0x00FF00);
			else
				set_pixel(img, ray->x, i, 0xFF0000);
		}
		i++;
	}
}

static void	draw_wall(t_data *data, t_img *img, t_ray *ray, int side)
{
	float	wall_dis;
	int		wall_height;

	if (side == 0)
		wall_dis = (ray->map_x - data->pos[0] + (1 - ray->step_x) / 2.0f)
			/ ray->cos_angle;
	else
		wall_dis = (ray->map_y - data->pos[1] + (1 - ray->step_y) / 2.0f)
			/ ray->sin_angle;
	if (wall_dis <= 0)
		wall_dis = 1.0f;
	wall_height = (int)(img->height / wall_dis);
	ray->wall_top = (img->height / 2) - (wall_height / 2);
	if (ray->wall_top < 0)
		ray->wall_top = 0;
	ray->wall_bottom = (img->height / 2) + (wall_height / 2);
	if (ray->wall_bottom >= img->height)
		ray->wall_bottom = img->height - 1;
	print_wall(data, img, ray, side);
}

static void	dda(t_data *data, t_img *img, t_ray *ray, int screen_x)
{
	int	side;

	while (data->map[ray->map_y] && data->map[ray->map_y][ray->map_x]
			&& data->map[ray->map_y][ray->map_x] == '0')
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
	}
	draw_wall(data, img, ray, side);
}

static void	def_step(float x, float y, t_ray *ray)
{
	if (ray->cos_angle < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (x - (int)x) * ray->dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)x + 1 - x) * ray->dist_x;
	}
	if (ray->sin_angle < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (y - (int)y) * ray->dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)y + 1 - y) * ray->dist_y;
	}
}

//define ray direction
void	draw_recast(t_data *data, t_img *img)
{
	int			i;
	t_ray		ray;
	const float	fov = 1.05f;
	const float	step = fov / img->width;

	i = 0;
	ray.angle = data->r - (fov / 2) - step;
	while (i < img->width)
	{
		ray.x = i;
		ray.map_x = (int)(data->pos[0]);
		ray.map_y = (int)(data->pos[1]);
		ray.angle += step;
		ray.cos_angle = cosf(ray.angle);
		ray.sin_angle = sinf(ray.angle);
		ray.dist_x = fabsf(1 / ray.cos_angle);
		ray.dist_y = fabsf(1 / ray.sin_angle);
		def_step(data->pos[0], data->pos[1], &ray);
		dda(data, img, &ray, i);
		i ++;
	}
}
