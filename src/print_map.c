/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:05:12 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/18 16:59:17 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static void	draw_cube(t_img *img, int x, int y, int color)
{
	t_data	*data;
	int		w;
	int		h;

	data = get_data();
	x *= data->size;
	y *= data->size;
	w = 0;
	while (y + w < img->height && w < data->size)
	{
		h = 0;
		while (h + x < img->width && h < data->size)
		{
			set_pixel(img, x + h, y + w, color);
			h++;
		}
		w++;
	}
}

void	draw_map(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (data->map[y] && (y * data->size) <= img->height)
	{
		x = 0;
		while (data->map[y][x] && (x * data->size) <= img->width)
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0')
			{
				if (data->map[y][x] == '1')
					color = 0x505050;
				else if (data->map[y][x] == '0')
					color = data->floor;
				draw_cube(img, x, y, color);
			}
			x++;
		}
		y++;
	}
}
