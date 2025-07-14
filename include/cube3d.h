/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoireau <adoireau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:00:54 by adoireau          #+#    #+#             */
/*   Updated: 2025/07/14 23:30:35 by adoireau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../libft/include/libft.h"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		pixel_bits;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_map
{
	int				pos;
	char			*str;
	struct s_map	*prev;
	struct s_map	*next;
}	t_map;

typedef struct s_data
{
	t_map			*map;
	t_img			*tex[4];
	int				sky[3];
	int				floor[3];
	float			x;
	float			y;
	float			r;
}	t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_data		*data;
}	t_mlx;

void	error_message(char *str, int i);

t_map	*first_line(t_map *map);
void	free_map(t_map *map);
t_map	*new_mapline(char *str, t_map *prev);
int		pars_img(char *tmp, t_data *data);
int		pars_rgb(char *tmp, t_data *data);
void	parsing(char *str);

int		close_win(void);
int		make_img(void);
int		init_mlx(t_mlx *mlx);

int		key_press(int keycode, t_mlx *mlx);

t_data	*get_data(void);
void	free_data(void);
void	reset_data(void);
t_mlx	*get_mlx(void);
void	free_mlx(void);
void	reset_mlx(void);

//test
void	display_texture(int texture_num);

#endif
