/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:28:59 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/09 19:51:48 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

t_map	*first_line(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->prev != NULL)
		map = map->prev;
	return (map);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	map = first_line(map);
	while (map->next != NULL)
	{
		map = map->next;
		free(map->prev);
	}
	free(map);
}

static int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' '
			|| str[i] == '1' || str[i] == '0'
			|| str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W'))
		i++;
	if (str[i] && str[i] != '\n')
		return (0);
	return (1);
}

t_map	*new_mapline(char *str, t_map *prev)
{
	t_map	*map;

	if (!str || !check_line(str))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->str = str;
	map->prev = prev;
	if (prev)
	{
		prev->next = map;
		map->pos = prev->pos + 1;
	}
	else
	{
		prev = NULL;
		map->pos = 0;
	}
	map->next = NULL;
	return (map);
}
