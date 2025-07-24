/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:00:31 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/24 16:55:14 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d_bonus.h"

int	set_weapon(void)
{
	t_mlx		*mlx;
	static char	*str[2] = {"./bonus/gun2.xpm", "./bonus/gunf2.xpm"};
	int			i;

	mlx = get_mlx();
	mlx->weapon[0] = get_img();
	mlx->weapon[1] = get_img();
	if (!mlx->weapon[0] || !mlx->weapon[1])
		error_message("weapon memory not allow", 0);
	i = 0;
	while (i < 2)
	{
		mlx->weapon[i]->img = mlx_xpm_file_to_image(mlx->mlx, str[i],
				&mlx->weapon[i]->width, &mlx->weapon[i]->height);
		if (!mlx->weapon[i]->img)
			error_message("weapon file", 0);
		mlx->weapon[i]->addr = mlx_get_data_addr(mlx->weapon[i]->img,
				&mlx->weapon[i]->pixel_bits, &mlx->weapon[i]->line_l,
				&mlx->weapon[i]->endian);
		if (!mlx->weapon[i]->addr)
			error_message("weapon data", 0);
		i++;
	}
	return (1);
}

void	free_weapon(void)
{
	t_mlx	*mlx;
	int		i;

	mlx = get_mlx();
	i = 0;
	while (i < 2)
	{
		if (mlx->weapon[i])
		{
			if (mlx->weapon[i]->img && mlx->mlx)
				mlx_destroy_image(mlx->mlx, mlx->weapon[i]->img);
			free(mlx->weapon[i]);
		}
		i++;
	}
}

void	draw_weapon(t_img *img, t_img *weapon)
{
	int			x;
	int			y;
	int			color;
	const int	w = (img->width / 2) - (weapon->width / 2) - get_mlx()->mv_weapon[1];
	const int	h = img->height - (weapon->height * 0.8) - get_mlx()->mv_weapon[0];

	y = 0;
	while (y < weapon->height && y + h < img->height)
	{
		x = 0;
		while (x < weapon->width)
		{
			color = get_pixel(weapon, x, y);
			if (color != 0xFFFFFF)
				set_pixel(img, x + w, y + h, color);
			x++;
		}
		y++;
	}
}
