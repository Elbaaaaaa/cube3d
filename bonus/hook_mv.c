/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:03:57 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/25 23:40:26 by adoireau         ###   ########.fr       */
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

void	mv_calc(float *x, float *y, float r, float speed)
{
	*x += cos(r) * speed;
	*y += sin(r) * speed;
}

void	mv_cara(t_data *data)
{
	const float	pi = 3.14159265358979323846;
	float		x;
	float		y;
	t_mlx		*mlx;

	mlx = get_mlx();
	if (!mlx)
		return ;
	x = data->pos[0];
	y = data->pos[1];
	if (mlx->keys[0] && !mlx->keys[2])
		mv_calc(&x, &y, data->r, 0.02);
	if (mlx->keys[2] && !mlx->keys[0])
		mv_calc(&x, &y, data->r + pi, 0.015);
	if (mlx->keys[1] && !mlx->keys[3])
		mv_calc(&x, &y, data->r - pi / 2, 0.01);
	if (mlx->keys[3] && !mlx->keys[1])
		mv_calc(&x, &y, data->r + pi / 2, 0.01);
	check_mv(x, y, data);
}

void	mv_cam(t_data *data)
{
	const float	pi = 3.14159265358979323846;
	t_mlx		*mlx;

	mlx = get_mlx();
	if (!mlx)
		return ;
	if (mlx->keys[4])
	{
		data->r -= 0.02;
		if (data->r < 0)
			data->r = data->r + (2 * pi);
	}
	if (mlx->keys[5])
	{
		data->r += 0.02;
		if (data->r > (2 * pi))
			data->r = data->r - (2 * pi);
	}
}
