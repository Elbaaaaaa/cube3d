/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:09:30 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/15 12:43:24 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	error_message(char *str, int i)
{
	ft_get_next_line(-2);
	free_mlx();
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (i == 1)
		ft_putstr_fd("Use: ./cube3d <./path/to/file.cub>\n", 2);
	else if (i == 2)
		ft_putstr_fd("Define only NO, SO, WE, EA, F, C"
			" with valid path & color\n", 2);
	else if (i == 3)
		ft_putstr_fd("Define close map only with 1, 0 & single spawn\n", 2);
	exit (1);
}
