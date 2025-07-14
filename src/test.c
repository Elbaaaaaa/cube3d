/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:20:45 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/10 17:29:29 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	display_texture(int texture_num)
{
	t_mlx	*mlx;
	t_img	*texture;

	mlx = get_mlx();
	if (texture_num < 1 || texture_num > 4)
		return ;
	texture = mlx->data->tex[texture_num - 1];
	if (!texture || !texture->img)
		return ;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, texture->img, 0, 0);
}
