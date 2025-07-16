/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:42:54 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/15 13:51:13 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

static t_img	*get_target_texture(char *tmp, t_data *data)
{
	t_img	*target;

	target = NULL;
	if (!ft_strncmp(tmp, "NO", 2) && !data->tex[0]->img)
		target = data->tex[0];
	else if (!ft_strncmp(tmp, "SO", 2) && !data->tex[1]->img)
		target = data->tex[1];
	else if (!ft_strncmp(tmp, "WE", 2) && !data->tex[2]->img)
		target = data->tex[2];
	else if (!ft_strncmp(tmp, "EA", 2) && !data->tex[3]->img)
		target = data->tex[3];
	return (target);
}

int	pars_img(char *tmp, t_data *data)
{
	char	*str;
	t_img	*target;

	target = get_target_texture(tmp, data);
	if (!target)
		return (0);
	str = ft_strtrim(tmp + 2, " \t");
	if (!str)
		return (0);
	target->img = mlx_xpm_file_to_image(get_mlx()->mlx, str,
			&target->width, &target->height);
	free(str);
	if (!target->img)
		return (0);
	target->addr = mlx_get_data_addr(target->img, &target->pixel_bits,
			&target->line_l, &target->endian);
	if (!target->addr)
		return (0);
	return (1);
}
