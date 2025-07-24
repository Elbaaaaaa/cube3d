/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:39:41 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/24 19:59:51 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d_bonus.h"

int	get_key_index(int keycode)
{
	if (keycode == 119)
		return (0);
	else if (keycode == 97)
		return (1);
	else if (keycode == 115)
		return (2);
	else if (keycode == 100)
		return (3);
	else if (keycode == 65361)
		return (4);
	else if (keycode == 65363)
		return (5);
	return (-1);
}

static void	check_mv(float x, float y, t_data *data)
{
	if (data->map[(int) data->pos[1]][(int) x] == '0')
		data->pos[0] = x;
	if (data->map[(int) y][(int) data->pos[0]] == '0')
		data->pos[1] = y;
}

void	mv_cara(t_data *data)
{
	float	x;
	float	y;
	t_mlx	*mlx;

	mlx = get_mlx();
	if (!mlx)
		return ;
	if (mlx->keys[0])
	{
		x = data->pos[0] + cos(data->r) * 0.02;
		y = data->pos[1] + sin(data->r) * 0.02;
	}
	if (mlx->keys[2])
	{
		x = data->pos[0] - cos(data->r) * 0.02;
		y = data->pos[1] - sin(data->r) * 0.02;
	}
	if (mlx->keys[1])
	{
		x = data->pos[0] + sin(data->r) * 0.02;
		y = data->pos[1] - cos(data->r) * 0.02;
	}
	if (mlx->keys[3])
	{
		x = data->pos[0] - sin(data->r) * 0.02;
		y = data->pos[1] + cos(data->r) * 0.02;
	}
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

void	trigger_fire(t_mlx *mlx)
{
	if (mlx->fire_animation <= 0)
	{
		mlx->fire = 1;
		mlx->fire_animation = 20;
		mlx->mv_weapon[0] = 10;
		mlx->mv_weapon[1] = 0;
	}
}
