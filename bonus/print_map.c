/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:05:12 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/22 16:56:18 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d_bonus.h"

static void	draw_circle(int x, int y, int color, int size)
{
	t_img	*img;
	int	i;
	int	j;

	img = get_mlx()->img;
	i = 0;
	while (i < size / 4)
	{
		j = 0;
		while (j < size / 4)
		{
			if (i * i + j * j <= size * size / 16)
				set_pixel(img, x + i - size / 8, y + j - size / 8, color);
			j++;
		}
		i++;
	}
}

static void	draw_cube(int x, int y, int color, int size)
{
	t_img	*img;
	int		w;
	int		h;

	img = get_mlx()->img;
	x *= size;
	y *= size;
	w = 0;
	while (y + w < img->height && w < size)
	{
		h = 0;
		while (h + x < img->width && h < size)
		{
			set_pixel(img, x + h, y + w, color);
			h++;
		}
		w++;
	}
}

static int	define_size(t_data *data, t_img *img)
{
	static int	size = 0;
	int len;
	int i;

	if (size == 0)
	{
		i = 0;
		while (data->map[i])
		{
			len = ft_strlen(data->map[i]);
			if (len > size)
				size = len;
			i++;
		}
		if (i > size)
			size = img->height / i / 3;
		else
			size = img->width / len / 3;
	}
	return (size);
}

void	draw_map(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	color;
	int	size = define_size(data, img);

	y = 0;
	while (data->map[y] && (y * size) <= img->height)
	{
		x = 0;
		while (data->map[y][x] && (x * size) <= img->width)
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0')
			{
				if (data->map[y][x] == '1')
					color = 0x505050;
				else if (data->map[y][x] == '0')
					color = data->floor;
				draw_cube(x, y, color, size);
			}
			x++;
		}
		y++;
	}
	draw_circle(data->pos[0] * size, data->pos[1] * size, 0x00FF00, size);
}
