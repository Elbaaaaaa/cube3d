/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:42:54 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 19:34:40 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

/*
	remplaser char* pour str et data->x_text par s_img
	tenter le load xmp pour le path
	si non valide return 0
*/
int	pars_img(char *tmp, t_data *data)
{
	char	*str;
	char	**target;

	if (!ft_strncmp(tmp, "NO", 2) && !data->n_tex)
		target = &data->n_tex;
	else if (!ft_strncmp(tmp, "SO", 2) && !data->s_tex)
		target = &data->s_tex;
	else if (!ft_strncmp(tmp, "WE", 2) && !data->w_tex)
		target = &data->w_tex;
	else if (!ft_strncmp(tmp, "EA", 2) && !data->e_tex)
		target = &data->e_tex;
	else
		return (0);
	str = ft_strtrim(tmp + 2, " \t");
	if (!str)
		return (0);
	*target = str;
	return (1);
}
