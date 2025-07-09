/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:20:45 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 19:33:01 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (NULL);
		data->n_tex = NULL;
		data->s_tex = NULL;
		data->e_tex = NULL;
		data->w_tex = NULL;
		data->map = NULL;
	}
	return (data);
}

void	free_data(void)
{
	t_data	*data;

	data = get_data();
	if (data)
	{
		if (data->n_tex)
			free(data->n_tex);
		if (data->s_tex)
			free(data->s_tex);
		if (data->e_tex)
			free(data->e_tex);
		if (data->w_tex)
			free(data->w_tex);
		if (data->map)
			free_map(data->map);
		free(data);
		data = NULL;
	}
}

t_mlx	*get_mlx(void)
{
	static t_mlx	*mlx = NULL;

	if (!mlx)
	{
		mlx = malloc(sizeof(t_mlx));
		if (!mlx)
			return (NULL);
		mlx->mlx = NULL;
		mlx->win = NULL;
		mlx->img = NULL;
		mlx->data = get_data();
		if (mlx->data == NULL)
		{
			free(mlx);
			return (NULL);
		}
	}
	return (mlx);
}

void	free_mlx(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	if (mlx)
	{
		if (mlx->img)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		if (mlx->mlx)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
		if (mlx->data)
			free_data();
		free(mlx);
		mlx = NULL;
	}
}
