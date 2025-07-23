/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:00:31 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/23 22:12:54 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d_bonus.h"

int	set_weapon(void)
{
	t_mlx	*mlx;
	static char *str[2] = {"./bonus/gun.xpm", "./bonus/gunf.xpm"};
	int		i;

	mlx = get_mlx();
	mlx->weapon[0] = get_img();
	mlx->weapon[1] = get_img();
	if (!mlx->weapon[0] || !mlx->weapon[1])
		error_message("weapon memory not allow", 0);
	i = 0;
	while (i < 2)
	{
		printf("%s\n", str[i]);
		mlx->weapon[i]->img = mlx_xpm_file_to_image(mlx->mlx, str[i], &mlx->weapon[i]->width, &mlx->weapon[i]->height);
		if (!mlx->weapon[i]->img)
			error_message("weapon file", 0);
		mlx->weapon[i]->addr = mlx_get_data_addr(mlx->weapon[i]->img, &mlx->weapon[i]->pixel_bits, &mlx->weapon[i]->line_l, &mlx->weapon[i]->endian);
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

void	draw_weapon(t_mlx *mlx)
{
	int x;
	int y;
	int color;
	int w;
	int h;

	y = 0;
	h = 0;
	while (y < mlx->weapon[0]->height && y + h < mlx->img->height)
	{
		x = 0;
		h = mlx->img->height - (mlx->weapon[0]->height * 4 / 5);
		while (x < mlx->weapon[0]->width)
		{
			color = 0xFFFFFF;
			color = get_pixel(mlx->weapon[0], x, y);
			if (color != 0xFFFFFF)
			{
				set_pixel(mlx->img, x + (mlx->img->width / 2) - (mlx->weapon[0]->width / 2), y + h, color);
			}
			x++;
		}
		y++;
	}

}
