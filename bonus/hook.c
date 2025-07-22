/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:39:41 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/22 16:33:37 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d_bonus.h"

static void	check_mv(float x, float y, t_data *data)
{
	if (data->map[(int) data->pos[1]][(int) x] == '0')
		data->pos[0] = x;
	if (data->map[(int) y][(int) data->pos[0]] == '0')
		data->pos[1] = y;
}

static void	mv_cara(int keycode, t_data *data)
{
	float	x;
	float	y;

	if (keycode == 119)
	{
		x = data->pos[0] + cos(data->r) * 0.1;
		y = data->pos[1] + sin(data->r) * 0.1;
	}
	else if (keycode == 115)
	{
		x = data->pos[0] - cos(data->r) * 0.1;
		y = data->pos[1] - sin(data->r) * 0.1;
	}
	else if (keycode == 97)
	{
		x = data->pos[0] + sin(data->r) * 0.1;
		y = data->pos[1] - cos(data->r) * 0.1;
	}
	else if (keycode == 100)
	{
		x = data->pos[0] - sin(data->r) * 0.1;
		y = data->pos[1] + cos(data->r) * 0.1;
	}
	check_mv(x, y, data);
	make_img();
}

static void	mv_cam(int keycode, t_data *data)
{
	const float	pi = 3.14159265358979323846;

	if (keycode == 65361)
	{
		data->r -= 0.1;
		if (data->r < 0)
			data->r = data->r + (2 * pi);
	}
	else if (keycode == 65363)
	{
		data->r += 0.1;
		if (data->r > (2 * pi))
			data->r = data->r - (2 * pi);
	}
	make_img();
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (mlx->img->img == NULL)
		return (0);
	else if (keycode == 65307)
		close_win();
	else if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
		mv_cara(keycode, mlx->data);
	else if (keycode == 65361 || keycode == 65363)
		mv_cam(keycode, mlx->data);
	return (1);
}
