/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:39:41 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/10 17:54:24 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	new_img(t_mlx *mlx)
{
	printf("new_img\n");
	if (mlx && mlx->mlx && mlx->img && mlx->img->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	if (make_img() == 0)
		close_win();
}

static void	mv_cara(int keycode, t_mlx *mlx)
{
	if (keycode == 119)
		display_texture(1);
	else if (keycode == 115)
		display_texture(2);
	else if (keycode == 97)
		display_texture(3);
	else if (keycode == 100)
		display_texture(4);
}

static void	mv_cam(int keycode, t_mlx *mlx)
{
	if (keycode == 65361)
		printf("<- : ");
	else if (keycode == 65363)
		printf("-> : ");
	new_img(mlx);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (mlx->img->img == NULL)
		return (0);
	else if (keycode == 65307)
		close_win();
	else if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
		mv_cara(keycode, mlx);
	else if (keycode == 65361 || keycode == 65363)
		mv_cam(keycode, mlx);
	return (1);
}
