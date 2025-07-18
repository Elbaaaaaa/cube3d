/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:43:52 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/16 17:39:54 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// check if int is valid and between 0 & 255
static char	*pars_int(char *str, int *nbr)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (NULL);
	*nbr = ft_atoi(str + i);
	if (*nbr < 0 || *nbr > 255)
		return (NULL);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (str + i);
}

// check if line is valid C 255, 255, 255
static int	pars_line(char *str, int *color)
{
	int	tab[3];

	if (!str || !*str)
		return (0);
	str = pars_int(str, &tab[0]);
	if (!str || !*str)
		return (0);
	else if (*str == ',')
		str++;
	str = pars_int(str, &tab[1]);
	if (!str || !*str)
		return (0);
	else if (*str == ',')
		str++;
	str = pars_int(str, &tab[2]);
	if (!str || *str)
		return (0);
	*color = ((tab[0] << 16) | (tab[1] << 8) | tab[2]);
	return (1);
}

// check if line start with F or C
int	pars_rgb(char *str, t_data *data)
{
	static int		f = 0;
	static int		c = 0;

	if (str[0] == 'F' && !f)
	{
		f = 1;
		return (pars_line(str + 1, &data->floor));
	}
	else if (str[0] == 'C' && !c)
	{
		c = 1;
		return (pars_line(str + 1, &data->sky));
	}
	else
		return (0);
}
