/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:09:30 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 18:58:20 by adoireau         ###   ########.fr       */
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
	exit (1);
}
