/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:39:41 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 19:31:28 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	new_img(t_mlx *mlx)
{
	printf("new_img\n");
	mlx_destroy_image(mlx->mlx, mlx->img);
	if (make_img() == 0)
		close_win();
}

static void	mv_cara(int keycode, t_mlx *mlx)
{
	if (keycode == 119)
		printf("w : ");
	else if (keycode == 115)
		printf("s : ");
	else if (keycode == 97)
		printf("a : ");
	else if (keycode == 100)
		printf("d : ");
	new_img(mlx);
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
	if (mlx->img == NULL)
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
